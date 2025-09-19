 class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0;
        int end   = nums.size() - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            
            if (mid % 2 == 1) mid--; /*agar mid odd h toh uske piche wala same 
            hona chahiye ya left side main hi single element hoga*/ 
            
            /* toh hamne mid-- kr diya, even ho gya ab mid ko mid+1 se compare kr
            lenge, same hua toh ab tk sahi tha, single element right main hoga
            else
            same nhi hua means mid ko bhi consider krna hoga as singleelement   ke loop main */

            if (nums[mid] == nums[mid + 1]) {
                // pair is correct → single is to the right
                start = mid + 2;
            } else {
                // pair is broken → single is at mid or to the left
                end = mid;
            }
        }

        return nums[start]; // start == end → single element
    }
};

/*class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size() ;
        int mid ;
        int start=0, end=n-1 ;
        while(start<=end)
        {
            int mid= start+(end-start)/2 ;

               if(mid%2==1)                
        {
            mid-- ;
           /* if(nums[mid]==nums[mid-1])
            {
                start=mid+1 ;
            }
            else
            {
                end=mid-1 ; /*here  odd mid is not considered
                             bcoz single element will always have even index 
            } 

                  
            }

             //even index se naya no. start hota h
            
                if(nums[mid]==nums[mid+1])
                {
                    start=mid+2 ;
                }
                else
               { end=mid ;
                
               }
            

              //index/mid is odd
         
        }
         return nums[start] ;
              
         

    }
          
    
};*/