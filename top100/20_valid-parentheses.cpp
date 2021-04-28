/*** 
 * @Author: gjwu
 * @Date: 2021-04-27 13:31:36
 * @Description: Easy - 有效的括号
 * @Ref: https://leetcode-cn.com/problems/valid-parentheses/
 */

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i=0; i<s.size(); i++) {
            char c = s[i];
            if (c=='(' || c=='[' || c=='{') {
                st.push(c);
            }
            else if (c==')' || c==']' || c=='}') {
                if (st.empty()) {
                    return false;
                }
                char t = st.top();
                st.pop();
                if (t=='(' && c==')') {
                    continue;
                }
                else if (t=='[' && c==']') {
                    continue;
                }
                else if (t=='{' && c=='}') {
                    continue;
                }
                else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};