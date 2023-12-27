// class Solution { //通过了，但是太暴力了，不好不好
// public:
//     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> outest;
//         vector<int> record1(1001, 0);
//         vector<int> record2(1001, 0);
//         for (int i = 0; i < nums1.size(); i++) {
//             record1[nums1[i]]++;
//         }
//         for (int i = 0; i < nums2.size(); i++) {
//             record2[nums2[i]]++;
//         }
//         for (int i = 0; i < 1001; i++) {
//             if (record1[i] > 0 && record2[i] > 0) {
//                 outest.push_back(i);
//             }
//         }
//         return outest;
//     }
// };

// 改进版
// class Solution { //通过了，但是太暴力了，不好不好
// public:
//     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

//         vector<int> record1(1001, 0);
//         for (int i = 0; i < nums1.size(); i++) {
//             record1[nums1[i]]++;
//         }
//         unordered_set<int> un_outest;
//         for (int &nu : nums2) { //范围for，循环nums2中的每一个元素，加不加&都行
//             if (record1[nu] > 0) {
//                 un_outest.insert(nu);
//             }
//         }
//         return vector<int> (un_outest.begin(), un_outest.end()); //学到了
//     }
// };


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set; // 存放结果，之所以用set是为了给结果集去重
        unordered_set<int> nums_set(nums1.begin(), nums1.end()); // 把nums1存到
        for (int num : nums2) {
            //若find没有找到，则find返回尾后迭代器.end()
            if (nums_set.find(num) != nums_set.end()) { 
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};
