#include <stdio.h>

#define MAX 10000
int bubble(int *,int);

int main(){
  int seq[MAX],len,chk=1,temp;
  int i,cnt;


  scanf("%d",&len);
  for(i=0;i<len;i++) scanf("%d",&seq[i]);
  
  /*while(chk==1){
    chk=0;
    for(i=len-1;i>=1;--i){
      if(seq[i]<seq[i-1]){
	temp=seq[i];
	seq[i]=seq[i-1];
	seq[i-1]=temp;
	chk=1;
	cnt++;
      }
    }
  }
  */
  
  cnt=bubble(seq,len);
  
  for(i=0;i<len-1;i++) printf("%d ",seq[i]);
  printf("%d\n",seq[i]);
  printf("%d\n",cnt);
  
  return 0;
}
//kannsuuka
int bubble(int *A,int len){
  int i,chk,temp,cnt=0;

  chk=1;
  while(chk==1){
    chk=0;
    for(i=len-1;i>0;i--){
      if(A[i]<A[i-1]){
	temp=A[i];
	A[i]=A[i-1];
	A[i-1]=temp;
	chk=1;
	cnt++;
      }
    }     
  }
  return cnt;
}

