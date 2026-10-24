class Solution {
public:
    void print(vector<int> &vec) {
        for (int ele : vec) {
            cout << ele << " ";
        }
        cout << endl;
    }

    int tribonacci(int n) {
        if (n == 0){
            return 0;
        } else if (n == 1 || n == 2) {
            return 1;
        }
        
        vector<int> res(n + 1);
        res[0] = 0;
        res[1] = 1;
        res[2] = 1;

        for (int i = 3; i <= n; i++) {
            res[i] = res[i - 1] + res[i - 2] + res[i - 3];
        }

        print(res);
        return res[n];
    }
};

/*
0, 1, 1, 2, 4, 7, 13, 24, 44, 81, 149, 274, 504, 927, 1705, 3136, 5768, 10609, 19513, 35890, 66012, 121415$T_0$

0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 4181 6765 10946 

*/