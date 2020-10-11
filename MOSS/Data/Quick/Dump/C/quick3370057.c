#include<stdio.h>

#define MAX 100000
#define INFTY 1000000002

typedef struct node{
  int key;
  char type;
}Card;

int n;
Card trump1[MAX],trump2[MAX];
Card L[MAX/2+2],R[MAX/2+2];

void Merge(int l,int m,int r){
  int i,j,k;
  int na = m - l;
  int nb = r - m;

  for(i = 0; i < na; i++)L[i] = trump1[l + i];
  for(j = 0; j < nb; j++)R[j] = trump1[m + j];
  L[na].key = R[nb].key = INFTY;
  i = j = 0;
  for(k = l; k < r; k++){
    if(L[i].key <= R[j].key){
      trump1[k] = L[i] ;
      i++;
    }
    else {
      trump1[k] = R[j];
      j++;
    }
  }
}

void MergeSort(int l,int r){
  int m;
  if(l + 1 < r){
    m = (l + r)/2;
    MergeSort(l,m);
    MergeSort(m,r);
    Merge(l,m,r);
  }
}
int Partition(int p,int r){
  int i,j;
  Card x,v;
  
  x = trump2[r];
  i = p - 1;
  for(j = p; j <= r - 1; j++){
    if(trump2[j].key <= x.key){
      i = i + 1;
      v = trump2[i];
      trump2[i] = trump2[j];
      trump2[j] = v;
    }
  }
  v = trump2[i+1];
  trump2[i+1] = trump2[r];
  trump2[r] = v;

  return i+1;
}

void QuickSort(int p,int r){
  int h;
  if(p < r){
    h = Partition(p,r);
    QuickSort(p,h-1);
    QuickSort(h+1,r);
  }
}

void isStable(){
  int i,stable = 0;
  for(i = 0; i < n; i++){
    if(trump1[i].type == trump2[i].type){
      stable = 1;
    }
    else {
      stable = 0;
      break;
    }
  }
  
  if(stable == 1)printf("Stable\n");
  else printf("Not stable\n");
}

int main(){
  int i,key;
  char type;
  
  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%s %d",&type,&key);
    trump1[i].key = trump2[i].key = key;
    trump1[i].type = trump2[i].type = type;
  }
  //if(n <= 2)MergeSort(0,n-1);
  MergeSort(0,n);
  QuickSort(0,n - 1);
  isStable();

  for(i = 0; i < n; i++)printf("%c %d\n",trump2[i].type,trump2[i].key);
  //for(i = 0; i < n; i++)printf("%c %d\n",trump1[i].type,trump1[i].key);
  
  return 0;
}

