#include<iostream>
#include<string>
#include<unordered_map>

int characterReplacement(std::string s, int k) {
    std::unordered_map<char , int>counter(26);

    int start= 0;
    int maxlenStr = 0; 
    int repeatCharCount = 0; 

    for (int end = 0 ; end< s.size(); end++){
        counter[s[end] - 'A']++;
        repeatCharCount = std::max(repeatCharCount , counter[s[end]-'A']);

        while (end - start +1 - repeatCharCount > k){

            counter[s[start]- 'A']--;
            start++;
        }

        maxlenStr = std::max(maxlenStr, end-start+1);

    }
    return maxlenStr;
}