class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> info;
        for (int i = 0; i < position.size(); i++) { 
            info.push_back({target-position[i], speed[i]});
        }
        sort(info.begin(), info.end());
        for (pair p: info) cout<<p.first<<" speed " << p.second<<endl;
        stack<double> st;
        for (int i = 0; i < info.size(); i++) {
            double arrTime = (info[i].first)/(1.0 * info[i].second);
            cout << arrTime<< endl;
            if (st.empty()) st.push(arrTime);
            else if (st.top() < arrTime) st.push(arrTime);
        }
        return st.size();
    }
};
