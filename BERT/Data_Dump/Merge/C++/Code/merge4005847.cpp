#include <iostream>
#include<math.h>
using namespace std;
int c;
int merge(int *A,int left,int mid,int right){
    int n1=mid-left;
    int n2=right-mid;
    int l[n1+1],r[n2+1];
    for(int i=0;i<n1;i++){
        l[i]=A[left+i];
    }
    for(int i=0;i<n2;i++){
        r[i]=A[mid+i];
    }
    l[n1]=1000000000;
    r[n2]=1000000000;
    int i=0,j=0;
    for(int k=left;k<right;k++){
        c++;
        if(l[i]<=r[j]){
            A[k]=l[i];
            i++;
            
        }else{
            A[k]=r[j];
            j++;
        }
    }return 0;
}
int mergeSort(int *A,int left,int right){
    if(left+1<right){
        int mid=(left+right)/2;
        mergeSort(A,left,mid);
        mergeSort(A,mid,right);
        merge(A,left,mid,right);
    }
    return 0;
}
int main(){
    int n;
    cin>>n;
    int s[n];
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    c=0;
    mergeSort(s,0,n);
    for(int i=0;i<n;i++){
        if(i!=n-1)cout << s[i]<<" ";
        if(i==n-1){
            cout <<s[i]<<endl<< c << endl;
        }
    }
}

