#include <iostream>
using namespace std;
 
int main() {
	// your code goes here
	int n;
	cin>>n;
	
	while(n--){
	    int h=1;
	    int x;
	    cin>>x;
	    int a[x];
	    for(int i=0;i<x;i++){
	        cin>>a[i];
	    }
	   for(int i=0;i<x;i++){
	       if(a[i]==0){
	           if(i>=1 && a[i-1]==0){
	               h=-1;
	               break;
	           }
	       continue;}
	       if(a[i]==1){
	           
	           if(i>=1 && a[i-1])
	           h+=5;
	           else
	           h+=1;
	       }
	   }
	   cout<<h<<endl;
	}
	return 0;
}
