#include <stdio.h>

typedef struct {
  char Kind;
  int Number;
} Card;

Card card[100000],card2[100000];

void quickSort(int,int);
int partition(int,int);

int main(){
  int n,i,j,c=0,t1=0,t2=0;
  
  scanf("%d",&n);
  
  for(i=0; i < n; i++){
    scanf(" %c%d",&card[i].Kind,&card[i].Number);
    card2[i] = card[i];
  }
  
  quickSort(0,n-1);

   for(i=1; i < n; i++){
     if(card[i-1].Number == card[i].Number){
      for(j=0; j < n; j++){
	if(card[i-1].Kind == card2[j].Kind && card[i-1].Number == card2[j].Number){
	  t1 = j;
	}
	if(card[i].Kind == card2[j].Kind && card[i].Number == card2[j].Number){
	  t2 = j;
	}
      }
      if(t1 > t2){
	  c++;
	  break;
      }
    }
  }
  
  for(i=0; i < n; i++){
    if(c == 0 && i == 0){
      printf("Stable\n");
    } else if(i == 0){
      printf("Not stable\n");
    }
    printf("%c %d\n",card[i].Kind,card[i].Number);
  }
  
  return 0;
}

void quickSort(int p,int r){
  int q;
  if(p < r){
    q = partition(p,r);
    quickSort(p,q-1);
    quickSort(q+1,r);
  }
}

int partition(int p,int r){
  Card C,c;
  int i=0,j=0;
  C.Number = card[r].Number;
  C.Kind = card[r].Number;
  i = p-1;
  for(j=p; j < r; j++){
    if(card[j].Number <= C.Number){
      i = i+1;
      c = card[i];
      card[i] = card[j];
      card[j] = c;
    }
  }
  c = card[i+1];
  card[i+1] = card[r];
  card[r] = c;
  return i+1;    
}


