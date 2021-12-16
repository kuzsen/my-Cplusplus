#define PI           3.14159265358979323846
class Solution {
public:
    // 使用反正切函数atan(dy/dx)：返回值值域范围为 [-0.5Π，0.5Π][-90°,90°]，需要对 dx与 dy 进行象限讨论，从而将值域范围转化为我们希望的 [0°,360°]，同时需要注意dx=0 的边界情况
    //使用 atan2(dy, dx)：值域范围为【-Π，+Π】 [-180°,180°]，与我们期望的 [0°,360°] 相差一个固定的值Π，可进行统一转换，也可以直接使用。
    double calAngel(double x, double y) { // 反正切函数atan(dy/dx),[-0.5Π，0.5Π]
        if (x == 0 && y > 0) return 90.0; // y轴正向
        else if (x == 0 && y < 0) return 270.0; // y轴负向
        else if (x > 0 && y >= 0) return atan(y / x) * 180.0 / PI; // 第一象限和x正
        else if (x < 0 && y >= 0) { // x轴反向
            return 180.0 - atan(y / (-x)) * 180.0 / PI;
        }
        else if (x < 0) { // 第三象限 y < 0
            return 180 + atan((-y) / (-x)) * 180.0 / PI;
        }
        else if (x > 0) { // 第四象限 y < 0
            return 360.0 - atan((-y) / x) * 180.0 / PI;
        }
        return 0.0;
    }
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        // 正负角问题，假如说角度范围是150°-250°，-170°按理说被覆盖在这范围了，因为-170°等于+190°，是同一个终边角

        int  posx = location[0], posy = location[1];
        int samePoint = 0; // 记录与location点重合点的个数，最后加在结果上返回
        vector<double> angles; // 存储每个点与location连线  与  x轴正向  的夹角
        for (auto& point : points) {
            point[0] -= posx; // 相当于point[0] - posx  横坐标之差
            point[1] -= posy;
            if (point[0] == 0 && point[1] == 0) {
                samePoint++;
                continue; // 不能把相同点也加入到angles数组中
            }
            angles.emplace_back(calAngel(point[0], point[1]));
        }
        sort(angles.begin(), angles.end()); // 对极角从小到大排序
        /*
        关于为什么要加360°的解释
    比如有两个点，一个点是179°，另一个点是-179°，angle大小是5°，如果选择以179°为 起点，加上angle就是184°，范围就是179°到184°，覆盖不到-179°，可我们知道实际上-179°应该也在这个范围里的，所以我们可以让-179°加上360°，变成181°，这时候就在179°到184°的范围里了，就可以被覆盖到了
    又因为angle是小于360°的，这就保证了原来的点和它加上360°后的点不可能被同时覆盖到，也就保证了同一个点不会被重复计算两次，保证了结果的正确性
         当angles[i] = 1°, angles[j] = 359°,maxAngle = 10°,
         angles[j] - angles[i] = 358°  > 10°,则判定i，j两点组成的角度不在10度内
         但是angles[i]与angles[j]在图形中相隔为2度，是小于10度的
         这时候把angles[i]加上360度，即为361度，加到数组后面，361 - angles[j] = 361-359 = 2度，可以弥补“i，j两点组成的角度不在10度内”这个错误
         */

        int n = angles.size();
        //for (int i = 0; i < angles.size(); ++i) { // angles.size()增加，超出时间限制
        for (int i = 0; i < n; ++i) {
            angles.emplace_back(angles[i] + 360.0);
        }
        n = n << 1; // 相当于 n* 2的1次幂

        // 双指针or滑动窗口去查找angle范围内点的最大个数
        int maxNum = 0; // 维护最大个数
        int l = 0; // 左指针
        double maxAngle = (double)angle; // 最大角度范围值的类型转换
        for (int r = 0; r < n; ++r) {
            if (angles[r] - angles[l] <= maxAngle) { // 两个点的极角相减=两个点与position形成的夹角大小
                maxNum = max(maxNum, r - l + 1);
            }
            else { // 超出范围，则l指针右移直到再次在范围之内
                while (angles[r] - angles[l] > maxAngle && l < r)
                {
                    l++;
                }
            }
        }
        return maxNum + samePoint;
    }
};