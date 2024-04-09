class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n=tickets.size();
        int x=tickets[k];
        int time=0;
        for(int i=0; i<n; i++){
            int buy=(i>k)?x-1:x;
            time+=min(buy, tickets[i]);
        }
        return time;           
    }
};
