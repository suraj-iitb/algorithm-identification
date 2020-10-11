#include <stdio.h>

#define MAX 100

int selection(int *,int);

int main(){
  int i,j;
  int seq[MAX],len,cnt=0,temp,num;

  scanf("%d",&len);
  for(i=0;i<len;i++) scanf("%d",&seq[i]);

  /* for(i=0;i<len;i++){
    num=i;
    for(j=i+1;j<len;j++){
      if(seq[num]>seq[j]){
	num=j;
      }
    }
    temp=seq[num];
    seq[num]=seq[i];
    seq[i]=temp;
    if(seq[i]!=seq[num]) cnt++;
    }*/

  cnt=selection(seq,len);

  for(i=0;i<len-1;i++) printf("%d ",seq[i]);
  printf("%d\n",seq[i]);
  printf("%d\n",cnt);
  
  return 0;
}

//kannsuuka
int selection(int *seq,int len){
  int cnt=0,min,temp;
  int i,j;

  for(i=0;i<len-1;i++){
    min=i;
    for(j=i;j<len;j++){
      if(seq[j]<seq[min]) min=j;
    }
    temp=seq[i];
    seq[i]=seq[min];
    seq[min]=temp;
    if(min!=i)cnt++;
  }
  return cnt;
}



