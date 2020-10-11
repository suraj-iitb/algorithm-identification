#include<stdio.h>
#include<stdlib.h>

int main(){

  int i,j,minj,num,*A,cnt=0,temp;

  while(1){
    scanf("%d",&num);
    if(num>=1&&num<=100) break;
    }
  A = (int *)malloc(num * sizeof(int));
  for(i=0;i<num;i++){
    scanf("%d",&A[i]);
    if(A[i]<0||A[i]>100) break;
  }
  for(i=0;i<num-1;i++){
    minj = i;
    for(j=i;j<num;j++){
      if(A[j]<A[minj]) minj = j;         
    }
    if(A[i]==A[minj]) continue;
    temp = A[i];
    A[i] = A[minj];
    A[minj] = temp;
    cnt++;
    
    
  }
  for(i=0;i<num;i++){
    if(i==num-1) printf("%d",A[i]);
    else if(A[i]>9) printf("%-3d",A[i]);
    else  printf("%-2d",A[i]);
    }
  printf("\n");
  printf("%d\n",cnt);
  
  return 0;
}

