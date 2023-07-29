class Solution {
public:
    // Function to count the number of set bits (means 1) in a number
    int setBits(long long n) {
        int c = 0;
        while (n > 0) {
            c += n % 2;
            n /= 2;
        }
        return c;
    }

    int makeTheIntegerZero(int num1, int num2) {
        if (num1 < num2)
            return -1;

        for (int k = 0; k < 61; ++k) {
            long long x = (long long)num1 - (long long)(num2) * k;
            
            /* Check if the k <= num1 - num2*k && setBits in `num1 - num2*k` <= k
             return answer as k; */
            if (k <= x && setBits(x) <= k ) {
                return k;
            }
        }

        return -1;
    }
};
