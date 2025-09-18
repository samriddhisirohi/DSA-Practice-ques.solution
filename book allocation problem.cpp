class Solution {
  public:
  
  
    bool isvalid(vector<int> &arr, int k, int maxallowedpages) {
        int student = 1;   // Start with 1 student
        int pages = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > maxallowedpages)
                return false;  // Single book exceeds limit

            if (pages + arr[i] > maxallowedpages) {
                student++;      // Need a new student
                pages = arr[i]; // Start counting for new student
            } else {
                pages += arr[i];
            }
        }

        return student <= k; // Valid if we used <= k students
    }

    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if (k > n) return -1; // Not enough books

        int sum = 0, maxBook = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            maxBook = max(maxBook, arr[i]);
        }

        int ans = -1;
        int start = maxBook, end = sum; // Range of answer

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (isvalid(arr, k, mid)) {
                ans = mid;      // Try smaller maximum
                end = mid - 1;
            } else {
                start = mid + 1; // Increase pages
            }
        }
        return ans;
    }
};

  
 /* bool isvalid(vector<int>arr,int k,int maxallowedpages)
  {
      int student=1, pages=0 ;
      for(int i=0; i<arr.size(); i++)
      {
          if(arr[i]>maxallowedpages)
          {
              return false ;
          }
          else
          {
              student++ ;
              pages=arr[i] ;
          }
      }
      return student>k ? false : true ;
      
  }
    int findPages(vector<int> &arr, int k) {
        // code here
        int n=arr.size() ;
       if(k>n)
       {
        return -1 ;   
       }
       int sum=0 ;
       for(int i=0; i<n; i++)
       {
           sum=+arr[i] ;
       }
       
       int ans=-1 ;
       int start=0, end=sum ; //range of ans
       while(start<=end)
       {
           int mid=start+(end-start)/2 ;
           if(isvalid(arr,k,mid))   //left
           {
               ans=mid ;
               end=mid-1 ;
               
           }
           else           //right
           start=mid+1 ;
       }
       
       return ans ;
    }
}; */