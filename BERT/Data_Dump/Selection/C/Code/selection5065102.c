#include <stdio.h>
#include <stdlib.h>

int n,count=0;
int * sort2(int *);

int main(){

  int i,*a,*b;

  scanf("%d",&n);
  a=(int *)malloc(n*sizeof(int));
  b=(int *)malloc(n*sizeof(int));

  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  b=sort2(a);

  for(i=0;i<n;i++){
    if(i!=n-1) printf("%d ",b[i]);
    else {
      printf("%d\n",b[i]);
      printf("%d\n",count);
    }
  }
  return 0;
}
int *sort2(int *a){
  int c,i,j,minj;
  for(i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(a[j]<a[minj])minj=j;
    }
    if(minj!=i){
    c=a[i];
    a[i]=a[minj];
    a[minj]=c;
    count++;
  }
  }
  return a;
}

