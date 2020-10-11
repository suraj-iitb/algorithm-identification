#include <stdio.h>

int num[110];
int bubblesort(int num[],int n){

  int i,j,tmp,count=0;
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(num[j]<num[j-1]){
        count++;
        tmp=num[j-1];
        num[j-1]=num[j];
        num[j]=tmp;
      }
    }
  }
  return count;
}

int main(){

  int i,n,ans;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&num[i]);
  }
  ans=bubblesort(num,n);
  for(i=0;i<n-1;i++) printf("%d ",num[i]);
  printf("%d\n%d\n",num[n-1],ans);
  return 0;
}
