class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        int ptr1 = 0, ptr2 = 0;
        while(ptr1 < len1 && ptr2 < len2){
            if(nums1[ptr1] < nums2[ptr2]){
                ptr1++;
            }else if(nums1[ptr1] > nums2[ptr2]){
                ptr2++;
            }else{
                return nums1[ptr1];
            }
        }
        return -1;
    }
};
