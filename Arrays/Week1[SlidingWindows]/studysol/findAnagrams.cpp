#include<vector>
#include<string>
#include<iostream>


bool allZeroes(std::vector<int>&counter){
    for(int &i :counter){
        if(i != 0){
            return false;
        }
    }
    return true;
}


std::vector<int> findAnagrams(std::string txt, std::string pat) {
    std::vector<int>counter(26);

    // retreiving the characters from the pattern for the map (counter)
    for (int i=0 ; i < pat.length(); i++){
        char ch = pat[i];
        counter[ch - 'a']++;
    }

    int start = 0; 
    std::vector<int>result;

    for (int end = 0 ; end< txt.length(); end++){
        counter[txt[end]-'a']--;
        if (end - start +1== pat.length()){
            if(allZeroes(counter)){
              result.push_back(start);
            }
            counter[txt[start]-'a']++;
            start++;
        }
    }
    return result;
}
