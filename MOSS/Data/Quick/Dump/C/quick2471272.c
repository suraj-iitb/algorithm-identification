#include<stdio.h>
typedef struct{
  int A;
  char B;
  int No;
}cards;
 
cards card[100000];
 
int partition(int, int);
void quickSort(int, int);
int stateJudge(int);
main(){
  int k, r, mid, p = 0;
  int i;
 
  scanf("%d", &k );
 
  for(i = 0; i < k; i++){
 
    scanf("%s%d",&card[i].B, &card[i].A);
 
    card[i].No = i;
     
    // printf("%c %d", card[q].B, card[q].A);
     
  }
   
   
  r = k - 1;
   
   
  quickSort(p, r);
   
  if( stateJudge(r) == 1 )printf("Stable\n");
  else printf("Not stable\n");
 
   
  for(i = 0; i < k; i++){
     
    printf("%c %d\n", card[i].B, card[i].A);
   
  }
   
  return 0;
   
}
 
 
int partition(int p, int r){
   
  int i = 0 , j;
  cards ch;
  i = p;
   
  for(j = p; j < r; j++){
    // printf("%d\n",i);
    if(card[j].A <= card[r].A ){
       
      ch = card[i];
      card[i] = card[j];
    card[j] = ch;
    i++;
     
    } 
  }
  ch = card[r];
  card[r] = card[i];
  card[i] = ch;
  //  printf("%d\n",i);
  return i;
   
}
 
 
void quickSort(int p, int r){
  int q;
  if(p < r){q = partition(p, r);
    //    printf("%c %d\n", card[q].B, card[q].A);
    quickSort(p, q-1) ;
     
    quickSort(q+1, r);
     
  }
}
 
int stateJudge(int r){
  int i;
  for(i = 0; i < r; i++){
     
    if(card[i].A == card[i+1].A){
       
      if(card[i].No > card[i+1].No)
    {
      return 0;
    }   
    }
  }
 return 1;
}
