#include<iostream>
using namespace std;
#define Max 500000
#define Half 250003
#define terminal 999999999999
typedef long long llong;
llong a[Max];
llong left_a [Half];
llong right_a [Half];
llong cnt=0;
int mergelr(llong a[],int left,int mid,int right){
    int n_left=0,n_right=0,pre_left=0,pre_right=0;
    for(int i=left;i<mid;i++){
        left_a[n_left++]=a[i];
    }
    left_a[n_left]=terminal;
    for(int i=mid;i<right;i++){
        right_a[n_right++]=a[i];
    }
    right_a[n_right]=terminal;
    for(int i=left;i<right;i++){
        cnt++;
        if(left_a[pre_left]<=right_a[pre_right]){
            a[i]=left_a[pre_left++];
        }
        else
            a[i]=right_a[pre_right++];
    }
    return 0;
}
int MergeSort(llong a[],int left,int right){
    int mid=(left+right)/2;
    if((right-left)<=1)
        return 1;
    MergeSort(a,left,mid);
    MergeSort(a,mid,right);
    mergelr(a,left,mid,right);
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    MergeSort(a,0,n);
    for(int i=0;i<n-1;i++)
        cout<<a[i]<<" ";
    cout<<a[n-1];
    cout<<endl;
    cout<<cnt<<endl;

    return 0;
}

