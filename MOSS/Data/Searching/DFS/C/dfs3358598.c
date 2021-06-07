#include <stdio.h>
#define N 100
int n;
int t=0;
int a[N][N],b[N],c[N],d[N];
void set(int );
void inp(int );
void cal(int );
int main(){
  int i,j;
  scanf("%d",&n);
  set(n);
  inp(n);
  for(i=0;i<n;i++){
    if(d[i]==0){
       cal(i);
     }
   }
  for(i=0;i<n;i++){
   printf("%d %d %d\n",i+1,b[i],c[i]);
 }
  return 0;
}

void set(int x){
    int i,j;
    for(i=0;i<x;i++){
        d[i]=0;
        for(j=0;j<x;j++){
          a[i][j]=0;
        }
    }
}

void inp(int x){
    int i,j,k,l,m;
    for(i=0;i<x;i++){
        scanf("%d%d",&k,&l);
        for(j=0;j<l;j++){
          scanf("%d",&m);
          a[k-1][m-1]=1;
        }
    }
}
void cal(int x){
  int i,j;
  d[x]=1;
  b[x]= ++t;
  for(i=0;i<n;i++){
    if(a[x][i]==1 && d[i]==0){
    cal(i);
  d[x]=2;
}
}
  c[x]= ++t;
}

