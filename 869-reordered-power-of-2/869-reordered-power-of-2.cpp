class Solution {
public:
    bool reorderedPowerOf2(int N) {
        long c = counter(N);
        for (int i = 0; i < 32; i++)
            if (counter(1 << i) == c) return true;
        return false;
    }

    long counter(int N) {
        long res = 0;
        for (; N; N /= 10) res += pow(10, N % 10);
        return res;
    }
};

// counter will counter the number of digits 9876543210 in the given number.
// Then I just compare counter(N) with all counter(power of 2).
// 1 <= N <= 10^9, so up to 8 same digits.
// If N > 10^9, we can use a hash map.

    