#include<stdio.h>

void selectionSort(int *,int);

int main(){
  int a[100],n,i;

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&a[i]);

  selectionSort(a,n);

  return 0;
}
void selectionSort(int *a,int n){
  int i,j,minj,x,kazu=0;

  for(i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(a[j]<a[minj]){
	minj=j;
      }
    }
    if(a[i]!=a[minj]) kazu++;
    x=a[i];
    a[i]=a[minj];
    a[minj]=x;
  }
  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i!=n-1) printf(" ");
  }
  printf("\n%d\n",kazu);
}

