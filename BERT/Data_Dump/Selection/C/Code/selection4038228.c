#include<stdio.h>
#define N 100
int main(){
  int i,j,n,A[N],flag,a,b=0,m,minj,k;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }for(j=0;j<n;j++){
    minj=j;
    for(k=j;k<n ;k++){
      if(A[k]<A[minj]){
        minj=k;
      }
    }if(j!=minj){a=A[j];
    A[j]=A[minj];
    A[minj]=a;
    b++;
    }
  }for(m=0;m<n-1;m++){
    printf("%d",A[m]);
    printf(" ");
  }printf("%d\n",A[n-1]);
  printf("%d\n",b);
}

