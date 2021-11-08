#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    int c=1;
    for(int i=1;i<s.length();i++){
        if(s[i-1]!=s[i])
        c++;
    }
    if(c%2)
    cout<<"IGNORE HIM!";
    else
    cout<<"CHAT WITH HER!";
	return 0;
}
