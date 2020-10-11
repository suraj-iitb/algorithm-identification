#include<stdio.h>
int main(){
  int n;
  int a[100];
  int count=0;
  int i;
  int j;
  int tmp;
  
  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    scanf(" %d",&a[i]);
  }

  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(a[j] < a[j-1]){
	tmp = a[j];
	a[j] = a[j-1];
	a[j-1] = tmp;
	count++;
      }
    }
  }
  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i != n-1) printf(" ");
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}

