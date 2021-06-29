#include <stdio.h>

void x(int*,int);
void y(int*,int);

int main(){
  int i,a[1000],n;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  x(a,n);
  y(a,n);

  return 0;
}

void x(int *a,int n){
  int i;

  for(i=0;i<n;i++){
    if(i>0) printf(" ");
    printf("%d",a[i]);
  }
  printf("\n");
}

void y(int *a,int n){
  int i,j,key;
  for(i=1;i<n;i++){
    key=a[i];
    j=i-1;
    while(j>=0 && a[j]>key){
    a[j+1]=a[j];
    j--;
    }
    a[j+1]=key;
    x(a,n);
  }
}

