#include<stdio.h>
#define N 100
int main(){
  int n,i,j,mini,count=0,l,A[N];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<=n-1;i++){
    mini=i;
    for(j=i;j<=n-1;j++){
      if(A[j]<A[mini]){
        mini=j;
      }
    }
      if(i != mini){
        count++;
        l=A[i];
        A[i]=A[mini];
        A[mini]=l;
      }
    }

    for(i=0;i<n-1;i++){
      printf("%d ",A[i]);

        }
    printf("%d",A[n-1]);
    printf("\n");
    printf("%d\n",count);
    return 0;
}

