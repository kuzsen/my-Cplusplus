class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        //    // ����һ����+����
        //    int res = numBottles;
        //    int bottles = numBottles; // ��ƿ��
        //    while (bottles >= numExchange) {
        //        res += bottles/numExchange; 
        //        bottles = bottles/numExchange + bottles%numExchange;
        //    }
        //    return res;

        // // ��������ģ�� ��ÿ�ζһ�һƿ����ȥnumexchange���ټ���һ����ƿ
        //     int res = numBottles;
        //     while (numBottles >= numExchange) {
        //         res++;
        //         numBottles -= (numExchange-1); 
        //     }
        //     return res;
            // ����������ѧ
            // ����һ��ʼ��numBottlesƿ
            // numBottles - n*(numExchange - 1) < numExchange, n����СֵΪ
        return numBottles >= numExchange ? numBottles + (numBottles - numExchange) / (numExchange - 1) + 1 : numBottles;
    }

};
