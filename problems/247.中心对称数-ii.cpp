class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        // n=0: "" 假设为A
        // n=1: 0,1,8 假设为B
        // n=2: 1A1,6A9,8A8,9A6(如果n小于所求长度，还应该包括"0A0")
        // n=3: 1B1,6B9,8B8,9B6
        // f(n)=向f(n-2)两边加上f(2)

        vector<string> x;
        int i;
        if (n % 2 == 0) {
            x = vector<string>{""};
            i = 2;
        } else {
            x = vector<string>{"0", "1", "8"};
            i = 3;
        }

        for (; i <= n; i += 2) {
            vector<string> y;
            for (int j = 0; j < x.size(); ++j) {
                y.push_back("1" + x[j] + "1");
                y.push_back("6" + x[j] + "9");
                y.push_back("8" + x[j] + "8");
                y.push_back("9" + x[j] + "6");
                if (i < n) {
                    y.push_back("0" + x[j] + "0");
                }
            }
            x = y;
        }
        return x;
    }
};