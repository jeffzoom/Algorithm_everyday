/*
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = nums.size() - 1, xj = 0;
        while (i <= j) {
            if (nums[i] == val) {
                //xj++;
                nums[i] = nums[j];
                //j -= xj; // xj是数组末尾移到最前面减少的元素
                j--;
            }
            else if (nums[i] != val) {
                i++;
            }
        }
        return ++j;
    }
};
*/
//不改变相对位置的话
/*双指针法（快慢指针法）： 通过一个快指针和慢指针在一个for循环下完成两个for循环的工作。

实现思路：定义两个int值作为“指针”指向原数组开头，以fast快指针为基准开始遍历nums数组，用slow指针记录新数组（保留值构成的数组），即索引保留值

slow如何实现记录新数组——索引保留值
当fast快指针遍历数组，索引值!=val值，即保留值时，slow++（新数组长度+1）；
当fast快指针遍历数组，索引值==val值，即删除值时，slow不变（新数组长度不变）；

fast快指针：寻找新数组里所需要的元素; 遍历原数组，得到索引值；
slow慢指针：需要更新的位置; 根据索引值是否val值，删除值/保留值
当fast快指针遍历数组结束，得到的slow值即新数组长度
*/
//快慢指针法
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (nums[fastIndex] != val) {
                nums[slowIndex] = nums[fastIndex];
                slowIndex++; //发现快指针指向保留值，slowIndex可+1
                // nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;   
    }
};

