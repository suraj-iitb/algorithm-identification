#include<stdio.h>
typedef struct card{
  char suit;
  int value;
  int id;
}card;
int partition(card *,int,int);
void quicksort(card *,int,int);
int main(){
  int i,n,p=0,v,sta=1;
  char s;
  scanf("%d",&n);
  int r=n-1;
  card A[n];
  for(i=0;i<n;i++){
    scanf(" %c %d",&s,&v);
    A[i].suit = s;
    A[i].value = v;
  	A[i].id=i;
  }
  quicksort(A,p,r);
	for(i=0;i<n;i++){
		if(A[i].value==A[i+1].value && A[i].id>A[i+1].id){
			sta=0;
			break;
		}
	}
  if(sta==1)printf("Stable\n");
  else printf("Not stable\n");
  for(i=0;i<n;i++){
    printf("%c %d\n",A[i].suit,A[i].value);
  }
  return 0;
}
void quicksort(card *A,int p,int r){
  if(p < r){
    int q = partition(A, p, r);
    quicksort(A, p, q-1);
    quicksort(A, q+1, r);
  }
}
int partition(card *A,int p,int r){
  int j;
  card temp;
  int x = A[r].value;
  int i = p-1;
  for(j = p;j<r;j++){
    if(A[j].value <= x){
      i++;
      temp = A[i];
      A[i] = A[j];
      A[j] = temp;
    }
  }
  temp = A[i+1];
  A[i+1] = A[r];
  A[r] = temp;
  return (i+1);
}
