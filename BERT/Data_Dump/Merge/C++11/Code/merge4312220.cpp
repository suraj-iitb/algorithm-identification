#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;

int cnt;
void merge(int A[], int left,int mid,int right){
    int n1 = mid - left;
    int n2 = right - mid;
    int L[n1+1],R[n2+1];

    for(int i = 0; i < n1 ; i++){
       L[i] = A[left+i]; 
    }
    for(int i = 0; i < n2 ; i++){
        R[i]=A[mid+i];
    }
    L[n1] = INT32_MAX;
    R[n2] = INT32_MAX;
    int i=0;
    int j=0; 
    for(int k = left; k<right  ; k++){
        if(L[i]<=R[j]){
            A[k] = L[i];
            i++;
        }else{
            A[k] = R[j];
            j++;
        } 
        cnt++;
    }
}
void mergesort(int A[],int left,int right){
    if(left+1<right){
        int mid = (left + right)/2;
        mergesort(A,left,mid);
        mergesort(A,mid,right);
        merge(A,left,mid,right);
    }else{
        return ;
    } 
}
int main(){
    int n;
    cin >> n;
    int A[n];
    for(int i = 0; i < n ; i++){
        scanf("%d",&A[i]); 
    }
    mergesort(A,0,n);
    for(int i=0; i<n; i++){
        if(i>=1)
            printf(" ");
        printf("%d",A[i]);
    }
    cout << endl;
    cout << cnt << endl;
}
