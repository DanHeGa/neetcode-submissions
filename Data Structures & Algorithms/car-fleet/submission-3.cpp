class Solution {
public:
    template<typename T>
    void debugVec(vector<T> vec) {
        for (T ele : vec) {
            cout << ele << " ";
        }
        cout << endl;
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (n == 0) return 0;
        //use of monotonic stack
        stack<double> stk;
        vector<int> idx(n);

        iota(idx.begin(), idx.end(), 0); //like range((len(position))) in python
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return position[i] > position[j]; //descending order
        });

        debugVec(idx);

        for(int ele : idx) {
            double time = static_cast<double>(target - position[ele]) / speed[ele];

            if (stk.empty() || time > stk.top()) {
                //if time > stk.top, a new fleet is created
                stk.push(time);
            } 
        }

        return stk.size();

    }
};
