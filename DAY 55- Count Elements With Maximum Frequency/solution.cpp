class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto &num : nums){
            mp[num]++;
        }
        int count = 0;
        int max_Freq = INT_MIN;
        for(auto &m : mp){
            if(m.second > max_Freq)
                max_Freq = m.second; 
        }

        for(auto &m : mp){
            if(m.second == max_Freq)
                count += max_Freq;
        }
        return count;

    }
};
