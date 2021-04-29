/*** 
 * @Author: gjwu
 * @Date: 2021-04-29 16:37:31
 * @Description: Medium - 电话号码的字母组合
 * @Ref: https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:

    map<char, string> table {
        {'0',""}, {'1',"*"}, {'2',"abc"},
        {'3',"def"}, {'4',"ghi"}, {'5',"jkl"},
        {'6',"mno"}, {'7',"pqrs"}, {'8',"tuv"},
        {'9',"wxyz"}
    };


    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.size() == 0) {
            return res;
        }
        dfs(res, "", digits, 0);
        return res;
    }

    void dfs(vector<string>& res, string str, string digits, int k) {
        if (str.size() == digits.size()) {
            res.push_back(str);
            return;
        }

        string tmp = table[digits[k]];
        for (char w : tmp) {
            str += w;
            dfs(res, str, digits, k+1);
            str.pop_back();
        }
        return;
    }
};