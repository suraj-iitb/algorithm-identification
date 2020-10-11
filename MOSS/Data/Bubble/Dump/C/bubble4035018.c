#include <stdio.h>

int Bubblesort(int *,int);
void swap (int *,int *);
  
int main()
{
  int i,n,a[100],b;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  b=Bubblesort(a,n);
  
  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i<n-1){
      printf(" ");
    }
  }
    printf("\n");
  printf("%d\n",b);
  
  return 0;
  
}

void swap(int *x,int *y){
  int temp;

  temp=*x;
  *x=*y;
  *y=temp;
}

int Bubblesort(int *a, int n){

  int i,j,count=0;

  for(i=0;i<n-1;i++){
    for(j=n-1;j>=i+1;j--){
      if(a[j]<a[j-1]){
	swap(&a[j],&a[j-1]);
	count++;
      }
    }
  }
  return count;
}
  

