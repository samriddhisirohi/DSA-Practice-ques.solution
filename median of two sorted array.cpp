//its time complexity is O((m+n)log(m+n)) instead O(log(m+n))

/* Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5. */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int m= nums1.size() ;
        int n= nums2.size() ;
        vector <int> temp ;

       for(int i = 0; i < m; i++)
             temp.push_back(nums1[i]);

        for(int i = 0; i < n; i++)
             temp.push_back(nums2[i]);

        sort(temp.begin(),temp.end()) ;

        //int start=0, end=temp.size()-1 ;

        int size= temp.size() ;

            double ans;

             if (size % 2 == 0)
                 ans = (temp[size/2 - 1] + temp[size/2]) / 2.0;

            else
                ans = temp[size/2];
       

     

        return ans ;

          }
};