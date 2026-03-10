class Solution {

public:

vector<int> maxSlidingWindow(vector<int>& nums, int k) {

 deque<int>d ;
 vector<int>ans ;

        //k-1 elements ko traverse krna
        for(int i=0; i<k-1; i++)
        {
            if(d.empty())
            d.push_back(i) ;

            else
            {
             while(!d.empty()&&nums[i]>nums[d.back()])
             d.pop_back() ;

             d.push_back(i) ;
            }
        }

        int n= nums.size() ;
        for(int i=k-1; i<n; i++)
        {
            //remove smaller element from back
            while(!d.empty() && nums[i]>nums[d.back()])
             d.pop_back() ;

            d.push_back(i) ;

            //checking if starting index in d exist in window, if not then pop_front()
            if(d.front()<=i-k)
            d.pop_front() ;

            ans.push_back(nums[d.front()]) ;
        }

        return ans ;
    }
};