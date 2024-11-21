#include<iostream>
#include<unordered_map>
#include<string>



int countGoodSubstrings(std::string s) {
    int start = 0; 
    int end =0 ; 
    int count = 0; 
    int n = s.length();

    std::unordered_map<char , int > mp;

    while (end < n){
        mp[s[end]]++;
        if (end -start +1 < 3 ){
            end++;
        }
        else {
            if (mp.size() == 3){
                count++;
            }
            mp[s[start]]--;
            if(mp[s[start]] == 0){
                mp.erase(s[start]);
            }
            start++;
            end++;
        }
    }
    return count;
}