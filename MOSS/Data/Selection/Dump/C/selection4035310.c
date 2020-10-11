#include <stdio.h>

int Selectionsort(int *, int);

int main(){
  int a[100],n,i,s;

   scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  s=Selectionsort(a,n);
  
  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i<n-1){
      printf(" ");
    }
  }
    printf("\n");
  printf("%d\n",s);
  
  return 0;
  
}

int Selectionsort(int *a, int n){

  int i,j,count=0,minj,t;

  for(i=0;i<n-1;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(a[j]<a[minj]){
	minj=j;
      }
    }
    t=a[i];
    a[i]=a[minj];
    a[minj]=t;
    if(i!=minj) count++;
  }
  return count;
}
  

