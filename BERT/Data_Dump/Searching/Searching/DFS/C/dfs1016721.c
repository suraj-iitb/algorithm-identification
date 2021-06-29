#include<stdio.h>
#define M 150
int u[M][M],s[M],t;
int tim,where[M];
int ans[M][2];
int visit[M];


int end(int n){
  int a=1,i;

  for(i=1;i<=n;i++){
    if(visit[i]==0)return i;
  }

  return 0;
} 



void push(int a){
  tim++;
  s[t++]=a;
  visit[a]=1;
}
int pop(){
  tim++;
  return s[t--];
}



int main(){
  int a,b,c,d,i,j,k,n;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d%d",&a,&b);
    for(j=0;j<b;j++){
      scanf("%d",&c);
      u[a][c]=1;
    }
  }
  i=1;
  j=1;
  push(i);
  ans[i][0]=tim;
  while(t>0){

    if(u[s[t-1]][j]==1&&visit[j]==0){
      push(j);
      where[s[t-2]]=j;
      if(ans[s[t-1]][0]==0)ans[s[t-1]][0]=tim;
      j=1;
    }
    j++;
    if(j>n){ 
      pop();
      ans[s[t]][1]=tim;
      j=where[s[t-1]];
 if(  t==0 && (end(n)>0) ){  
       push(end(n));
       ans[s[t-1]][0]=tim; 
     } 
    
    }

    
  }

  for(i=1;i<=n;i++){
    printf("%d %d %d\n",i,ans[i][0],ans[i][1]);

  }













  return 0;
}
