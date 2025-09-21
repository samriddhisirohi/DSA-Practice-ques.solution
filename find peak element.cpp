class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
          int start=0, end=nums.size()-1 ;
          while(start<=end)
          {
            int mid= start+(end-start)/2 ;

               
                // Handle neighbors safely

            long left  = (mid == 0) ? LONG_MIN : nums[mid - 1];
            /*mid == 0 → checks if mid is the first element.

If true → set left = LONG_MIN (a very small number, so nums[mid] > left is always true).

If false → set left = nums[mid-1] (the actual left neighbor).*/

            long right = (mid == (int)nums.size() - 1) ? LONG_MIN : nums[mid + 1];
            /*long right = (mid == nums.size() - 1) ? LONG_MIN : nums[mid + 1];

mid == nums.size() - 1 → checks if mid is the last element.

If true → set right = LONG_MIN.

If false → set right = nums[mid+1] (the actual right neighbor).*/


            if(nums[mid]>left && nums[mid]>right)
            return mid ;

            else if(nums[mid]>left)
            start=mid+1 ;

            else
            end=mid-1 ;
          }

          return start ;
    }
    
};

//another simpler solution
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] > nums[mid + 1])
                end = mid;       // peak is on the left side or at mid
            else
                start = mid + 1; // peak is on the right side

        }

        return start; // start == end = peak index
    }
};
