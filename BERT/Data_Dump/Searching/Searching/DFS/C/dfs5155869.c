#include <stdio.h>
#define N 200

int main(){
  int i,j,k,p,point,num,n,inc=0,q=0;
  int glaph[N][N],come[N],go[N],stack[N],flag[N],nextpoint[N];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d %d",&point,&num);
    for(j=0;j<num;j++){
      scanf("%d",&k);
      glaph[point-1][k-1]=1;
    }
  }
  for(i=0;i<n;i++){
    flag[i]=2;//not visit
    nextpoint[i]=0;
  }
  for(i=0;i<n;i++){
    if(flag[i]==2){
      flag[i]=3;//come
      come[i]=++inc;
      stack[++q]=i;
      while(q){
        for(p=nextpoint[stack[q]];p<n;p++){
          nextpoint[stack[q]]=p+1;
          if(glaph[stack[q]][p])break;
        }
        if(p!=n){
          if(flag[p]==2){
            flag[p]=3;
            come[p]=++inc;
            stack[++q]=p;
          }
        }else{
          flag[stack[q]]=4;//go
          go[stack[q]]=++inc;
          stack[q--]=0;
        }
      }
    }
  }
  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,come[i],go[i]);
  }
  return 0;
}

