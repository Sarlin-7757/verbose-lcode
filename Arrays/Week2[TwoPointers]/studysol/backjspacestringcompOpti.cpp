#include<string>


bool backspaceCompare(std::string s, std::string t){

    int i; 
    int j; 
    int skip_s = 0 ; 
    int skip_t = 0;

    while (i>=0 || j >=0){

        while (i >=0){
            if(s[i] == '#'){
                skip_s ++ ; 
                i --;
            }
            else if (skip_s > 0){
                skip_s -- ; 
                i--;
            }
            else {
                break;
            }
        }

        while (j >=0){
            if(t[j] == '#'){
                skip_t ++;
                j--;
            }
            else if (skip_t> 0){
                skip_t--;
                j--;
            }
            else{
                break;
            }
        }


        char a = (i < 0 )? '$' : s[i] ;
        char  b = (j < 0 )? '$' : t[j];

        if (a != b ){ 
            return false; 
        }


        i--;
        j--;
    }

    return true;


}


