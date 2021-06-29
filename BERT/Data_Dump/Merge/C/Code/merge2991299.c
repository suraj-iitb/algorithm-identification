#include<stdio.h>

int merge(int[],int,int,int);
int mergeSort(int[],int,int,int);

int main(){
    int i,c,n,s[10000000];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&s[i]);
    }
    c = mergeSort(s,0,n,n);
    for(i=0;i<n;i++){
        printf("%d",s[i]);
        if(i != n-1){
            printf(" ");
        }
    }
    printf("\n%d\n",c);
    return 0;
}

int merge(int A[],int left,int mid,int right){
    int i,j,k,n1,n2,count=0;
    n1 = mid - left;
    n2 = right - mid;
    int L[n1+1], R[n2+1];
    for(i = 0 ; i <= n1-1 ; i++){
        L[i] = A[left + i];
    }
    for(i = 0 ; i <= n2-1 ; i++){
        R[i] = A[mid + i];
    }
    L[n1] = 999999999;
    R[n2] = 999999999;
    i = 0;
    j = 0;
    for(k = left ; k <= right-1 ; k++){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i = i + 1;
            count++;
        }else{
            A[k] = R[j];
            j = j + 1;
            count++;
        }
    }
    return count;
} 
int mergeSort(int A[],int left,int right,int n){
    int mid;
    static int count=0;
    if(n<=1) return count;
    if(left+1 < right){
        mid = (left + right)/2;
        mergeSort(A, left, mid,n);
        mergeSort(A, mid, right,n);
        count += merge(A, left, mid, right);
    }
    return count;
}

