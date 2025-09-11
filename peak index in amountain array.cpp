class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int n=arr.size(), start=0, end=arr.size()-1 ;
       
      while(start<=end)
        {
             int mid = end + (start - end) / 2; //ab runtime eeror nhi de rha
            /*pehle memory location nhi kr skta vo access krne ko bol rhe the*/
            
             //peak element
             if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
             return mid ;
            
            //right side move
             else if(arr[mid]>arr[mid-1])
             start=mid+1 ;

            //left side move
             else
             end=mid-1 ;
        }

        return -1 ;

     }
};