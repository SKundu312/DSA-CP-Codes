//O(n^2)-brute force approach
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> count;
        int h=0,k=0;
        for(int i=0;i<=s.size()-1;i++){
            int j=s.size()-1;
            while(i<=j){
            if(s[i]==s[j] && i!=j){
                if(j>=k)
                k=j;
                break;
            }
            j--;
          }
            if(i==k){
              count.push_back(k-h+1);
              h=i+1;
              k=i+1;
            }
        }
        return count;
    }
};
