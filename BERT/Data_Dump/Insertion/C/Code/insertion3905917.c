#include<stdio.h>

void inserttionSort(int numbers[],int array_size){
  int i,j;
  for(i=1;i<array_size;i++){
    j=i;

    while((j>0)&&(numbers[j-1]>numbers[j])){
      int tmp;
      tmp =numbers[j-1];
      numbers[j-1]=numbers[j];
      numbers[j]=tmp;
      j--;

    }
    for(int k=0;k<array_size;k++){
    if(k!=array_size-1)printf("%d ",numbers[k]);
    else{printf("%d",numbers[k]);}
  }
  printf("\n");
  }

}
int main(void){
  int n;
  int A[100];
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  for(int p=0;p<n;p++){
    if(p!=n-1)printf("%d ",A[p]);
    else{printf("%d",A[p]);}
  }
  printf("\n");
  inserttionSort(A,n);


  return 0;
}

