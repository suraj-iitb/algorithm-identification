#include <stdio.h>
#define M 500000

int unit[M],cnt;
int L[M/2+2],R[M/2+2];

void merge(int left,int mid, int right){
    int n1,n2,i;
    n1=mid -left;
    n2=right - mid;
    for(i=0;i<n1;i++){
        L[i]=unit[left+i];
    }
    for(i=0;i<n2;i++){
        R[i]=unit[mid+i];
    }
    L[n1]=R[n2]=2000000000;
    i=0;
    int j=0;
    for(int k=left;k<right;k++){
        cnt++;
        if(L[i]<=R[j]){
            unit[k]=L[i++];
        }
        else {
            unit[k]=R[j++];
        }
    }
}

void mergesort(int left,int right){
    if(left+1<right){
        int mid = (left + right)/2;
        mergesort(left,mid);
        mergesort(mid,right);
        merge(left,mid,right);
    }
}

int main(void){
    cnt=0;
    int kari;
    int i=0,limit,right,left;
    scanf("%d",&limit);
    for(i=0;i<limit;i++){
        scanf("%d",&kari);
        unit[i]=kari;
    }
    mergesort(0,limit);
    for(i=0;i<limit;i++){
        printf("%d",unit[i]);
        if(i!=limit-1)printf(" ");
    }
    printf("\n%d\n",cnt);
    return 0;
}


