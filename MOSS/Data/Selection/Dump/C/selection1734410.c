#include <stdio.h>
#define N 100
int selection(int *,int );

int main(){
  int i,num=0,num2[N],new;
  scanf("%d",&num);
  for(i=0;i<num;i++){
    scanf("%d",&num2[i]);
  }
  new=selection(num2,num);
  for(i=0;i<num;i++){
    if(i<num-1) printf("%d ",num2[i]);
    else printf("%d\n",num2[i]);
  }
  printf("%d\n",new);
  return 0;
}

int selection(int *num2,int num){
  int i,minj,j,cnt=0,temp;
  for(i=0;i<=num-1;i++){
    minj=i;
    for(j=i;j<=num-1;j++){
      if(num2[j]<num2[minj]){
	minj=j;
      }
    }
    temp=num2[i];
    num2[i]=num2[minj];
    num2[minj]=temp;
    if(num2[i]!=num2[minj]) cnt++;
  }
  return cnt;
}
