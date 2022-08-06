class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        //  Finding base condition.. that for base 5..adding up..count of poorpig.
        
        int poorpig = 0;
        while (true)
        {
            int x = (int )(minutesToTest/minutesToDie)+1;
            if (pow(x, poorpig) < buckets)
                poorpig++;
            else
                break;
        }
        return poorpig;
    }
};