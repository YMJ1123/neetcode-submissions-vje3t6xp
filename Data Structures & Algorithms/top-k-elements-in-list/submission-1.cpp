class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n_count[2001] = {0};
        for (int i : nums){
            n_count[i + 1000]++;
        }
        vector<pair<int, int>> vec;
        for (int j=0; j<2001; j++){
            vec.push_back({n_count[j], j - 1000});

        }
        nth_element(vec.begin(), vec.begin() + k - 1, vec.end(),    
        [](const auto& a, const auto& b) {        
            return a.first > b.first; // 降冪：大的在前    
        });
        vector<int> ans;
        for (int n=0; n<k; n++){
            ans.push_back(vec[n].second);
        }
        return ans;
    }
};
