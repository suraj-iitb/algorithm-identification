#include<stdio.h>
#include<stdlib.h>

int *num;
int *res;

int c[200000];
#define MAX 10000


void countingsort(int);

int main(){
  int i,j;
  int n;

  scanf("%d",&n);
  
  num=malloc(sizeof(int)*(n+1));
  res=malloc(sizeof(int)*(n+1));
  
  for(i=0;i<n;i++){
    scanf("%d",&num[i]);
  }

  countingsort(n);
  for(j=1;j<=n;j++){
    if(j!=n) printf("%d ",res[j]);
    else printf("%d\n",res[j]);
  }
  
  free(num);
  free(res);
  
  return 0;
}

void countingsort(int n){
  int i,j;

  for(i=0;i<MAX;i++){
    c[i]=0;
  }
 
  for(j=0;j<n;j++){
    c[num[j]]++;
  }

  for(i=0;i<MAX;i++){
    c[i]=c[i]+c[i-1];
  }

  for(j=n;j>=0;j--){
    res[c[num[j]]]=num[j];
  c[num[j]]--;
  }
}
