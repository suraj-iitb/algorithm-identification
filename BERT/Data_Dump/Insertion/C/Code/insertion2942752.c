#include <stdio.h>
#define N 100

int main(){
  int i,h,s,j,r;
  int A[N];
  int tmp,num;
  scanf("%d",&num);
  for(s=0;s<num;s++){
    scanf("%d",&A[s]);
  }
  for(i=1;i<num;i++){
    for(h=0;h<num-1;h++){
      printf("%d ",A[h]);
    }
    printf("%d\n",A[num-1]);
    tmp=A[i];
    j=i;
    while(0<j && tmp<A[j-1]){
      A[j]=A[j-1];
      j--;
    }
    A[j]=tmp;
  }
  for(r=0;r<num-1;r++){
    printf("%d ",A[r]);
  }
  printf("%d\n",A[num-1]);
  return 0;
}

