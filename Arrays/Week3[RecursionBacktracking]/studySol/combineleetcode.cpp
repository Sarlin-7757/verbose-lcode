#include<vector>
#include<string>
#include<algorithm>

using std::vector; 
using std::string;
using std::sort;
const vector<string> phoneMap = {
    "",     // 0
    "",     // 1
    "abc",  // 2
    "def",  // 3
    "ghi",  // 4
    "jkl",  // 5
    "mno",  // 6
    "pqrs", // 7
    "tuv",  // 8
    "wxyz"  // 9
};

// Recursive function to generate combinations
void backtrack(const string& digits, int index, string current, vector<string>& combinations) {
    if (index == digits.size()) {
        combinations.push_back(current);
        return;
    }

    // Get the letters corresponding to the current digit
    string letters = phoneMap[digits[index] - '0'];

    for (char letter : letters) {
        backtrack(digits, index + 1, current + letter, combinations);
    }
}

string letterCombinations(const string& digits) {
    if (digits.empty()) return "";

    vector<string> combinations;
    backtrack(digits, 0, "", combinations);

    // Sort combinations in descending order
    sort(combinations.rbegin(), combinations.rend());

    // Combine all combinations into a single string
    string result;
    for (const string& comb : combinations) {
        result += comb + " ";
    }

    // Remove trailing space and return
    if (!result.empty()) result.pop_back();
    return result;
}


int main(){
  return 0;
}
