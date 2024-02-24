#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
#define MAX_N 100000
    int find(const int* groups, int index){
        while(index != groups[index])index = groups[index];
        return index;
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        static int groups[MAX_N];
        static vector<int> temp;

        for (int i = 0; i < n; ++i) groups[i] = i;
        groups[firstPerson] = 0;

        sort(meetings.begin(), meetings.end(), [](const auto& l, const auto& r) {
            return l[2] < r[2];
        });

        const int SIZE = meetings.size();
        int i = 0;
        while (i < SIZE) {
            int currentTime = meetings[i][2];
            temp.clear();
            while (i < SIZE && meetings[i][2] == currentTime) {
                int g1 = find(groups, meetings[i][0]);
                int g2 = find(groups, meetings[i][1]);
                groups[max(g1, g2)] = min(g1, g2);
                temp.push_back(meetings[i][0]);
                temp.push_back(meetings[i][1]);
                ++i;
            }
            for (int j = 0; j < temp.size(); ++j) {
                if (find(groups, temp[j]) != 0) {
                    groups[temp[j]] = temp[j];
                }
            }
        }

        vector<int> result;
        for (int j = 0; j < n; ++j) {
            if (find(groups, j) == 0)result.push_back(j);
        }

        return result;
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
