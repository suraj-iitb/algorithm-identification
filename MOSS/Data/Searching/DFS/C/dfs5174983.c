#include<stdio.h>

int A[101][101]={};
int d[100] = {}, f[100] = {};
int l = 0;

void ser();

int main(){
  
  int n,i,j,k,t,a;

  scanf("%d", &n);

  for(i = 0 ; i < n ; i++){
    scanf("%d%d",&k,&t);
    A[k][0] = 1;
    for(j = 0 ; j < t ; j++){
      scanf("%d",&a);
      A[k][a]=1;
    }
  }

  for(i = 1 ; i <= n ; i++ ){
    if(A[i][0] == 1){
      A[i][0] = 0;
      ser(i,n);
    }
  }

  for(i = 1 ; i <= n ; i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }

  return 0;
}

void ser(int a,int n){
  int i;

  
  
  d[a] = ++l;
  
  for(i = 1 ; i <= n ; i++){
    if(A[a][i] == 1 && A[i][0] == 1){
      A[i][0] = 0;
      ser(i,n);
    }
  }
  f[a] = ++l;

  
}
				    
      
  

