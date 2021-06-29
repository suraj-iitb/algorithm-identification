#include <bits/stdc++.h>
using namespace std;
int a[500009],t[500009],r=0;
void mergesort(int lo,int hi){
if(lo==hi) return;
int mid =(lo+hi)/2;
mergesort(lo,mid);
mergesort(mid+1,hi);
int i,j,k;
i=lo;
j=mid+1;
for(k=lo;k<=hi;k++){
if(i==mid+1) t[k]=a[j++];
else if(j==hi+1)  t[k]=a[i++];
else if(a[i]<a[j]) t[k]=a[i++];
else t[k]=a[j++];
r++;
}
for(k=lo;k<=hi;k++){
a[k]=t[k];
}
}
int main()
{
int m,n,i,j,s=0,t=0,te;
cin>>n;
for(i=0;i<n;i++) cin>>a[i];
mergesort(0,n-1);
for(i=0;i<n-1;i++) cout<<a[i]<<" ";
cout<<a[n-1]<<endl;
cout<<r;
cout<<endl;
return 0;
}
