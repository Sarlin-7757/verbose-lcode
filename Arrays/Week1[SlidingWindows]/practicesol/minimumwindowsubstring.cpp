#include<string>
#include<limits.h>
#include<iostream>
#include<unordered_map>


std::string minWindow(std::string s, std::string t) {
    int n = s.length();

    if (t.length() > n){
        return "";
    }
    
    std::unordered_map<char ,int>mp;

    for(char &ch: t){
        mp[ch]++;
    }

    int start = 0; 
    int end = 0;
    int requiredCount = t.length();

    int minWindowSize = INT_MAX;

    int start_i = 0;


    while(end < n){
        char ch = s[end];

        if (mp[s[end]]>0){
            requiredCount--;
        }
        mp[s[end]]--;

        while(requiredCount == 0){
            int windowSize = end -start+1;

            if(minWindowSize > windowSize){
                minWindowSize = windowSize;
                start_i = start;
            }

            mp[s[start]]++;

            if(mp[s[start]] > 0){
                requiredCount++;
            }
            start++;
        }
        end++;

    }
    return minWindowSize == INT_MAX ? "": s.substr(start_i , minWindowSize);
}




int main(){
    std::string s =  "ADOBECODEBANC";
    std::string t = "ABC";

    std::string ans = minWindow(s, t);

    std::cout << ans ;

}