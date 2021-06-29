#include <iostream>
using namespace std;
#define INF 1000000001
#define MAX 500000
int L[MAX/2+1],R[MAX/2+1],count=0;
void marge(int A[],int left,int mid,int right){
    int n1=mid-left;
    int n2=right-mid;
    for(int i=0;i<n1;i++) L[i]=A[left+i];
    for(int i=0;i<n2;i++) R[i]=A[mid+i];
    L[n1]=INF;
    R[n2]=INF;
    int i=0,j=0;
    for(int k=left;k<right;k++){
        if(L[i]<=R[j]){
            A[k]=L[i];
            i+=1;
        }
        else{
            A[k]=R[j];
            j+=1;
        }
        count+=1;
    }
}
void margesort(int A[],int left,int right){
    if(left+1<right){
        int mid=(left+right)/2;
        margesort(A,left,mid);
        margesort(A,mid,right);
        marge(A,left,mid,right);
    }
}
int main(){
    int A[MAX]={},n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    margesort(A,0,n);
    for(int i=0;i<n;i++){
        if(i==0){
            cout<<A[i];
        }
        else{
            cout<<" "<<A[i];
        }
    }
    cout<<endl;
    cout<<count<<endl;
    return 0;
}
