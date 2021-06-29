#include<stdio.h>
void bubblesort(int num[], int array_size){
  int flag,counter,i,j,temp;
  counter=0;
  flag=1;
  while(flag==1){
    flag=0;
    for(i=array_size-1;i>0;i--){
      if(num[i]<num[i-1]){
        temp=num[i];
        num[i]=num[i-1];
        num[i-1]=temp;
        flag = 1;
        counter++;
      }
    }
  }
  for(j=0;j<array_size;j++){
    if(j>0)printf(" ");
    printf("%d", num[j]);
  }
  printf("\n%d\n",counter);
}

int main(){
  int i,j,n;
  scanf("%d",&n);
  int A[n];
  for(i=0;i<n;i++){
    scanf("%d", &A[i]);
  }
  bubblesort(A,n);
  return 0;
}
