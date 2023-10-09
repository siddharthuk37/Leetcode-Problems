 #include<iostream>
 #include<vector>
using namespace std;
 double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()<nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }
        int n=nums1.size();
        int m=nums2.size();
        int k=(n+m)%2==0?(n+m)/2-1:(n+m)/2;
        k++;
        
        int lo=max(0,k-m);
        int hi=min(k,n);
        double ans1=0;
        double ans2=0;
        while(lo<=hi){
            int cut1=(lo+hi)/2;
            int cut2=k-cut1;
            
            int l1=cut1==0?INT_MIN:nums1[cut1-1];
            int l2=cut2==0?INT_MIN:nums2[cut2-1];
            int r1=cut1==n?INT_MAX:nums1[cut1];
            int r2=cut2==m?INT_MAX:nums2[cut2];
            if(l1<=r2 && l2<=r1){
                ans1=max(l1,l2);
                if((n+m)%2!=0)return ans1;
               else{
                    ans2=min(r1,r2);
                    return (ans1+ans2)/2.0;
                }
                
            }
            else if(l1>r2){
                hi=cut1-1;
            }
            else{
                lo=cut1+1;
            }
        }
        return -1;
        
    }
    int main(){
        int arr1[2]={1,2};
        int arr2[2]={3,4};
        vector<int>nums1(arr1,arr1+2);
        vector<int>nums2(arr2,arr2+2);
        cout<<findMedianSortedArrays(nums1,nums2);
    }