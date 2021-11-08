#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
    int k,n,w;
    cin>>k>>n>>w;
    if((w*(w+1)*k)/2 <=n)
    cout<<"0";
    else
    cout<<(w*(w+1)*k)/2 -n;
	return 0;
}
