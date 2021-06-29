#include <stdio.h>
#define HEN 1
#define kuro 2
#define siro 0
#define gre 1
int A[100][100];
int n,z,iro[100],dd[100],ff[100];

void saikiDFS(int x){
  int a;
  iro[x]=gre;
  
  dd[x]=++z;

  for(a=0; a < n;a++){
    
    if(A[x][a]==0){
      continue;
    }

    if(iro[a]== siro){
      saikiDFS(a);
    }

  }
  iro[x]=kuro;
  ff[x]=++z;
  
}

void firstDFS(){
  int b;

  for(b=0; b < n; b++){
    iro[b]=siro;
  }
  z=0;//syokika

  for(b=0; b < n;b++){

    if(iro[b]==siro){
      saikiDFS(b);
    }
    
  }

  for(b=0; b< n;b++){

    printf("%d %d %d",b+1,dd[b],ff[b]);
    printf("\n");
  }

}


int main(){
  int i,j,k,l,m,c,d;
  
  scanf("%d",&n);

  for(i=0;i < n;i++){
    for(j=0;j < n; j++){
       A[i][j]=0;
    }
}
  
      for(i=0; i < n;i++){

    scanf("%d %d",&c,&d);
    c=c-1;

    for(j=0; j < d; j++){

      scanf("%d",&k);
      k=k-1;
      A[c][k]=HEN;
    }
  }

      firstDFS();
      return 0;

}

