#include <stdio.h>

int main(){
  int aaa[100],gyo,i,j,temp;

  scanf("%d",&gyo);

  for(i=0;i<gyo;i++){
    scanf("%d",&aaa[i]);
  }

  for(i=0;i<gyo;i++){
    for(j=i;0<j;j--){
      if(aaa[j-1]>aaa[j]){
	temp=aaa[j];
	aaa[j]=aaa[j-1];
	aaa[j-1]=temp;
      }
      else break;
    }

    for(j=0;j<gyo-1;j++){
      printf("%d ",aaa[j]);
    }
    printf("%d\n",aaa[gyo-1]);
  }

  return 0;
}

