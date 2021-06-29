#include<stdio.h>
#include<stdlib.h>
int merge(int *S,int left,int mid,int right,int count){
    int n1,n2,i,j,k;
    double *L,*R;
    n1=mid-left;
    n2=right-mid;
    L=malloc(sizeof(double)*(n1+1));
    R=malloc(sizeof(double)*(n2+1));
    for(i=0;i<n1;i++){
        *(L+i)=*(S+left+i);
    }
    for(i=0;i<n2;i++){
        *(R+i)=*(S+mid+i);
    }
    *(L+n1)=10000000000;
    *(R+n2)=10000000000;

    i=0; j=0;
    for(k=left;k<right;k++){
        if(*(L+i)<=*(R+j)){
            *(S+k)=*(L+i);
            i=i+1;
            count++;
        }
        else{
            *(S+k)=*(R+j);
            j=j+1;
            count++;
        }
    }
    free(L);
    free(R);
    return count;
}

int mergeSort(int *S, int left,int right,int count){
    int mid;
    if((left+1)<right){
        mid=(left+right)/2;
        count=mergeSort(S,left,mid,count);
        count=mergeSort(S,mid,right,count);
        count=merge(S,left,mid,right,count);
    }
    return count;
}
int main(void){
    int n,*S,i,count=0;
    scanf("%d",&n);
    S=malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        scanf("%d",(S+i));
    }
    count=mergeSort(S,0,n,count);
    for(i=0;i<n-1;i++){
        printf("%d ",*(S+i));
    }
    printf("%d\n",*(S+i));
    printf("%d\n",count);
    free(S);
    return 0;
}
