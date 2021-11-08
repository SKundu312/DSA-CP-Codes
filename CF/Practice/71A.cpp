#include <iostream>
using namespace std;
 
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    if(s.size()>10)
	    {
	        string s1;
	        s1+=s[0]+to_string(s.size()-2)+s[s.size()-1];
	        cout<<s1<<endl;
	    }
	    else
	    cout<<s<<endl;
	}
	return 0;
}
