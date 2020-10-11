#include<stdio.h>

typedef struct{
  int num;
  char mark;
  int index;
}Card;

int partition(Card*,int,int);
void quicksort(Card*,int,int);

int main(){

  Card a[100000];
  int a_num,i,key,stability=0;

  //入力
  scanf("%d",&a_num);
  for(i = 0; i < a_num; i++){
    scanf(" %c %d",&a[i].mark,&a[i].num);
    a[i].index = i;
  }
  
  //ソート
  key = a[a_num-1].num;
  quicksort(a,0,a_num-1);
  for(i = 0; i < a_num-1; i++){
    if(a[i].num == a[i+1].num && a[i].index > a[i+1].index){
      stability=1;
    }
  }

  //出力
  if(stability == 0)printf("Stable\n");
  else if(stability == 1)printf("Not stable\n");
    for(i = 0; i < a_num; i++){
    printf("%c %d\n",a[i].mark,a[i].num);
  }
  
  return 0;
}



int partition(Card *a, int p, int last)
{
  int key,i,j;
  Card swap;

  key = a[last].num;
  i = p-1;


  for(j = p; j < last; j++){
    if(a[j].num <= key){
      i = i+1;
      swap = a[i];
      a[i] = a[j];
      a[j] = swap;
    }
  }
      swap = a[i+1];
      a[i+1] = a[last];
      a[last] = swap;

      return i+1;
}

void quicksort(Card *a, int p, int last){
  int q;

  if(p < last){
    q = partition(a,p,last);
    quicksort(a,p,q-1);
    quicksort(a,q+1,last);
  }
}
