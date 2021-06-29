#include<iostream>
using namespace std;

#define INFTY 2000000000
#define MAX 500000

int L[250000+2],R[250000+2];
int t=0;

void marge(int A[],int left,int mid,int right){
    int n1 = mid - left;
    int n2 = right - mid;

    for(int i=0;i<n1;i++) L[i] = A[left + i];
    for(int i=0;i<n2;i++) R[i] = A[mid + i];

    L[n1]=R[n2]=INFTY;

    int i=0,j=0;
    for(int k=left;k<right;k++)
    {
        t=t+1;
       if(L[i]<R[j]){
           A[k] = L[i];
           i = i+1;
       }else{
           A[k] = R[j];
           j = j+1;
       }
    }

}

void margeSort(int A[],int left,int right){
    if(left+1 < right){
        int mid = (left+right)/2;
        margeSort(A,left,mid);
        margeSort(A,mid,right);
        marge(A,left,mid,right);
    }
}

int main(){
    int A[MAX],n;

    cin >> n;
    for(int i=0;i<n;i++) cin >> A[i];

    margeSort(A,0,n);

    for(int i=0;i<n;i++){
        if(i)cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << t << endl;

    return 0;
}
