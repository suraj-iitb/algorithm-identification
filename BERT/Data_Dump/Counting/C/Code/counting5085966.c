#include <stdio.h>
#define N 2000000

void countingsort(int *,int *,int,int);

int main(){
  int i,n,a[N],b[N]={},k=0;

  scanf("%d",&n);
  for(i=1;i<n+1;i++){
    scanf("%d",&a[i]);
    if(k<a[i]) k=a[i];
  }
  countingsort(a,b,k,n);
  for(i=1;i<n+1;i++){
    if(i>=2) printf(" ");
    printf("%d",b[i]);
  }
  printf("\n");
  return 0;
}

void countingsort(int *a,int *b,int k,int n){
  int i,j,c[N]={};

  /*for(i=0;i<k+1;i++){
    c[i]=0;
    }*/
  for(j=1;j<n+1;j++){
    c[a[j]]++;
  }
  for(i=1;i<k+1;i++){
    c[i]=c[i]+c[i-1];
  }
  for(j=n+1;j>=1;j--){
    b[c[a[j]]]=a[j];
    c[a[j]]--;
  }
}
