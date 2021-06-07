#include<stdio.h>
#include<string.h>
int main(){
  int n,i,j,a[101][101],m,l,stack[100],stamp[101][2],now,time=1,flag,start;
  scanf("%d",&n);
  for(i=1;i<=n;i++) for(j=1;j<=n;j++){
      a[i][j]=0;
      stack[j]=-1;
      stamp[j][0]=-1;
      stamp[j][1]=-1;
    }
  for(i=1;i<=n;i++){
    scanf("%d %d",&j,&m);

    for(j=1;j<=m;j++){
      scanf("%d",&l);
      a[i][l]=1;
    }
  }
  start=1;
  now=1;
  j=0;
  while(1){
    if(stamp[start][1] != -1){
      flag=0;
      for(i=2;i<=n;i++){
	if(stamp[i][0] == -1){
	  start=i;
	  now=i;
	  flag=1;
	  break;
	}
      }
      if(flag==0) break; 
    }
    flag=0;
    if(stamp[now][0] == -1){
      stamp[now][0]=time;
      time++;
    }
    
    if(stamp[now][1] == -1){
      stack[j]=now;
      j++;
    }
    /*
    printf("now=%d[%d] time=%d stacks =",now,stamp[now][0],time);
    for(i=0;i<j;i++) printf(" %d",stack[i]);
    printf("\n");
    */
    for(i=1;i<=n;i++){
      if(a[now][i]==1 && stamp[i][0] == -1){
	now=i;
	flag=1;
	break;
      }
    }
    if(flag==1) continue;
    stamp[now][1]=time;
    time++;
    j--;
    if(stack[j] == now) j--;
    now=stack[j];

  }
  for(i=1;i<=n;i++){
    printf("%d %d %d\n",i,stamp[i][0],stamp[i][1]);
  }
}

