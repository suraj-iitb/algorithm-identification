#include <bits/stdc++.h>
using namespace std;
 
void marge(vector<int>&a,int left,int mid,int right,int &cnt){
    int nl=mid-left,nr=right-mid;
    vector<int> L(nl+1),R(nr+1);
    for(int i=0;i<nl;i++)L[i]=a[left+i];
    for(int i=0;i<nr;i++)R[i]=a[mid+i];
    L[nl]=2000000000;
    R[nr]=2000000000;
    int i=0,j=0;
    for(int k=left;k<right;k++){
        if(L[i]<=R[j]){
            a[k]=L[i];
            i++;
        }else{
            a[k]=R[j];
            j++;
        }
        cnt++;
    }
    return;
}
void margesort(vector<int>&a,int left,int right,int &cnt){
    if(left+1<right){
        int mid=(left+right)/2;
        margesort(a,left,mid,cnt);
        margesort(a,mid,right,cnt);
        marge(a,left,mid,right,cnt);
    }
    return;
}
int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int cnt=0,left=0,right=n;
    margesort(a,left,right,cnt);
    for(int i=0;i<n;i++){
      cout<<a[i];
      if(i<n-1)cout<<' ';
}
    cout<<endl<<cnt<<endl;
  return 0;
}
