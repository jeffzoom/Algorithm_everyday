// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> outall;
//         for (int i = 0; i < nums.size() - 2; i++) {
//             for (int j = i + 1; j < nums.size() - 1; j++) {
//                 for (int x = j + 1; x < nums.size(); x++) {
//                     if (nums[i] + nums[j] + nums[x] == 0) {
//                         outall.push_back(vector<int>{nums[i], nums[j], nums[x]});
//                     }
//                 }
//             }
//         }
//         // 这个不重复的三元组好难
        
//         return outall;
//     }
// };

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 排序后的三指针法 这个方法蛮清晰
        vector<vector<int>> outall;
        sort(nums.begin(), nums.end());
        vector<int> recodeiilr;

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > 0) return outall;
            // while ((nums[i] == nums[i + 1]) && (i < nums.size() - 1)) i++;
            // 错误去重a方法，将会漏掉-1,-1,2 这种情况
            /*
            if (nums[i] == nums[i + 1]) continue; 
            //现在和未来的一样，直接到未来 但是现在的-1,-1,2就漏掉了
            */
            // 正确去重a方法 这样不会漏掉-1,-1,2 真聪明
            if (i > 0 && nums[i] == nums[i - 1]) continue;//现在和过去的一样，直接到未来
            
            int left = i + 1, right = nums.size() - 1;

            while (left < right) {
                if (nums[i] + nums[left] + nums[right] < 0) left++;
                else if (nums[i] + nums[left] + nums[right] > 0) right--;
                else {
                    outall.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    // if (nums[i] == nums[i + 1]) { //记录重复的位置
                    // //这样也不行，不能创建一个recodeiilr，记录重复位置
                    // }
                    while (left < right && nums[left] == nums[left + 1] ) left++; // 去重
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                }
                
            }
            
        }
        
        return outall;
    }
};