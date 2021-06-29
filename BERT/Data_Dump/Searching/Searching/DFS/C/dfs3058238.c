#include<stdio.h>

void fuka(int);

int n;
int cnt=1;
int a[101][101],b[101],c[101],d[101];
int main(){
  int i,j,x,y,z;
  scanf("%d",&n);
  b[0]=0;
  for(i=0;i<n;i++){
    scanf("%d%d",&x,&y);
    for(j=0;j<y;j++){
      scanf("%d",&z);
      a[x-1][z-1]=1;
    }
  }

  for(i=0;i<n;i++){
    if(b[i]==0)fuka(i);
  }

  for(i=0;i<n;i++)printf("%d %d %d\n",i+1,c[i],d[i]);
  
  return 0;
}

void fuka(int x){
  int i;
  c[x]=cnt;
  cnt++;
  b[x]=1;
  for(i=0;i<n;i++){
    if(a[x][i]==1 && b[i]==0)fuka(i);
  }
  d[x]=cnt;
  cnt++;
}

