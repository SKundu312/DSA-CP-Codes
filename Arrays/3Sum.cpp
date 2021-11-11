class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        if(nums.size()<3)
            return ans;
        sort(nums.begin(),nums.end());
         int j,k;
        for(int i=0;i<nums.size()-2;i++){
           j=i+1;
           k=nums.size()-1;
           int sum =0-nums[i];
            if(i && nums[i]==nums[i-1])
                continue;
            while(j<k){
                if(nums[j]+nums[k]<sum)
                    j++;
                else if(nums[j]+nums[k]>sum)
                    k--;
                else{
                    vector<int>row;
                    row.push_back(nums[j]);
                    row.push_back(nums[k]);
                    row.push_back(nums[i]);
                    ans.push_back(row);
                    while(j<k && nums[k]==nums[k-1])k--;
                    while(j<k && nums[j]==nums[j+1])j++;
                    j++;
                    k--;
                }
            }
        }
        return ans;
    }
};
