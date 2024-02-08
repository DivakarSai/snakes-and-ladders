#include <random>
class Dice{
    public:
        int num_dice;
        Dice(int num=1){
            num_dice = num;
        }
        int roll(){
            int ans=0;
            for(int i = 0; i < num_dice; i++){
                ans += rand() % 6 + 1;
            }
            return ans;
        }

};