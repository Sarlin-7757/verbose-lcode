#include<vector>
#include<iostream>
#include<string>
#include<unordered_map>

std::vector<std::string>result;


void solve(int idx ,std::string &digits , std::string &temp  , std::unordered_map<char , string> &mp){
    if(idx >= digits.length()){
        result.push_back(temp);
        return;
    }

    char ch = digits[idx];

    std::string str = mp[ch];

    for (int i = 0 ; i < str.length() ; i++){
        // DO
        temp.push_back(str[i]);
        // Solve
        solve(idx+1 , digits , temp , mp);
        //UNOD
        temp.pop_back();

    }
}


std::vector<std::string> letterCombinations(std::string digits) {

    if(digits.length() == 0){
        return {};
    }


    std::unordered_map <char ,std::string>mp;

    mp['2'] =  "abc";
    mp['3'] = "def";
    mp['4'] = "ghi";
    mp['5'] = "jkl";
    mp['6'] = "mno";
    mp['7'] = "pqrs";
    mp['8'] = "tuv";
    mp['9'] = "wxyz";

    std::string temp = "";
    solve(0 , digits ,temp, mp );

    return result;
        
}