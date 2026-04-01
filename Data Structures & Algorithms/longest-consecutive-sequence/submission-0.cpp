class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_set<int> hash_set;
        int max_length = 1;
        for (int n : nums){
            hash_set.insert(n);
        }
        for (const auto& elem : hash_set) {
            auto it = hash_set.find(elem - 1);
            if (it != hash_set.end()){
                continue;
            }
            else{
                int current_length = 1;
                int i = elem + 1;
                while (hash_set.find(i) != hash_set.end()){
                    current_length++;
                    i++;
                }
                max_length = max(max_length, current_length);
            }
        }
        return max_length;
    }
};
