class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> timemap;

public:
    TimeMap() {
        
    }

    
    void set(string key, string value, int timestamp) {
        timemap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (timemap.find(key)==timemap.end()){
            return "";
        }
        else{
            vector<pair<int, string>>& this_key_list = timemap[key];
            int left = 0;
            int right = this_key_list.size() - 1;
            string result = "";
            while (left <= right){ //有等號是為了只有1元素也能處理
                int mid = left + (right - left) / 2;
                int mid_time = this_key_list[mid].first;
                string mid_val = this_key_list[mid].second;

                if (mid_time <= timestamp){// 情況 A: 這個時間點是在目標時間之前 (或剛好等於)
                     // 這是一個「合法」的答案，先記錄下來！
                    result = mid_val;

                    // 右邊可能還有「更晚但仍小於等於 timestamp」的紀錄
                    // 所以我們嘗試往右邊找 (讓時間更大一點)
                    left = mid + 1;
                }
                else{
                    // 情況 B: 這個時間點超過目標時間了
                    // 完全不考慮，直接往左邊找
                    right = mid - 1;
                }

            }
        return result;
        }
    }
};
