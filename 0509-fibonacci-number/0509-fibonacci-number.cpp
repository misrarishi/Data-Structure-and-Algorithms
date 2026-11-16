class Solution {
private:
    int solve(int n, vector<int>& f) {
        if (n <= 1)
            return n;
        if (f[n] != -1)
            return f[n];
        return f[n] = solve(n - 1, f) + solve(n - 2, f);
    }

public:
    int fib(int n) {
        vector<int> f(n + 1, -1);
        return solve(n, f);
    }
};