//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main() {
//    int tankNum, life, power, base; // 坦克数量， 碉堡生命值， 碉堡每次可以炸多少量坦克， 碉堡数量
//    cin >> tankNum >> life >> power >> base;
//    vector<int> lifes(base, life); // 碉堡生命值数组
//    int round = 0; // 回合数
//    // 示例
//    // 10, 6, 8, 2
//    // 2
//
//    int index = 0; // 指向当前剩余第一座碉堡
//
//    // 坦克尽量集中火力打剩余生命最少的碉堡，每回合炸毁尽量多的碉堡，否则碉堡反过来就会炸毁坦克
//    while (tankNum > 0 && index < base) { // 还有坦克可以攻击 && 还剩下碉堡
//        round++;
//
//        // 坦克进攻碉堡
//        int curFire = tankNum; // 本回合的火力
//        while (curFire > 0 && index < base) {
//            if (curFire >= lifes[index]) { // 当前火力大于当前指向碉堡的剩余生命值
//                curFire -= lifes[index];
//                lifes[index] = 0; // 消灭index当前指向的碉堡，将其生命值置为0
//                index++; // 指向下一个碉堡
//            }
//            else {
//                lifes[index] -= curFire;
//                curFire = 0;
//            }
//        }
//        // 碉堡进攻坦克
//        tankNum -= (base - index) * power; 
//    }
//    if (lifes[base - 1] > 0) { // 最后一座碉堡的生命值仍然大于0，说明坦克最终进攻失败了
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