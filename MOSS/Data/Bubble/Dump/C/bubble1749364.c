#include<stdio.h>
#include<stdlib.h>

int main(){

  int n,*a,kaisu=0,temp;
  int i,j;

  scanf("%d",&n);

  a=(int *)malloc(sizeof(int)*n);

  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  for(i=0;i<n-1;i++){
    for(j=n-1;j>i;j--){
      if(a[j]<a[j-1]){
	temp=a[j];
	a[j]=a[j-1];
	a[j-1]=temp;
	kaisu++;
      }
    }
  }

  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i!=n-1)printf(" ");
  }
  printf("\n%d\n",kaisu);

  free(a);

  return 0;

}
