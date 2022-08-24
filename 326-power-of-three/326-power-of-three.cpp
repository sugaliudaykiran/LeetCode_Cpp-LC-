class Solution {
public:
    bool isPowerOfThree(int n) {  
        while (n >= 3)  // TC -> O(log_3(N))..  SC -> O(1)..
        {
            if (n%3 != 0)
            {
                return false;
            }
            n = n/3;
        }
        return (n == 1);
    }
};

// n = 9/3 = 3, 9%3 == 0 -> 3/3 = 1, 3%3 == 0..
// n = 10/3 = 3, 10%3 != 0.. then stop.. Incase number be of pow of 3, it's remainder need to equal to 0..  