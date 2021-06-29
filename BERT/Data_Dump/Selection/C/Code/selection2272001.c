#include <stdio.h>

void selectionSort(int *,int);

int main(){
  int N,A[100],i;

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  selectionSort(A,N);

  return 0;

}
void selectionSort(int *a,int n)
{
  int i,j,k,num=0,minj=0,count=0;
  for(i=0;i<n;i++){
    minj = i;
    for(j=i;j<n;j++){
      if(a[j]<a[minj]){
	minj=j;
      }
    }
    if(minj!=i){
	num=a[i];
	a[i]=a[minj];
	a[minj]=num;
       count++;
      }
  }
  for(k=0;k<n;k++){
      printf("%d",a[k]);
      if(k!=n-1)printf(" ");
      }
    printf("\n");
    printf("%d\n",count);
}
