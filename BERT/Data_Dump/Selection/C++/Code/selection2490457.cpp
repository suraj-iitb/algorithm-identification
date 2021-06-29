#include <iostream>
#include <cstdio> 
using namespace std;

int main(){
  int n,i,j,mini,tmp,count,swapped;
  scanf("%d",&n);
  int a[n];
  for(i=0; i<n; i++){
    scanf("%d",&a[i]);
  }
  swapped =0;
  count = 0;
  for(i=0; i<n; i++){
    mini = i;
    for(j=i; j<n; j++){
      if(a[mini]>a[j]){
        mini = j;
        swapped = 1;
      }
    }
      tmp = a[i];
      a[i] = a[mini];
      a[mini] = tmp;
      count += swapped;
      swapped = 0;
  }

  for(i=0; i<n; i++){
    printf("%d",a[i]);
    if(i!=n-1){
      printf(" ");
    }else{
      printf("\n");
    }
  }

  printf("%d\n",count);
  return 0;
}
