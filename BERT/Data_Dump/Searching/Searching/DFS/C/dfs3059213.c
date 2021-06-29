#include<stdio.h>
#define MAX 101
void depth(int);
int n,co=1,a[MAX][MAX],b[MAX],c[MAX],d[MAX];
int main(){
  int i,j,k,u,v;
scanf("%d",&n);
b[0]=0;
for(i=0;i<n;i++){
  for(j=0;j<n;j++){
    a[i][j]=0;
  }
 }
for(i=0;i<n;i++){
  scanf("%d%d",&u,&k);
  for(j=0;j<k;j++){
    scanf("%d",&v);
    a[u-1][v-1]=1;
  }
 }
for(i=0;i<n;i++){
  if(b[i]==0){
    depth(i);
  }
 }
for(i=0;i<n;i++){
  printf("%d %d %d\n",i+1,c[i],d[i]);
 }
return 0;
}
void depth(int q){
  int p;
  c[q]=co++;
  b[q]=1;
  for(p=0;p<n;p++){
    if(a[q][p]==1 && b[p]==0){
      depth(p);
    }
  }
  d[q]=co++;
}
    

