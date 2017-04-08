#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<ctime>

using namespace std;


void QuickSortRandomAndMedian(int a[],int start,int end);
int MedianOfThreePartition(int a[],int p, int r);
int co,noofswaps=0;
void QuickSortMedian(int a[],int start,int end) {
    int q;
    co++;
    if (end-start<2) return;
    q=MedianOfThreePartition(a,start,end);
    QuickSortMedian(a,start,q);
    QuickSortMedian(a,q,end);
}

int MedianOfThreePartition(int a[],int p, int r) {
    int x=a[p];
    int y=a[(r-p)/2+p];
    int z=a[r-1];
      int  i=p-1;
   int j=r;
    if (y>x && y<z || y>z && y<x ) 
        x=y;
    else if (z>x && z<y || z>y && z<x )     
            x=z;
    while (1) { 
                   
         do  {
		
                    j--;
           	co++;
                        } 
				while (a[j] > x);
        do
          {
		i++;

        	co++;
 } 
while (a[i] < x);
        if  (i < j)
      { 
    swap(a[i],a[j]);
        }
else 
     return j+1;
    
}

}

 int main()
{
 
  int n=30;
  
int a[n];
  for(int i=0;i<n;++i)
    a[i]=rand()%100;

QuickSortMedian(a,0,n-1);
 
for(int i=0;i<n;++i)
    cout<<a[i]<<" \t";
cout<<endl;
 
return 0;
}

