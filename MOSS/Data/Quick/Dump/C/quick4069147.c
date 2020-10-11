#include<stdio.h>
#include<string.h>
#define N 100000

typedef struct {
  char mark;
  int num;
} TRP;

TRP CARD[N],store[N];

int patition(int p,int r){
  int i,j;
  TRP X,V;

  X = CARD[r];
  i = p - 1;
  for(j = p;j < r;j++){
    if(CARD[j].num <= X.num){
      i = i + 1;
      V = CARD[i];
      CARD[i] = CARD[j];
      CARD[j] = V;
    }
  }
  V = CARD[i+1];
  CARD[i+1] = CARD[r];
  CARD[r] = V;
  return i+1;
}

void QuickSort(int p,int r){
  int q;
  if(p < r){
    q = patition(p,r);
    QuickSort(p,q-1);
    QuickSort(q+1,r);
  }
}

void merge(int left,int mid,int right){
  int i,j,k,n1,n2;

  n1 = mid - left;
  n2 = right - mid;

  TRP L[n1],R[n2];

  for(i = 0;i < n1;i++) L[i] = store[left + i];
  for(i = 0;i < n2;i++) R[i] = store[mid + i];

  L[n1].num = R[n2].num = 1000000005;

  i = 0; j = 0;
  for(k = left;k < right;k++){
    if(L[i].num <= R[j].num){
      store[k] = L[i];
      i++;
    }
    else {
      store[k] = R[j];
      j++;
    }
  }
}

void mergeSort(int left,int right){
  int mid;
  if(left + 1 < right){
    mid = (left + right) / 2;
    mergeSort(left,mid);
    mergeSort(mid,right);
    merge(left,mid,right);
  }
}

int main(){
  int n,i,stable = 1;

  scanf("%d",&n);

  for(i = 0;i < n;i++){
     scanf("%s%d",&CARD[i].mark,&CARD[i].num);
     store[i] = CARD[i];
   }

  QuickSort(0,n-1);
  mergeSort(0,n);

  /*for(i = 0;i < n;i++){
    for(l = i+1;l < n;l++){
      if(CARD[i].num == CARD[l].num){
        same = 1;
        for(j = k;j < n;j++){
          if(CARD[i].num == store[j].num){
            for(k = j+1;k < n;k++){
              if(store[j].num == store[k].num){
                printf("%c %c %c %c\n",CARD[i].mark,store[j].mark,CARD[l].mark,store[k].mark);
                printf("%d %d %d %d\n",CARD[i].num,store[j].num,CARD[l].num,store[k].num);
                if(CARD[i].mark != store[j].mark || CARD[l].mark != store[k].mark){
                  flag = 1;
                }
                break;
              }
            }
            break;
          }
        }
        break;
      }
      else k = 0;
    }
  }
  if(same == 0 || flag == 0) printf("Stable\n");
  else printf("Not stable\n");
  */

  for(i = 0;i < n;i++){
    if(CARD[i].mark != store[i].mark) stable = 0;
  }

  if(stable) printf("Stable\n");
  else printf("Not stable\n");

  for(i = 0;i < n;i++) printf("%c %d\n",CARD[i].mark,CARD[i].num);

  return 0;
}

