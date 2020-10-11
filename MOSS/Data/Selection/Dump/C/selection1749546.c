#include<stdio.h>
#include<stdlib.h>

int selectionSort(int*,int);

int main(){

  int n,*a,kaisu;
  int i,j;

  scanf("%d",&n);

  a=(int *)malloc(sizeof(int)*n);

  for(i=0;i<n;i++)scanf("%d",&a[i]);

  kaisu=selectionSort(a,n);

  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i!=n-1)printf(" ");
  }
  printf("\n%d\n",kaisu);

  free(a);

  return 0;

}

int selectionSort(int *a,int n){

  int i,j,minj,temp,kaisu=0;
  for(i=0;i<n-1;i++){
    minj=i;
    for(j=i+1;j<n;j++){
      if(a[j]<a[minj]){
	minj=j;
      }
    }
    if(i!=minj){
      temp=a[i];
      a[i]=a[minj];
      a[minj]=temp;
      kaisu++;
    }
  }

  return kaisu;
}
