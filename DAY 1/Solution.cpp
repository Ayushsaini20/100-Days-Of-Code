class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int,int>_map;
       for(int i=0;i <nums.size(); ++i){
           int num= nums[i];
           int complement =target - num;
           auto it = _map.find(complement);
           if(it !=_map.end()){
               return {it->second,i};
               }
               _map[num] =i;
           }
           return {};
       }

    
};
