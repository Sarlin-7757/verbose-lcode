#include<string>

using std::string;

class Solution {
public:

    bool isAlnum(char c) {
        if (c >= '0' && c <= '9') {
            return true;
        }
        
        if (c >= 'A' && c <= 'Z') {
            return true;
        }
        if (c >= 'a' && c <= 'z') {
            return true;
        }
        return false;
    }   
    
    bool isPalindrome(string s) {
        int left = 0; 
        int right = s.size() - 1;

        while(left < right){
            // skip the alphanumeric from left 
            while(left < right && !isAlnum(s[left])) {
                left++;
            }
           // skip the alphanumeric from right 
            while(left < right && !isAlnum(s[right])) {
                right--;
            }
            
            if(tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }
        return true;
    }
};

