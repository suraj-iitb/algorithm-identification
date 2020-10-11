#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define SENTINEL INT_MAX
 
int A[500000],c=0;
int L[300000], R[300000];
 
void Merge(int left, int mid, int right){
    int i, j, k;
    int n1 = mid - left;
    int n2 = right - mid;
 
 
    for (i = 0; i < n1;i++){
        L[i] = A[left + i];
    }
    for (i = 0; i < n2;i++){
        R[i] = A[mid + i];
    }
    L[n1] = SENTINEL;
    R[n2] = SENTINEL;
    i = 0;
    j = 0;
    for (k = left; k < right;k++){
        c++;
        if (L[i] <= R[j]){
            A[k] = L[i];
            i = i + 1;
        }else{
            A[k] = R[j];
            j = j + 1;
        }
    }
}
 
void Merge_Sort(int left, int right){
    int mid;
    if (left + 1 < right){
        mid = (left + right) / 2;
        Merge_Sort(left, mid);
        Merge_Sort(mid, right);
        Merge(left, mid, right);
    }
}
 
int main(){
    int i, j, k;
    scanf("%d",&i);
    for (j = 0; j < i;j++){
        scanf("%d",&A[j]);
    }
 
    Merge_Sort(0,j);
 
     
    for (i = 0; i < j; i++){
        printf("%d", A[i]);
        if (i < j - 1){
            printf(" ");
        }
    }
printf("\n%d\n",c);
return 0;
}
