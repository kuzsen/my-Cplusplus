//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main() {
//    int tankNum, life, power, base; // ̹�������� �ﱤ����ֵ�� �ﱤÿ�ο���ը������̹�ˣ� �ﱤ����
//    cin >> tankNum >> life >> power >> base;
//    vector<int> lifes(base, life); // �ﱤ����ֵ����
//    int round = 0; // �غ���
//    // ʾ��
//    // 10, 6, 8, 2
//    // 2
//
//    int index = 0; // ָ��ǰʣ���һ���ﱤ
//
//    // ̹�˾������л�����ʣ���������ٵĵﱤ��ÿ�غ�ը�پ�����ĵﱤ������ﱤ�������ͻ�ը��̹��
//    while (tankNum > 0 && index < base) { // ����̹�˿��Թ��� && ��ʣ�µﱤ
//        round++;
//
//        // ̹�˽����ﱤ
//        int curFire = tankNum; // ���غϵĻ���
//        while (curFire > 0 && index < base) {
//            if (curFire >= lifes[index]) { // ��ǰ�������ڵ�ǰָ��ﱤ��ʣ������ֵ
//                curFire -= lifes[index];
//                lifes[index] = 0; // ����index��ǰָ��ĵﱤ����������ֵ��Ϊ0
//                index++; // ָ����һ���ﱤ
//            }
//            else {
//                lifes[index] -= curFire;
//                curFire = 0;
//            }
//        }
//        // �ﱤ����̹��
//        tankNum -= (base - index) * power; 
//    }
//    if (lifes[base - 1] > 0) { // ���һ���ﱤ������ֵ��Ȼ����0��˵��̹�����ս���ʧ����
//        round = -1;
//    }
//    cout << round << endl;
//    system("pause");
//    system("cls");
//    return 0;
//}

#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    system("pause");
    system("cls");
    return 0;
}