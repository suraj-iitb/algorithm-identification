#include <iostream>
#include <cstdio> 
using namespace std;

int main(){
  int n,i,j;
  scanf("%d",&n);
  int a[n],tmp,count;
  for(i=0; i<n; i++){
    scanf("%d",&a[i]);
  }

  count=0;

  for(i=0; i<n-1; i++){
    for(j=n-1; j>i; j--){
      if(a[j-1] > a[j]){
        tmp = a[j];
        a[j] = a[j-1];
        a[j-1] = tmp;
        count += 1;
      }
    }
  }
  for(i=0; i<n; i++){
    printf("%d",a[i]);
    if(i!=n-1){
      printf(" ");
    }else if(i==n-1){
      printf("\n");
    }
  }
  printf("%d\n",count);
}
