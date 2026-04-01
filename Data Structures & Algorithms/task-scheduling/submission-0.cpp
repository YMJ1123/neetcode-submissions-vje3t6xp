class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // 最少時間 = ({最大頻率} - 1) × (n + 1) + {擁有最大頻率的任務種類數}
        vector<int> counts(26, 0);
        for (char task : tasks) {
            counts[task - 'A']++;
        }

        // find the most frequent one
        int max_freq = 0;
        for (int count: counts){
            max_freq = max(max_freq, count);
        }

        // find 擁有最大頻率的任務種類數
        int max_count = 0;
        for (int count: counts){
            if (count == max_freq){
                max_count++;
            }
        }

        int result = (max_freq - 1) * (n + 1) + max_count;
        int total_tasks = tasks.size();
        return max(result, total_tasks);

    }
};
