/*
 * FileName:     merge_sort_fix
 * CreatedDate:  2020-04-13 17:25:44 +0900
 * LastModified: 2020-04-13 21:33:38 +0900
 */

#include <stdio.h>
#define INFTY 1000000001
int count=0;
void merge(long int *s,int left,int mid,int right){
    int n1=mid-left;
    int n2=right-mid;
    long int L[n1+1],R[n2+1];
    for(int i=0;i<n1;i++){
        L[i]=s[left+i];
    }
    for(int i=0;i<n2;i++){
        R[i]=s[mid+i];
    }
    L[n1]=INFTY;
    R[n2]=INFTY;
    int i=0,j=0;
    for(int k=left;k<right;k++){
        if(L[i]<=R[j]){
            s[k]=L[i++];
        }
        else{
            s[k]=R[j++];
        }
        count++;
    }
}
void mergesort(long int *s,int left,int right){
    if(left+1<right){
        int mid = (left+right)/2;
        mergesort(s,left,mid);
        mergesort(s,mid,right);
        merge(s,left,mid,right);
    }
}
int main(void){
    int n;
    scanf("%d",&n);
    long int s[n];
    for(int i=0;i<n;i++){
        scanf("%ld",&s[i]);
    }
    mergesort(s,0,n);
    printf("%ld",s[0]);
    for(int i=1;i<n;i++){
        printf(" %ld",s[i]);
    }
    printf("\n");
    printf("%d\n",count);
    return 0;
}

