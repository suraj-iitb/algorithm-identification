#include<stdio.h>

#define MAX 101

int size[MAX],p[MAX],roll[MAX][MAX];
void GVE(int c,int v);

int main(){
  int i,j,n,m;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    p[i]=10000;
    for(j=1;j<=n;j++){
      roll[i][j]=0;
    }
  }
  for(i=1;i<=n;i++){
    scanf("%d",&m);
    scanf("%d",&size[m]);
    for(j=1;j<=size[m];j++){
      scanf("%d",&roll[m][j]);
    }
  }
  GVE(1,0);
  for(i=1;i<=n;i++){
    if(p[i]==10000){
      p[i]=-1;
    }
    printf("%d %d\n",i,p[i]);
  }
  return 0;
}

void GVE(int c,int v){
  int i;
  p[c]=v;
  for (i=1;i<=size[c];i++){
    if (p[roll[c][i]]>v){
      GVE(roll[c][i],v+1);
    }
  }
}

