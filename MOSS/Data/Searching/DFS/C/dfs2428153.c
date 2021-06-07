#include <stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2
int n,a[100][100];
int d[100];
int f[100];
int color[100];
int t;

void getnumber(int i){
  int k;
  color[i]=GRAY;
  d[i]=++t;
  for(k=0;k<n;k++){
    if(a[i][k]==0){
      continue;
    }
    if(color[k]==WHITE){
      getnumber(k);
    }
  }
  color[i]=BLACK;
  f[i]=++t;
}
void find(){
  int i;
  for(i=0;i<n;i++){
    color[i]=WHITE;
    t=0;
  }
  for(i=0;i<n;i++){
    if(color[i]==WHITE){
      getnumber(i);
    }
  }
  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
}

int main(int argc, char const *argv[]) {
  int k,i,j,number,dimention,element;

  int d[100];
  int f[100];
  int color[100];
  scanf("%d",&n);
  for(i=0;i<100;i++){
    for(j=0;j<100;j++){
      a[i][j]=0;
    }
  }
  for(i=0;i<n;i++){
    scanf("%d %d",&number,&dimention);
    for(j=0;j<dimention;j++){
      scanf("%d",&element);
      a[number-1][element-1]=1;
    }
  }
  /*for(i=0;i<n;i++){
    color[i]=WHITE;
  }
  t=0;
  for(i=0;i<100;i++){
    if(color[i]==WHITE){
      visit(i);
    }
  }*/
  /*for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      printf("%d ",a[i][j]);
    }
    printf("\n");
  }
*/
  find();
  return 0;
}




/*void visit(r){
  S.push(r);
  color[r]= GRAY;
  d[r]=++t;
  while(S)
}*/
