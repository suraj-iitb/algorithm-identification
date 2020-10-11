#include<stdio.h>

#include <stdlib.h>
int main(){
  int i,n,a[2000000],b[2000000],c[10000],count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    c[i]=0;
  }
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
    c[a[i]]++;
  }
  for(i=0;i<10000;i++){
    count +=c[i];
    c[i]=count;
  }
  
  
  for(i=n-1;i>=0;i--){
    b[c[a[i]]-1]=a[i];
    c[a[i]]--;
  }
  for(i=0;i<n;i++){
    printf("%d",b[i]);
    if(i!=n-1) printf(" ");
    else printf("\n");
  }
  return 0;
}

