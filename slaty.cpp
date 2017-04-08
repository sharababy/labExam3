

#include<iostream>
#include<climits>
#include<algorithm>
#include<cmath>
using namespace std;


int lsm(int A[],int n){

        int dp[n];//dp array
        dp[0] = A[0];
        int max1 = dp[0];
        
        for(int i = 1; i < n; i++){
            dp[i] = A[i] + ( dp[i - 1] > 0 ? dp[i - 1] : 0);//for dp[i] include dp[i-1] if it is positive add dp[i-1]+a[i] or else include only a[i]
            max1 = max(max1, dp[i]);
        }
        
        return max1;
}

 
int maxSubArraySum(int a[], int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
 
    for (int i = 0; i < size; i++)
    {
           
             max_ending_here = max_ending_here + a[i];
           if (max_so_far < max_ending_here)
               max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
             max_ending_here = 0;
    }
            return max_so_far;
}
 
int main()
{
  int n;
cout<<"enter the size of array"<<endl;
 cin>>n;
    int a[n];
 for(int i=0;i<n;++i)
  {cout<<"enter"<<i+1<<"th element"<<endl  ;
    cin>>a[i];}
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum;
   cout<<"\nmaximum contigous sum is using dp is\n"<<lsm(a,n); 
   return 0;
}
