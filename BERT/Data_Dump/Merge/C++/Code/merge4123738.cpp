#include <iostream>
#define infty 1000000001
using namespace std;
int c=0;
void merge(int *a,int left,int mid,int right){
    int n1=mid-left;
    int n2=right-mid;
    int l[n1+1];
    int r[n2+1];
    for(int i=0;i<n1;i++){
        l[i]=a[left+i];
    }
    for(int i=0;i<n2;i++){
        r[i]=a[mid+i];
    }
    l[n1]=infty;
    r[n2]=infty;
    int i=0;
    int j=0;
    for(int k=left;k<right;k++){
        c++;
        if(l[i]<=r[j]){
            a[k]=l[i];
            i++;
        }
        else{
            a[k]=r[j];
            j++;
        }
    }
}
void mergesort(int *a,int left,int right){
    if(left+1<right){
        int mid=(right+left)/2;
        mergesort(a,left,mid);
        mergesort(a,mid,right);
        merge(a,left,mid,right);
    }
}
int main(){
    int n;
    cin>>n;
    int b[n];
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    mergesort(b,0,n);
    for(int i=0;i<n-1;i++){
        cout<<b[i]<<" ";
    }
    cout<<b[n-1]<<endl;
    cout<<c<<endl;
    return 0;
}
