class Solution {
public:
    double iterativePow(double x, long long n) {
        double ans = 1.0;
        double base = x;
        while(n > 0) {
            if (n & 1) {
                ans *= base;
            }

            base *= base;
            n >>= 1; //move n for further analysis
        }

        return ans;
    }

    double myPow(double x, int n) {
        long long N = n;
        return (N > 0) ? iterativePow(x, N) : 1.0 / iterativePow(x, -N);    
    }
};
