#define PI           3.14159265358979323846
class Solution {
public:
    // ʹ�÷����к���atan(dy/dx)������ֵֵ��ΧΪ [-0.5����0.5��][-90��,90��]����Ҫ�� dx�� dy �����������ۣ��Ӷ���ֵ��Χת��Ϊ����ϣ���� [0��,360��]��ͬʱ��Ҫע��dx=0 �ı߽����
    //ʹ�� atan2(dy, dx)��ֵ��ΧΪ��-����+���� [-180��,180��]�������������� [0��,360��] ���һ���̶���ֵ�����ɽ���ͳһת����Ҳ����ֱ��ʹ�á�
    double calAngel(double x, double y) { // �����к���atan(dy/dx),[-0.5����0.5��]
        if (x == 0 && y > 0) return 90.0; // y������
        else if (x == 0 && y < 0) return 270.0; // y�Ḻ��
        else if (x > 0 && y >= 0) return atan(y / x) * 180.0 / PI; // ��һ���޺�x��
        else if (x < 0 && y >= 0) { // x�ᷴ��
            return 180.0 - atan(y / (-x)) * 180.0 / PI;
        }
        else if (x < 0) { // �������� y < 0
            return 180 + atan((-y) / (-x)) * 180.0 / PI;
        }
        else if (x > 0) { // �������� y < 0
            return 360.0 - atan((-y) / x) * 180.0 / PI;
        }
        return 0.0;
    }
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        // ���������⣬����˵�Ƕȷ�Χ��150��-250�㣬-170�㰴��˵���������ⷶΧ�ˣ���Ϊ-170�����+190�㣬��ͬһ���ձ߽�

        int  posx = location[0], posy = location[1];
        int samePoint = 0; // ��¼��location���غϵ�ĸ����������ڽ���Ϸ���
        vector<double> angles; // �洢ÿ������location����  ��  x������  �ļн�
        for (auto& point : points) {
            point[0] -= posx; // �൱��point[0] - posx  ������֮��
            point[1] -= posy;
            if (point[0] == 0 && point[1] == 0) {
                samePoint++;
                continue; // ���ܰ���ͬ��Ҳ���뵽angles������
            }
            angles.emplace_back(calAngel(point[0], point[1]));
        }
        sort(angles.begin(), angles.end()); // �Լ��Ǵ�С��������
        /*
        ����ΪʲôҪ��360��Ľ���
    �����������㣬һ������179�㣬��һ������-179�㣬angle��С��5�㣬���ѡ����179��Ϊ ��㣬����angle����184�㣬��Χ����179�㵽184�㣬���ǲ���-179�㣬������֪��ʵ����-179��Ӧ��Ҳ�������Χ��ģ��������ǿ�����-179�����360�㣬���181�㣬��ʱ�����179�㵽184��ķ�Χ���ˣ��Ϳ��Ա����ǵ���
    ����Ϊangle��С��360��ģ���ͱ�֤��ԭ���ĵ��������360���ĵ㲻���ܱ�ͬʱ���ǵ���Ҳ�ͱ�֤��ͬһ���㲻�ᱻ�ظ��������Σ���֤�˽������ȷ��
         ��angles[i] = 1��, angles[j] = 359��,maxAngle = 10��,
         angles[j] - angles[i] = 358��  > 10��,���ж�i��j������ɵĽǶȲ���10����
         ����angles[i]��angles[j]��ͼ�������Ϊ2�ȣ���С��10�ȵ�
         ��ʱ���angles[i]����360�ȣ���Ϊ361�ȣ��ӵ�������棬361 - angles[j] = 361-359 = 2�ȣ������ֲ���i��j������ɵĽǶȲ���10���ڡ��������
         */

        int n = angles.size();
        //for (int i = 0; i < angles.size(); ++i) { // angles.size()���ӣ�����ʱ������
        for (int i = 0; i < n; ++i) {
            angles.emplace_back(angles[i] + 360.0);
        }
        n = n << 1; // �൱�� n* 2��1����

        // ˫ָ��or��������ȥ����angle��Χ�ڵ��������
        int maxNum = 0; // ά��������
        int l = 0; // ��ָ��
        double maxAngle = (double)angle; // ���Ƕȷ�Χֵ������ת��
        for (int r = 0; r < n; ++r) {
            if (angles[r] - angles[l] <= maxAngle) { // ������ļ������=��������position�γɵļнǴ�С
                maxNum = max(maxNum, r - l + 1);
            }
            else { // ������Χ����lָ������ֱ���ٴ��ڷ�Χ֮��
                while (angles[r] - angles[l] > maxAngle && l < r)
                {
                    l++;
                }
            }
        }
        return maxNum + samePoint;
    }
};