class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        int start=0, end=nums.size()-1 ;

        while(start<=end)
        {
            int mid= start+(end-start)/2 ;

            if(nums[mid]==target)
            {
                return true ;

            }

              // 🔑 Handle duplicates
            if (nums[start] == nums[mid] && nums[mid] == nums[end]) {
                start++;
                end--;
            }
            /*When nums[start] == nums[mid] == nums[end],
                we can’t decide which side is sorted.

                Incrementing start and decrementing end
                safely skips duplicates and keeps correctness. */


            //left main sorted h
            else if(nums[mid]>=nums[start])
            {
                if(nums[start]<=target && nums[mid]>target)
                end=mid-1 ;

                else 
                start=mid+1 ;
            }

            //right side sorted h, check karenge

            else
            {
                if(nums[mid]<target && nums[end]>=target)
                    start=mid+1 ;

                    else
                    end=mid-1 ;
            }

            
        }

        return false ;

    }
};