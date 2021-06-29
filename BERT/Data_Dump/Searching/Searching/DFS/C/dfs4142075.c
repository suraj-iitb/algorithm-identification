#include <stdio.h>

#define N 100
#define A 0
#define B 1
#define C 2

int D[N][N],E[N],a[N],b[N];
int c,n;

void X(int z);
void Y();

int main(){
  
  int z,v,w,i,j;

  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    
    for(j=0;j<n;j++)
      
      D[i][j]=0;
    
  }

  for(i=0;i<n;i++){
    
    scanf("%d %d",&z,&w);
    
    z--;
    
    for(j=0;j<w;j++){
      
      scanf("%d",&v);

      v--;
      
      D[z][v]=1;
    }
  }

  Y();

  return 0;
}

void X(int z){
  
  int i;
  
  E[z]=B;
  
  a[z]=++c;
  
  for(i=0;i<n;i++){
    
    if(D[z][i]==0)
      continue;
    
    if(E[i]==A){
      
      X(i);
    }
  }
  E[z]=C;
  b[z]=++c;
}

void Y(){
  
  int z;
  
  for(z=0;z<n;z++)
    
    E[z]=A;
  
  c=0;

  for(z=0;z<n;z++){
    
    if(E[z]==A)
      
      X(z);
  }
  for(z=0;z<n;z++){
    
    printf("%d %d %d\n",z+1,a[z],b[z]);
    
  }
}


