#include<stdio.h>

#define Max 100000
#define S 1000000000

struct Card{
  char suit;
  int value;
};


struct Card L[Max / 2 + 2], R[Max / 2 + 2];

void mer(struct Card a[], int n, int l, int m, int r){
  int i, j, k, n1, n2;
  n1 = m - l;
  n2 = r - m;
  
  for(i = 0 ; i < n1 ; i++) 
                L[i] = a[l + i];
  for(i = 0 ; i < n2 ; i++) 
             R[i] = a[m + i];
  
  L[n1].value = R[n2].value = S;
  i = j = 0;
  
  for(k = l ; k < r ; k++){
    if(L[i].value <= R[j].value){
      a[k] = L[i++];
    }
    else{
      a[k] = R[j++];
    }
  }
}

void Sort(struct Card A[], int n, int l, int r){
  int m;
  if(l + 1 < r){
    m = (l + r) / 2;
    Sort(A, n, l, m);
    Sort(A, n, m, r);
    mer(A, n, l, m, r);
  }
}

int partition(struct Card A[], int n, int p, int r){
  int i, j;
  struct Card t, x;
  x = A[r];
  i = p - 1;

  for(j = p ; j < r ; j++){
    if(A[j].value <= x.value){
      i++;
      t = A[i];
      A[i] = A[j];
      A[j] = t;
    }
  }

  t = A[i + 1];
  A[i + 1] = A[r];
  A[r] = t;


  return i + 1;
}

void quickSort(struct Card A[], int n, int p, int r){
  int q;
  if(p < r){
    q = partition(A, n, p, r);
    quickSort(A, n, p, q - 1);
    quickSort(A, n, q + 1, r);
  }
}


int main(){
  int n, i, v, stable = 1;
  struct Card A[Max], b[Max];
  char s[10];

  scanf("%d", &n);

  for(i = 0 ; i < n ; i++){
    scanf("%s %d", s, &v);
    A[i].suit = b[i].suit = s[0];
    A[i].value = b[i].value = v;
  }

  Sort(A, n, 0, n);
  quickSort(b, n, 0, n - 1);
  
  for(i = 0 ; i < n ; i++){
    if(A[i].suit != b[i].suit) 
             stable = 0;
  }

  if(stable == 1)
         printf("Stable\n");
  else  
         printf("Not stable\n");
  for(i = 0 ; i < n ; i++){
    printf("%c %d\n", b[i].suit, b[i].value);
  }

  return 0;
}


