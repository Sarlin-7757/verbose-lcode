#include<vector>
#include<string>


// #define mod 1000000007


int uniqueLetterString(std::string s) {
 #define mod 1000000007
// example s = 'ABC  , t = A , B , C ,  AB , BC , ABC so sum = 1 + 1 + 1 + 2 + 2 + 3 = 10 
int n = s.size(); 

std::vector<std::vector<int>>hashmap(26);


// prefix -1 to the list for the left hand side limit to find the size of left window 

for (int i = 0 ; i < 26 ; i++){
    hashmap[i].push_back(-1);
}


// set the indices of occurance of characters on the list 
for (int i = 0; i < s.size(); i++){
    char ch = s[i];
    hashmap[ ch - 'A'].push_back(i);
}

// suffix the right hand limit to the list in order to find the right window.

for (int i = 0 ; i < 26 ; i ++){
    hashmap[i].push_back(n);
}



long long count = 0; 

for (int i = 0 ; i < 26 ; i ++){
    for (int j = 1 ; j < hashmap[i].size()- 1; j++){
        count += ((hashmap[i][j] - hashmap[i][j-1]) * (hashmap[i][j+1] - hashmap[i][j]));
    }
}
return count;


        
}