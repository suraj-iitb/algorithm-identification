#include<stdio.h>
void SelectionSort(int *,int);
#define N 100 



main(){
  int i,A[N],n;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);
  SelectionSort(A,n);

  return 0;
}

void SelectionSort(int *a,int num){
  int i,j,temp,minj,con=0;
  for(i=0;i<num;i++){
    minj = i;
    for(j=i;j<num;j++) {
      if(a[j]<a[minj]){ 
	minj = j;

      }
    }
    if(i!=minj)	con++;
    temp=a[i];
    a[i] = a[minj];
      a[minj]=temp;
  }
  
  for(i=0;i<num-1;i++) printf("%d ",a[i]);
  printf("%d",a[num-1]);  
  printf("\n");  
  printf("%d\n",con);
}
