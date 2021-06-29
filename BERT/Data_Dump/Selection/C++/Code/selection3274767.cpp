#include<stdio.h>

int selectionSort(int,int *);

int main(){
    int cnt,n;
    scanf("%d",&n);
    int i,h[n];
    for(i=0;i<n;i++)scanf("%d",&h[i]);
    cnt = selectionSort(n,&h[0]);
    for(i=0;i<n;i++){
        if(i!=n-1)printf("%d ",h[i]);
        else printf("%d\n",h[i]);
    }
    printf("%d\n",cnt);
    return 0;
}

int selectionSort(int n,int *A){
    int i,j,cnt=0;
    for(i=0;i<n;i++){
        int minj=i;
        for(j=i;j<n;j++){
            if(A[j]<A[minj]){
                minj=j;
            }
        }
        if(minj!=i){
        int tmp = A[minj];
        A[minj]= A[i];
        A[i]=tmp;
        cnt++;
        }
        }
    return cnt;
}


