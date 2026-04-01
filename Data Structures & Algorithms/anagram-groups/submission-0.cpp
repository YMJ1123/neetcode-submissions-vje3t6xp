class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash_map;
        for (string str : strs){
            int charCounts[26] = {0};
            for (int i = 0; i < str.length(); i++) {
                charCounts[str[i] - 'a']++; 
            }
            string key;
            for (int j = 0; j < 26; j++){
                key.push_back('|');
                key += to_string(charCounts[j]);

            }
            hash_map[key].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto& kv : hash_map) {     // auto: 自動偵測資料型別，這裡是pair: (key, value)
            ans.push_back(move(kv.second)); //把 value 的群組轉存到答案
        }
        return ans;
    }
};
