#include<stdio.h>
struct Card{
  char suit;
  int value;
int key;
};
struct Card A[100001];
 
int Partition(int p,int r){
  int i,j;
  struct Card key,x;
   
  x=A[r];
  i=p-1;
   
  for(j=p;j<r;j++){
    if(A[j].value<=x.value){
      i=i+1;
      key=A[i];
      A[i]=A[j];
      A[j]=key;
    }
  }
   
  key=A[i+1];
  A[i+1]=A[r];
  A[r]=key;
   
  return i+1;
}
void Quicksort(int p,int r){
  int q;
  if(p<r){
    q = Partition(p, r);
    Quicksort(p,q-1);
    Quicksort(q+1,r);
  }
}
 
int main(){
  int n,i,j,count=0;
  char ch,ch2;
   
  scanf("%d%c",&n,&ch);
  for(i=1;i<=n;i++){    
    scanf("%c%c%d%c",&A[i].suit,&ch2,&A[i].value,&ch);
    A[i].key=i;   
  }
  
  
  Quicksort(1,n);
	
 for(i=1;i<n;i++){
 	if(A[i].value==A[i+1].value && A[i].key>A[i+1].key){
 		count=1;
 break;}
}
  if(count!=1) printf("Stable\n");
  else printf("Not stable\n");
   
  for(i=1;i<=n;i++) printf("%c %d\n",A[i].suit,A[i].value);
   
  return 0;
}
