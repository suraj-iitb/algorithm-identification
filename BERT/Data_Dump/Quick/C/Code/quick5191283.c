#include <stdio.h>
#include <stdlib.h>

#define STABLE 1
#define NSTABLE -1

typedef struct{
  char c;
  int value;
  int n;
}card;

int Partition(card *, int, int);
void quickSort(card *, int, int);
int judge(card *, int);
void change(card *, int, int);

int main(){
  int j;
  int num, res, v;
  char c[2];
  card s[100001];
  scanf("%d", &num);
  for(j=0; j<num; j++){
    scanf("%s", c);
    scanf("%d", &v);
    s[j].c = c[0];
    s[j].value = v;
    s[j].n = j;
  }
  quickSort(s, 0, num-1);
  res = judge(s, num);
  if(res == STABLE)
    printf("Stable\n");
  else
    printf("Not stable\n");
  for(j=0; j<num; j++){
    printf("%c %d\n", s[j].c, s[j].value);
  }

  return 0;
}

int judge(card s[], int num){
  int i, res=STABLE;
  for(i=0; i<num-1; i++){
    if(s[i].value == s[i+1].value && s[i].n > s[i+1].n){
        res = NSTABLE;
        break;
      }
  }
  return res;
}

void change(card s[], int i, int j){
  card temp;
  temp = s[i];
  s[i] = s[j];
  s[j] = temp;
}

int Partition(card s[], int l, int r){
  int i, j, x;
  x = s[r].value;
  i = l - 1;
  for(j=l; j<r; j++){
    if(s[j].value <= x){
     i = i + 1;
     change(s, i, j);
   }
  }
  change(s, i+1, r);
  return i+1;
}

void quickSort(card s[], int l, int r){
  int q;
  if(l < r){
    q = Partition(s, l, r);
    quickSort(s, l, q-1);
    quickSort(s, q+1, r);
  }
}

