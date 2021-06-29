#include <stdio.h>
#define N 100
#define INFTY 100000000

int main(){
  int i,j,k,point,num,pre=0,n,head=0,tail=1,distance[N],Q[N],H[N][N];
  int glaph[N][N];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      glaph[i][j]=0;
    }
  }
  for(i=0;i<n;i++){
    scanf("%d %d",&point,&num);
    for(j=0;j<num;j++){
      scanf("%d",&k);
      glaph[point-1][k-1]=1;
    }
    if(i!=0)distance[i]=INFTY;
  }

  while(head!=tail){
    //printf("head=%d,tail=%d\n",head,tail);
    if(head!=0)pre=head;
    head++;
    /*for(i=head;i<=tail;i++){
      printf("%d ",Q[i]);
    }
    printf("pre is %d\n",pre);*/
    for(i=0;i<n;i++){
      //if(i==5)printf("i===================%d\n",i);
      //printf("head=%d,tail=%d,distance[%d]=%d,pre=%d\n",head,tail,i,distance[i],pre);
      if(/*glaph[i][pre]==1 ||*/glaph[pre][i]==1){
        if(distance[i]>=INFTY){
          tail++;
          Q[tail]=i;
          distance[i]=distance[pre]+1;
          H[pre][i]=i;
          //printf("H[%d]=%d\n",pre,i);
          //printf("1:distance[%d]=%d\n",i,distance[i]);
        }else if(distance[i]>distance[pre]+1){
          tail++;
          Q[tail]=i;
          distance[i]=distance[pre]+1;
          //printf("2:distance[%d]=%d\n",i,distance[i]);
          for(j=1;j<n;j++){
            //printf("H[%d]=%d\n",i,H[i]);
            //if(i==6)printf("-----------------------------------------H[6][%d]=%d\n",j,H[i][j]);
            if(H[i][j]==j &&distance[j]>distance[i]+1){
              distance[j]=distance[i]+1;
              //printf("again distance[%d]=%d\n",j,distance[j]);
              break;
            }

          }
        }
        H[pre][i]=i;
        //printf("H[%d][%d]=%d\n",pre,i,H[pre][i]);
      }
    }
  }

  //printf("1 0\n");
  for(i=0;i<n;i++){
    if(distance[i]>=INFTY)distance[i]=-1;
    printf("%d %d\n",i+1,distance[i]);
  }
  return 0;
}
