
class Solution {
public:
    using info=pair<long long, int>;// (ending time, room number)
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<int> count(n, 0);
        vector<int> freeR(n);
        iota(freeR.begin(), freeR.end(), 0);
        priority_queue<int, vector<int>, greater<int>> freeRoom(freeR.begin(), freeR.end());
        priority_queue<info, vector<info>, greater<info>> used;

        for (auto& meet: meetings){
            int room;
            while (!used.empty() && used.top().first<=meet[0]){
                room=used.top().second;
                freeRoom.push(room);
                used.pop();
            }
            long long start, m_time=meet[1]-meet[0];
            if (freeRoom.empty()){
                tie(start, room)=used.top();
                used.pop();
            }
            else{
                room=freeRoom.top();
                start=meet[0];
                freeRoom.pop();
            }
            count[room]++;
            used.push({start+m_time, room});
        }
        int idx=max_element(count.begin(), count.end())-count.begin();

        return idx;
    }
};
