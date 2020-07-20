#include<stdio.h>

int bubbleSort(int ,int *);

int main(){
    int n,cnt;
    scanf("%d",&n);
    int i,h[n];
    for(i=0;i<n;i++)scanf("%d",&h[i]);
    cnt=bubbleSort(n,&h[0]);
    for(i=0;i<n;i++){
        if(i!=n-1)printf("%d ",h[i]);
        else printf("%d\n",h[i]);
    }
    printf("%d\n",cnt);
    return 0;
}

int bubbleSort(int n,int *A){
  int i,cnt=0,j;
  for(i=0;i<n-1;i++){
        for (j=n-1;j>=i+1;j--){
            if (A[j] < A[j-1]){
                int tmp = A[j];
                A[j]=A[j-1];
                A[j-1]=tmp;
                cnt++;
            }
        }
    }
    return cnt;
}


