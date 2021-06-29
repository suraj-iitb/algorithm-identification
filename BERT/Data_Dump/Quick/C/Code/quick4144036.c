#include <stdio.h>
#include <string.h>

#define M 100000

typedef struct{
  int value;
  char word[5];
  int mem;
}data;

int partition(data *,int,int);
void quickSort(data *,int,int);
int hantei(data *,data *,int);

int main(){
  data seq_ori[M],seq_qui[M];
  int len;
  int i;

  scanf("%d",&len);
  for(i=0;i<len;i++){
    scanf(" %s %d",seq_ori[i].word,&seq_ori[i].value);
    seq_ori[i].mem=i;
    seq_qui[i]=seq_ori[i];
  }
  
  quickSort(seq_qui,0,len-1);
  
  if(hantei(seq_qui,seq_ori,len)) printf("Stable\n");
  else printf("Not stable\n");

  for(i=0;i<len;i++) printf("%s %d\n",seq_qui[i].word,seq_qui[i].value);
  
  return 0;
}

int partition(data *A,int p,int r){
  int x;
  int i,j;
  data temp;
  
  x=A[r].value;
  i=p-1;
  for(j=p;j<r;j++){
    if (A[j].value <= x){
      i = i+1;
      //A[i] と A[j] を交換
      temp=A[i];
      A[i]=A[j];
      A[j]=temp;
    }
  }
  //A[i+1] と A[r] を交換
  temp=A[i+1];
  A[i+1]=A[r];
  A[r]=temp;
  
  return i+1;
}

void quickSort(data *seq_qui,int p ,int r){
  int q;
  if( p < r){
    q = partition(seq_qui, p, r);
    quickSort(seq_qui, p, q-1);
    quickSort(seq_qui, q+1, r);
  }
}

int hantei(data seq[],data seqo[],int len){
  int i,cnt=0;
  for(i=0;i<len;i++){
    if((seq[i].value == seq[i+1].value)
       && (seq[i].mem > seq[i+1].mem)) return 0;
    }
  //seq[i].word!=seqo[i].word ok
  return 1;
}


