class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string = "";
        for (string s : strs){
            encoded_string += to_string(s.size()) + "#" + s;
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i<s.size()){
            // 從 index i 開始找
            int delimiter_pos = s.find('#', i);
            int l = stoi(s.substr(i, delimiter_pos-i));

            string str = s.substr(delimiter_pos + 1, l);
            res.push_back(str);

            i = delimiter_pos + 1 + l;


        }
        return res;
    }
};
