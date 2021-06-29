#include<stdio.h>
#define  MAX 105
int A[MAX][MAX],T,B[MAX];
void alg(int t){
    int i,data[100],c=0,s=0;
    data[s]=t;
    s++; 
    while(1){
        if(c==s) break;
        t=data[c];
        c++;
        for(i=1;i<=T;i++){
            if(A[t][i]==1){
	            if(B[i]>=0)continue;
	            data[s]=i;
	            s++;
	            B[i]=B[t]+1;
            }
        }
    }
}
int main(){
  int i,j,k,n,u;
  scanf("%d",&T);
  for(i=0;i<T;i++){
    for(j=0;j<T;j++){
      A[i][j]=0;
    }
  }
  for(i=0;i<T;i++){
    scanf("%d%d",&u,&k);
    B[u]=-1;
    for(j=0;j<k;j++){
      scanf("%d",&n);
      A[u][n]=1;
    }
  }
  B[1]=0;
  alg(1);
  for(i=1;i<=T;i++){
    printf("%d %d\n",i,B[i]);
  }
  return 0;
}
