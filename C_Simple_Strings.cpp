#include<bits/stdc++.h>
using namespace std;
int main()
{
    //brute hi accept ho gya ki bhai char check kro prev wale se aur fir a to z koi bhi element dhoondhke lagado min wala check ni krna pada
    long int i,j,cnt,x,y;
    string s;
    while(cin>>s)
    {
        for(i=1;i<s.size();i++){
           if(s[i]==s[i-1]){
            for(j='a';j<='z';j++){
                //this check makes this the most optimal 
                if(s[i+1]!=j && s[i-1]!=j)
                {
                    s[i]=j;
                    break;
                }
            }
           }
        }
        cout<<s<<endl;
    }
    return 0;
}