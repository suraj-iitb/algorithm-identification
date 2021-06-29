#include <stdio.h>
#include <string.h>
#define MAX 100000

typedef struct card{
  char moji;
  int num,id;
} card;

int partition(card [],int,int);
void quickSort(card [],int,int);
int stable(card [],int);


int main(){
  
  int i,n,q;
  card cards[MAX];

  scanf("%d",&n);
  for(i=0;i<n;i++){
  	scanf("%s%d",&cards[i].moji,&cards[i].num);
  	cards[i].id = i;
  }

  	quickSort(cards,0,n-1);

  if(stable(cards,n))printf("Stable\n");
  else printf("Not stable\n");
  for(i=0;i<n-1;i++)printf("%c %d\n",cards[i].moji,cards[i].num);
  	printf("%c %d\n",cards[i].moji,cards[i].num);


  return 0;

}

void quickSort(card A[],int p,int r)
{
	int q;
	if(p<r){
		q=partition(A,p,r);
		quickSort(A,p,q-1);
		quickSort(A,q+1,r);
	}
}
int partition(card A[],int p,int r)
{
	int x,i,j;
	card temp;

	x = A[r].num;
  i =p - 1;

   for(j=p;j<r;j++){
    if(A[j].num <= x){ 
    	i = i+1;

      temp=A[i];
    A[i] = A[j];
    A[j] = temp;
    } 
  }

  temp = A[i+1];
  A[i+1] = A[r];
  A[r] = temp;

  return i+1;
}

int stable(card A[],int n)
{
	int i;
	for(i=0;i<n-1;i++){
		if(A[i].num==A[i+1].num&& A[i].id>A[i+1].id)return 0;
	}
	return 1;
}
