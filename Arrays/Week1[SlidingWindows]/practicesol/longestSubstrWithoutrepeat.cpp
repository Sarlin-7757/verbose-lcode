Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.



int lengthOfLongestSubstring(string s) {
    // can also use unordered_map instead of map 
       map<char , bool >charMap;

       int larStr = 0; 

       int start = 0; 

       for (int end = 0 ; end < s.length(); end++){
           char ch= s[end];

           if(!charMap[ch]){
               charMap[ch] = true;
               larStr = max(larStr , end-start+1);
           }
           else{
               while(charMap[ch]){
                   charMap[s[start]] = false;
                   start++;
               }
               charMap[ch]= true;
           }
       }
       return larStr;
    }
