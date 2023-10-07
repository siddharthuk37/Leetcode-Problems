/*
Problem Description : 
===================================================
1835. Find XOR Sum of All Pairs Bitwise AND
Difficulty : Hard
===================================================
Complexity
Time complexity:
      O(m or n) depending upon which array size is bigger
Space complexity:
      O(1)

*/

int getXORSum(int* arr1, int arr1Size, int* arr2, int arr2Size){
   int sum=0,xand=0;
    for(int j=0;j<arr2Size;j++){
           xand^=arr2[j];
       }
   for (int i=0;i<arr1Size;i++){
            sum^=arr1[i]&xand;
   }  
   return sum;
}