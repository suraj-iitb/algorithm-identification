#include<stdio.h>
int main(){
  int a,b,i,j,flag=0;
  int aa[10000];
  int bb[500];
  int count=0,judge=0;
  scanf("%d",&a);
  for(i=0;i<a;i++){
    scanf("%d",&aa[i]);
  }
  scanf("%d",&b);
  for(i=0;i<b;i++){
    scanf("%d",&bb[i]);
    for(j=0;j<a;j++){
        if(aa[j]==bb[i]){
            judge=1;
            break;
        }
        else{
            judge=0;
        }
    }
            
    if(judge!=0){
      count++;
      flag=1;
      judge=0;
    }
  }
  if(flag==0){
    printf("0\n");
  }
  else{
    printf("%d\n",count);
  }
  return 0;
}

