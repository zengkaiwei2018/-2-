



#include<iostream>
#include<stdio.h>
using namespace std;

void HeapAdjust(int L[],int s,int m)
{
    int rc=L[s];
    for(int j=2*s;j<=m;j*=2)
    {
        if(j<m && L[j]<L[j+1])
            ++j;
        if(rc>=L[j])
            break;
        L[s]=L[j];
        s=j;
    }
    L[s]=rc;
}
void CreatHeap(int L[],int n)
{
    for(int i=n/2;i>0;i--)
    {
        HeapAdjust(L,i,n);
    }
}
void HeapSort(int L[],int n)
{
    CreatHeap(L,n);
   for(int i=n;i>1;i--)
   {
       int x=L[1];
       L[1]=L[i];
       L[i]=x;
       HeapAdjust(L,1,i-1);
   }
}
void Print(int L[],int n)
{
    cout<<L[1];
    for(int i=2;i<=n;i++)
    {
        cout<<" "<<L[i];
    }
    cout<<endl;
}
int main()
{
   ios::sync_with_stdio(false);
   int N;
   cin>>N;
   int data[N+1];
   data[0]=0;
   for(int i=1;i<=N;i++)//下标从1开始
   {
       cin>>data[i];
   }
   HeapSort(data,N);
   Print(data,N);
   return 0;
}
