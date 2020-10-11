#include <stdio.h>
#define N 100
void insert(int *,int);

int main(){
  int a[N],i,length,n,j;
  scanf("%d",&length);
  for(i=0;i<=length-1;i++){
    scanf("%d",&n);
    a[i]=n;
      }
  insert(a,length);
  
  return 0;
}

void insert(int a[],int l){
  int i,key,j,c;
      for(c=0;c<l-1;c++){
      printf("%d ",a[c]);
    }
      printf("%d\n",a[c]);
     
  for(i=1;i<=l-1;i++){
    key = a[i];
    j = i-1;
    while(j>=0&&key<a[j]){
      a[j+1]=a[j];
      j--;
      a[j+1]=key;
    }
    for(c=0;c<l-1;c++){
      printf("%d ",a[c]);
    }
    printf("%d\n",a[c]);
  } 
}

