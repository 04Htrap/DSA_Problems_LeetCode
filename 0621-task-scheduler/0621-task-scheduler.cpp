class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for(char i: tasks) {
            freq[i - 'A']++;
        }

        int elementNo = tasks.size();
        int cycles = elementNo / n;

        priority_queue<int> pq;
        for(int i = 0; i < 26; i++) {
            if(freq[i])
                pq.push(freq[i]);
        }
        int time = 0;
        while(!pq.empty()) {
            int cycle = n + 1;
            vector<int> remain;

            while(cycle > 0 && !pq.empty()) {
                int curr = pq.top();
                pq.pop();
                if(curr > 1) remain.push_back(curr - 1);
                time++;
                cycle--;
            }

            for(int r : remain) pq.push(r);

            if(!pq.empty()) time += cycle;
        }

        return time;
    }
};