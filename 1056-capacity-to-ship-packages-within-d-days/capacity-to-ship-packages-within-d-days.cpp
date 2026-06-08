class Solution {
public://finding minimum
    int maximum(vector<int>& w){
        int maxi=INT_MIN;
        for(int i=0;i<w.size();i++)
        {
            maxi=max(w[i],maxi);
        }
        return maxi;
    }
    int day(int cap,vector<int>& wt)
    {
        int load=0;int days=1;
        for(int i=0;i<wt.size();i++)
        {
            if(load+wt[i]>cap)
            {
                days++;
                load=wt[i];
            }
            else
            {
                load=load+wt[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        //Find the max
        int sum=0;
        for(int i=0;i<weights.size();i++)
        {
            sum=sum+weights[i];
        }
        int start=maximum(weights);
        int end=sum;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(day(mid,weights)<=days)
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