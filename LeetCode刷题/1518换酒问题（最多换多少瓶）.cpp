class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        //    // 方法一：商+余数
        //    int res = numBottles;
        //    int bottles = numBottles; // 空瓶数
        //    while (bottles >= numExchange) {
        //        res += bottles/numExchange; 
        //        bottles = bottles/numExchange + bottles%numExchange;
        //    }
        //    return res;

        // // 方法二：模拟 ，每次兑换一瓶，减去numexchange，再加上一个空瓶
        //     int res = numBottles;
        //     while (numBottles >= numExchange) {
        //         res++;
        //         numBottles -= (numExchange-1); 
        //     }
        //     return res;
            // 方法三：数学
            // 除了一开始的numBottles瓶
            // numBottles - n*(numExchange - 1) < numExchange, n的最小值为
        return numBottles >= numExchange ? numBottles + (numBottles - numExchange) / (numExchange - 1) + 1 : numBottles;
    }

};
