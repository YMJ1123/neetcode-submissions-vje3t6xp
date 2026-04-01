class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        //target = position[i] + speed[i] * t
        vector<pair<int, int>> cars;
        int len = speed.size();
        cars.reserve(len); // 預留空間，避免多次重新分配
        for (int i = 0; i < len; ++i){
            cars.emplace_back(position[i], speed[i]);        
        }
        sort(cars.begin(), cars.end(), [](const auto& a, const auto& b) {
            return a.first > b.first; // 第一個元素大者在前
        });
        stack<double> require_times; //double 以處理time四捨五入問題
        for (pair<int, int> car: cars){
            double time2target = ((double)target - (double)car.first) / (double)car.second;
            if (require_times.empty() || time2target>require_times.top()){
                require_times.push(time2target);
            }
        }
        return require_times.size();
    }
};
