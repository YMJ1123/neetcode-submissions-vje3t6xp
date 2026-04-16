class CountSquares {
private:
    // 記錄所有的點，用來當作尋找對角線的候選人
    vector<pair<int, int>> pointsList;
    
    // 2D 陣列點名冊，記錄某個座標 (x, y) 出現過幾次
    // 因為題目保證座標在 0~1000 之間，直接開 1001x1001 是最快的
    vector<vector<int>> ptsCount;

public:
    CountSquares() {
        // 初始化點名冊，全部填入 0
        ptsCount = vector<vector<int>>(1001, vector<int>(1001, 0));
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        
        // 把點加進清單裡
        pointsList.push_back({x, y});
        // 點名冊上的數量 + 1
        ptsCount[x][y]++;
    }
    
    int count(vector<int> point) {
        int px = point[0];
        int py = point[1];
        int totalSquares = 0;
        
        // 遍歷我們加過的所有點，把每個點都當作對角線的 P3 試試看
        for (auto& p3 : pointsList) {
            int x = p3.first;
            int y = p3.second;
            
            // 條件 1：不能是自己，且 X 距離等於 Y 距離 (保證是對角線)
            if (abs(px - x) != 0 && abs(px - x) == abs(py - y)) {
                
                // 條件 2：去點名冊查另外兩個角 (px, y) 和 (x, py) 存不存在
                // 能組成的正方形數量，就是這兩個角出現次數的「乘積」
                totalSquares += ptsCount[px][y] * ptsCount[x][py];
            }
        }
        
        return totalSquares;
    }
};