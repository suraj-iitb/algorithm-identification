#include <stdio.h>
#include <stdlib.h>

void countingSort(int *a,int *b,int n,int k){
  int i,j;
  int c[k+1];
  for(i=0;i<=k;i++)c[i]=0;
  for(j=1;j<=n;j++)c[a[j]]++;
  for(i=1;i<=k;i++)c[i]=c[i]+c[i-1];
  for(j=n;j>=1;j--){
    b[c[a[j]]]=a[j];
    c[a[j]]--;
  }
}

int main(){
  int i,n,max=0;
  int *ar1,*ar2,*a,*b;
  
  scanf("%d",&n);
  ar1=(int *)malloc(n*sizeof(int)+1);
  ar2=(int *)malloc(n*sizeof(int)+1);
  a=ar1;
  b=ar2;

  for(i=1;i<n+1;i++){
    scanf("%d",a+i);
    if(*(a+i)>max)max=*(a+i);
  }
  countingSort(a,b,n,max);

  for(i=1;i<n;i++)printf("%d ",*(b+i));
  printf("%d\n",*(b+i));
  free(ar1);
  free(ar2);
  return 0;
}
