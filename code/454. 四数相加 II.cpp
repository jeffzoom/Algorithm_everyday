// 不能暴力，超出时间限制
// class Solution {
// public:
//     int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
//         int outnum = 0, tempsum = 0;
//         int i1, i2, i3, i4;
//         for(i1 = 0; i1 < nums1.size(); i1++) {
//             for(i2 = 0; i2 < nums1.size(); i2++) {
//                 for(i3 = 0; i3 < nums1.size(); i3++) {
//                     for(i4 = 0; i4 < nums1.size(); i4++) {
//                         if (nums1[i1] + nums2[i2] + nums3[i3] + nums4[i4] == 0) outnum++;
//                     }
//                 }
//             }
//         }
//         return outnum;
//     }
// };

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int outnum = 0, tempsum = 0;
        // int i1, i2, i3, i4;
        unordered_map<int, int> num_12;
        for (int i1 : nums1){
            for (int i2 : nums2) {
                num_12[i1 + i2]++;
            }
        }
        // nums1 + nums2 + nums3 + nums4 = 0
        // nums1 + nums2 = 0 - (nums3 + nums4)
        for (int i3 : nums3){
            for (int i4 : nums4) {
                if (num_12.find(0 - (i3 + i4)) != num_12.end()) {
                    outnum += num_12[0 - (i3 + i4)];
                }
            }
        }
        return outnum;

    }
};