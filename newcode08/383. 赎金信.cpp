class Solution { // 通过了
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> allmagazine; // 错误1：得是char，不能是string，因为magazine[i]的返回值是char，就是'a'，'b'这种，并不是"a"，"b"这种
        for (int i = 0; i < magazine.size(); i++) {
            allmagazine[magazine[i]]++;
        }
        for (int i = 0; i < ransomNote.size(); i++) {
            allmagazine[ransomNote[i]]--;
            if (allmagazine[ransomNote[i]] < 0) {
                return false;
            }
        }
        return true;
    }
};

注意：magazine 中的每个字符只能在 ransomNote 中使用一次。
class Solution { // 通过了
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> recode_az(26, 0);
        for (int i = 0; i < magazine.size(); i++) {
            // 为什么recode_az[magazine[i] - "a"]++;会报错呢
            recode_az[magazine[i] - 'a']++;
        }
        for (int i = 0; i < ransomNote.size(); i++) {
            recode_az[ransomNote[i] - 'a']--;
            if (recode_az[ransomNote[i] - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};