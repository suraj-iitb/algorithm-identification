#include<stdio.h>

int n, data[101][100], v[101];

void visit(int x,int y){
  int i;
  if(v[x]==-1 || v[x]>y) v[x]=y;
  else return;
  for(i=0;data[x][i]!=0;i++) visit(data[x][i],y+1);
}

int main(){
  int i, j, a, b;


  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d %d",&a,&b);
    for(j=0;j<b;j++) scanf("%d",&data[a][j]);
    data[a][j]=0;
  }
 
  for(i=1;i<=n;i++)  v[i]=-1;

  visit(1,0);

  for(i=1;i<=n;i++) printf("%d %d\n",i,v[i]);  

  return 0;
}



