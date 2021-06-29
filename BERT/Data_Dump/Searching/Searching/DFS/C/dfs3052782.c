#include<stdio.h>
#define max 101
void depth(int);
int n,count=1,m[max][max],d[max],H[max],S[max];
int main(){
  int i,j,k,u,v;
  scanf("%d",&n);
  d[0]=0;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      m[i][j]=0;
    }
  }
  for(i=0;i<n;i++){
    scanf("%d %d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      m[u-1][v-1]=1;
    }
  }
  for(i=0;i<n;i++){
    if(d[i]==0){
      depth(i);
    }
  }
  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,H[i],S[i]);
  }
  return 0;
}

void depth(int q){
  int p;
  H[q]=count++;
  d[q]=1;
  for(p=0;p<n;p++){
    if(m[q][p]==1 && d[p]==0){
      depth(p);
    }
  }
  S[q]=count++;
}

