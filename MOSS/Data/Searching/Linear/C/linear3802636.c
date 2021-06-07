#include<stdio.h>

int main(){
  int n1,n2,b,cnt=0;
  int i=0,j=0;
  int a[10010];
  scanf("%d",&n1);
  while(i!=n1){
    scanf("%d",&a[i]);
    i++;
  }
  scanf("%d",&n2);
  while(j!=n2){
    scanf("%d",&b);int k=0;
    while(k!=n1){
      if(a[k]==b){
        cnt++;break;
      }
      k++;
    }
    j++;
  }
  printf("%d\n",cnt);

}

