#include <iostream>
using namespace std;

int cnt=0,n;

void merge(int s[],int left,int mid,int right){
    int n1=mid-left;
    int n2=right-mid;
    int L[n1+1],R[n2+1];
    int i,j,k;
    for(i=0;i<n1;i++)L[i]=s[left+i];
    for(i=0;i<n2;i++)R[i]=s[mid+i];
    L[n1]=R[n2]=1000000001;
    i=j=0;
    for(k=left;k<right;k++){
        if(L[i]<=R[j]){
            s[k]=L[i];
            i++;
        }
        else{
            s[k]=R[j];
            j++;
        }
        cnt++;
    }
}

void mergeSort(int s[],int left,int right){
    if(left+1<right){
        int mid=(left+right)/2;
        mergeSort(s,left,mid);
        mergeSort(s,mid,right);
        merge(s,left,mid,right);
    }
}

int main(void){
    int i,s[500000];
    
    cin>>n;
    for(i=0;i<n;i++)cin>>s[i];
    
    mergeSort(s,0,n);
    
    for(i=0;i<n-1;i++)cout<<s[i]<<" ";
    cout<<s[n-1]<<endl;
    
    cout<<cnt<<endl;

    return 0;
}

