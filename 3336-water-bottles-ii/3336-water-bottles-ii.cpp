class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drunkBottle = numBottles;
        int emptyBottle = numBottles;

        while(emptyBottle >= numExchange) {
            emptyBottle = emptyBottle - numExchange;
            drunkBottle++;
            numExchange++;
            emptyBottle++;
        }
        return drunkBottle;
    }
};