#include<stdio.h>
int search(int);
int n;
int l[10000];
int main(){
  int i;
  int q;
  int q_n;
  int result=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&l[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&q_n);
    result+=search(q_n);
  }
  printf("%d\n",result);
  return 0;
}
int search(int x){
  int i;
  int flag=0;
  for(i=0;i<n;i++)if(x==l[i]){
      flag=1;
      break;
    }
  return flag;
}

