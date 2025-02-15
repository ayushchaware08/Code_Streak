#include<iostream>
using namespace std;
bool ispalindrome(string& s){
    int start = 0, end = s.length();
    while(start < end){
        if(s[start]!=s[end]) return false;
        start++;
        end--;
    }
}
int subarr(string& s){
    int i=0, j=s.length();
    
    for(int i =0; i<s.length(); i++){
        string temp ="";
        for(int j =i+1; j<s.length(); j++){
            temp.push_back
            (s[i]);
        }
    }
}
int main(){



}