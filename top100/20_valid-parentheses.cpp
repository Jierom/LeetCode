
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