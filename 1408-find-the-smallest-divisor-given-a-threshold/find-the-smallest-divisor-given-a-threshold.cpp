class Solution {
public:
    int maximum(vector<int>& nums){
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            maxi=max(nums[i],maxi);
        }
        return maxi;
    }
    int sumofdivision(vector<int>& nums,int div)
    {   int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum=sum+ceil((double)(nums[i])/(double)(div));
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start=1;
        int end=maximum(nums);
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(sumofdivision(nums,mid)<=threshold)
            {
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return start;
    }
};