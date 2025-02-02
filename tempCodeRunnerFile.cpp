#include<stdc/bitsc++.h>
#include<iostream>
#include<string>
int editor(string s){
    for(int i =0; i<s.size(); i++){
        if((s[i]!=' ') || (s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            return 1;
        }
    }
    return 0;
}
int main(){
    string s = "";
    for(int i =0; i<s.length(); i++){
        cin>>s[i];
    }
    int ans = editor(s);
    if(ans == 0) cout<<"Error"<<endl;
    else cout<<"Sucessful"<<endl;
    return 0;
}