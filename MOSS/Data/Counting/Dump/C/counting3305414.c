#include<stdio.h>
#include<stdlib.h>
#define MAX 2000000
#define VMAX 10000

int main(){
  int i,n,*a,*b,c[VMAX],sai=0;
  scanf("%d",&n);
  a=malloc(sizeof(int)*n);
  b=malloc(sizeof(int)*n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
    if(a[i]>sai){
      sai=a[i];
    }
  }

  //countingsort
  for(i=0;i<=sai;i++){
    c[i]=0;
  }
  for(i=0;i<n;i++){
    c[a[i]]++;
  }
  for(i=1;i<=sai;i++){
    c[i]+=c[i-1];
  }
  for(i=n-1;i>=0;i--){
    b[c[a[i]]]=a[i];
    c[a[i]]--;
  }
  for(i=1;i<=n;i++){
    printf("%d",b[i]);
    if(i==n){
      printf("\n");
    }else{
      printf(" ");
    }
  }
}
  
  

