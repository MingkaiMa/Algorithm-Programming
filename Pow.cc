class Solution {
public:
    double core(double x, int n)
    {
        if(n == 1) return x;
        if(n == 0) return 1;

        double v = core(x, n / 2);

        if(n % 2 == 0)
            return v * v;
        else
            return v * v * x;

    }
    double myPow(double x, int n) {
        if(n < 0)
            return 1 / core(x, -n);
        else
            return core(x, n);
    }
};