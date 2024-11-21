#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char>st; 
        for(int ch = 0 ; ch < s.size(); ch++){
            st.push(s[ch]);
        }
        for(int ch = 0; ch < s.size(); ch++){
            s[ch] = st.top();
            st.pop();
        }
    }  
};
