#include <iostream>
using namespace std;
 
int main() {
	// your code goes here
	int n ;
	cin>>n;
	while(n--){
	    int a[7];
	    int ans[3];
	    for(int i=0;i<7;i++)
	    cin>>a[i];
	    ans[0]=a[0];
	    for(int i=1;i<6;i++){
	        for(int j=i+1;j<6;j++)
	        if((a[6]-a[0]-a[i])==a[j]){
	            ans[1]=a[i];
	            ans[2]=a[j];
	        }
	    }
	    for(int i=0;i<3;i++)
	    cout<<ans[i]<<" ";
	    cout<<endl;
	}
	return 0;
}
