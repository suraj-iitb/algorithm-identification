#include <stdio.h>
#define M 2000005

int n,s[M],t[M];
void CountingSort(void);
  
int main(){
  int i;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&s[i+1]);
  }
  CountingSort();
  for(i=1;i<n;i++){
    printf("%d ",t[i]);
 }
  printf("%d\n",t[n]);



  return 0;
}
void CountingSort(void){
  int i,j,C[M];
  for(i=0;i<M;i++){
   C[i]=0;
  }
  for(j=1;j<=n;j++){

    C[s[j]]++;
  }
  for(i=1;i<=M;i++){
    C[i]=C[i]+C[i-1];
  } 
  for(j=n;j>=1;j--){
    t[C[s[j]]]=s[j];
    C[s[j]]--;
  }
}

