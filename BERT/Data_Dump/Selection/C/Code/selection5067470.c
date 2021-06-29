#include <stdio.h>
void selectionSort(int *,int );
int main(){
  int a[100],n,i;

  scanf("%d",&n);
  for (i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  selectionSort(a,n);
  return 0;
}

void selectionSort(int *a,int n){
  int i,j,minj,v,t=0;
  for(i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(a[j]<a[minj]){
	minj=j;
      }
    }
    if(i!=minj){
      v=a[i];
      a[i]=a[minj];
      a[minj]=v;
      t++;
    }
    
  }
  for(j=0;j<n-1;j++){
    printf("%d ",a[j]);
  }
  printf("%d\n%d\n",a[n-1],t);
}

