#include <stdio.h>

int linearSearch(int *,int,int);

int main(){
  int i,n,data[10000],a,b,c=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&data[i]);
      }

  scanf("%d",&a);
  for(i=0;i<a;i++){
    scanf("%d",&b);
    if(linearSearch(data,n,b)){
      c++;
    }
  }
  printf("%d\n",c);

  return 0;
}

int linearSearch(int data[],int n,int b){
  int i=0;
  data[n]=b;
  while(data[i]!=b){
    i++;
  }
    return i!=n;
}

