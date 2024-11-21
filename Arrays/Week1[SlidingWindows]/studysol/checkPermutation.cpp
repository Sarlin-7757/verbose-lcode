#include<vector>
#include<string>

bool allZeroes(std::vector<int>&counter){
    for(int &i : counter){
        if(i != 0){
            return false;
        }
    }
    return true;
}


bool checkInclusion(std::string s1, std::string s2) {
    std::vector<int>counter(26);

    for (int i = 0 ; i < s1.length(); i++){
        char ch = s1[i];
        counter[ch - 'a']++;
    }

    int start = 0;
    
    for (int end =0 ; end< s2.length(); end++){
        counter[s2[end]- 'a']--;
        if(end -start + 1 == s1.length()){
            if(allZeroes(counter)){
                return false;
            }
            counter[s2[start]- 'a']++;
            start++;
        }
    }
    return true;
}
