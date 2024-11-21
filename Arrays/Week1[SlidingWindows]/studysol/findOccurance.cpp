#include<string>
#include<vector>
#include<iostream>

bool allZeroes(std::vector<int>&counter){
    for(int &i : counter){
        if (i != 0){
            return false;
        }
        return true;
    }
}


int findNumberofOccuranceAnagrams(std::string text , std::string pat){

    std::vector<int>counter(26 , 0);

    for (int i = 0; i < pat.length() ; i++){
        char ch = pat[i];
        counter[ch-'a']++;
    }

    int start=0;
    int result=0;    

    for (int end = 0 ; end < text.length(); end++){
        counter[text[end]- 'a']--;

        if (end - start +1 == pat.length()){
            if(allZeroes(counter)){
                result++;
            }
            counter[text[start]- 'a']++;
            start++;
        }
    }
    return result;
}