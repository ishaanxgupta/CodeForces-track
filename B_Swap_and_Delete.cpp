#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

//ismein bas zero aur one ka count rkh liya aur fir iterate kri string aur fir agar zero mila toh check kiya one se swap kr skte aur one mila toh check
//kiya zero se swap kr skte aur kisi bhi point par agar ni kr skte toh uske age ke sab delete hi krne padenge
int solve(string s){
    int n = s.size();
    if(n == 1){
        return 1;
    }
    if(n == 0){
        return 0;
    }

   int zeroes = 0;
   int ones = 0;
   for(auto ch:s){
    if(ch == '0'){
        zeroes++;
    }else{
        ones++;
    }
   }

   int ans = 0;
   for(int i=0;i<n;i++){
    int element = s[i] - '0';
    if(element == 0 && ones > 0){
        ones--;
    }else if(element == 1 && zeroes > 0){
        zeroes--;
    }else{
        ans = n-i;
        break;
    }
   }
   return ans;

}

int main(){
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        int ans = solve(s);
        cout<<ans<<endl;
    }
    return 0;
}
