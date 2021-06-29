#include<iostream>
#include<vector>
using namespace std;
int cnt=0;
long long t=2000000000;

void merge(vector<int> &a,int left,int mid,int right){
    int m=mid-left;
    int n=right-mid;
    vector<int> b(m+1),c(n+1);
    for(int i=0;i<m;i++){
        b[i]=a[left+i];
    }
    for(int i=0;i<n;i++){
        c[i]=a[mid+i];
    }
    b[m]=t;
    c[n]=t;
    int j=0,k=0;
    for(int i=left;i<right;i++){
        cnt++;
        if(b[j]<=c[k]){
            a[i]=b[j++];
        }
        else a[i]=c[k++];
    }
}

void merge_sort(vector<int> &a,int left,int right){
    if(left+1<right){
        int mid=(left+right)/2;
        merge_sort(a,left,mid);
        merge_sort(a,mid,right);
        merge(a,left,mid,right);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    merge_sort(a,0,n);
    for(int i=0;i<n;i++){
        if(i)cout<<' ';
        cout<<a[i];
    }
    cout<<endl;
    cout<<cnt<<endl;
}
