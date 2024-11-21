#include<iostream> 
#include<vector>
#include<algorithm>
int a[10000];

int b = 100;
int solve(){
    for(int i = 0 ; i < 3; i++){
        std::cin >> a[i];
    }
    std::sort(a , a+3);
    int ans = 0;
    for(int i = 0 ; i < 3; i++){
        if(b >= a[i]){
            b -= a[i];
            ans++;
        }       
    }
    return ans;
}

int main(){
   int res = solve();
   std::cout << res << "\n";
}
