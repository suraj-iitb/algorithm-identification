#include<stdio.h>
int selectionSort(int *,int);
int main(){
  int a[100];
  int i,j,tmp,minj,n,c=0;
  scanf("%d",&n);
  for(i=0;i<n;i++) {
    scanf("%d",&a[i]);
  }
  for(i = 0;i < n;i++) {
    minj = i;
    for(j = i;j < n;j++) {
      if(a[j] < a[minj]) {
	minj = j;
      }
    }
    if(i != minj){
      tmp = a[i];
      a[i] = a[minj];
      a[minj] = tmp;
      c++;
    }
  }
  for(i=0;i<n;i++) {
    if(i > 0) printf(" ");
    printf("%d",a[i]);
  }
  printf("\n");
  printf("%d\n",c);
 
  return 0;
}
 
