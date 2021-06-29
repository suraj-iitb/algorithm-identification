#include <bits/stdc++.h>
using namespace std;
int A[1000],B[1000];
int main()
{
   int n,c=0,d,w[100000];
   cin>>n;
   for(int a=0;a<n;a++)
   {
       cin>>d;
       w[a]=d;
   }
   int e;
   int k=0;
   for(int a=0;a<n;a++)
   {
       for(int b=0;b<n-a-1;b++)
       {
           if(w[b]>w[b+1])
           {
               k++;
               e=w[b];
               w[b]=w[b+1];
               w[b+1]=e;
           }
       }
   }
   for(int a=0;a<n;a++)
   {
       if(a==n-1)
       {
           cout<<w[a];
       }
       else
       {
       cout<<w[a]<<" ";
       }
   }
   cout<<endl;
   cout<<k<<endl;
}
