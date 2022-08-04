class Solution {
public:
    // extension * p = reflection * q..
    int mirrorReflection(int p, int q) {
        int extension = q, ref = p;
        
        while (p % 2 == 0 && q % 2 == 0)
        {
            p/= 2;
            q/=2;
        }
        if (p % 2 == 0 && q % 2 != 0)
        {
            return 2;
        }
        else if (p % 2 != 0 && q % 2 != 0)
        {
            return 1;
        }
        else if (p % 2 != 0 && q % 2 == 0)
        {
            return 0;
        }
        return -1;
    }
};