#include<bits/stdc++.h>
using namespace std;
#define N 500000
#define S 1000000001
 
void merge(int *, int, int ,int);
void mergeSort(int *, int, int);
int cnt;

int main(){
  int n,s[N];
  cin>>n;
  for(int i=0;i<n;i++) cin>>s[i];
  mergeSort(s,0,n);
   
  for(int i=0;i<n-1;i++)cout<<s[i]<<' ';
  cout<<s[n-1]<<endl<<cnt<<endl;
  return 0;
}
 
void merge(int *a,int left,int mid,int right){
  int n1 = mid - left;
  int n2 = right - mid;
  int l[n1+1], r[n2+1];
   
  for(int i=0;i<n1;i++) l[i]=a[left + i];  
  for(int i=0;i<n2;i++) r[i]=a[mid + i];
  l[n1]=S;
  r[n2]=S;
  int x=0,y=0;

  for(int k=left;k<right;k++){
    if(l[x]<=r[y]){
      a[k]=l[x];
      x++;
    }
    else{
      a[k]=r[y];
      y++;
    }
    cnt++;
  }
}
 
void mergeSort(int *a, int left, int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergeSort(a,left,mid);
    mergeSort(a,mid,right);
    merge(a,left,mid,right);
  }
}

