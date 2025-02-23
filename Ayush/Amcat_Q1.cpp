#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
int editor(string s){
    int cnt =0;
    for(int i =0; i<s.size(); i++){
        if((s[i]!=' ') || (s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            cnt++;
        }
    }
    return cnt;
}
int main(){
    string s;
    // for(int i =0; i<s.length(); i++){
    //     cin>>s[i];
    // }
    getline(cin, s);
    int ans = editor(s);
    cout<<ans;
    return 0;
}