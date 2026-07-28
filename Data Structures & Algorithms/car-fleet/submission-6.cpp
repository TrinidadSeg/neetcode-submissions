class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        for (int i = 0; i < position.size(); i++) cars.push_back({target-position[i], speed[i]});
        sort(cars.begin(), cars.end());
        stack<double> arrs;
        for (pair car: cars) {
            double key = car.first * 1.0 / car.second;
            if (arrs.empty()|| arrs.top() < key) arrs.push(key);
        }
        return arrs.size();
    }
};
