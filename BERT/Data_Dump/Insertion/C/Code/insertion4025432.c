#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *,int);

int main(){

  int i,k,n,cnt=0;
  int a[1000];

  scanf("%d",&n);
  if(n<0 || n>100){
    printf("nは範囲外\n");
    exit(1);
  }
  for(i=0;i<n;i++)
    if(scanf("%d",&a[i])==EOF) break;
  
  if(n>1000){
    printf("Aは範囲外\n");
    exit(2);
  }
  
  for(k=0;k<n-1;k++)
      printf("%d ",a[k]);
    printf("%d\n",a[k]);

  insertionSort(&a[0],n);
  
    
  return 0;

}

void insertionSort(int *a,int n)
{
  int i,j,k,v;
  
  for(i=1;i<n;i++){
    v = a[i];
    j = i-1;
    while(j>=0 && a[j] > v){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;

    for(k=0;k<n-1;k++)
      printf("%d ",a[k]);
    printf("%d\n",a[k]);
    
  }
}



