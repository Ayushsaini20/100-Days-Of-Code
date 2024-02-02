class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<string>str;
        vector<int> ans;
        for(int i = 1; i <10; i++){
            string tmp = to_string(i);
            for(int j = i+1; j< 10; j++){
                tmp = tmp + to_string(j);
                str.push_back(tmp);
                int num = stoi(tmp);
                if(num >= low && num <= high) ans.push_back(num); 
            }
        }
        sort(begin(ans),end(ans));
        return ans;
    }
};
