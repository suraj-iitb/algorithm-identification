#include <stdio.h>
int n,i,j,a[100],b,c=0,minj;
int main () {

  scanf("%d",&n);
  for (i=0;i<n;i++)
     scanf("%d",&a[i]);



  for (i=0;i<n;i++){
    minj = i;
    for (j=i;j<n;j++){
      if( a[j] < a[minj]){
	minj = j;
      }
    }
    if(a[i]!=a[minj]){
    b=a[i];
    a[i]=a[minj];
    a[minj]=b;
    c++;
  }
  }
     

 
  for (i=0;i<n;i++){
     printf("%d",a[i]);
     if (i<n-1)
       printf(" ");
  }
  printf("\n%d\n",c);
  return 0;
}

