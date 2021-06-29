#include <cstdio>
#include <utility>

constexpr int MAX_N = 100000;

struct card{
  char suit;
  int num;
  int index;
};

int partition(card* A, int p, int r){
  card x = A[r];
  int i = p - 1;
  for(int j = p; j < r; j++){
    if(A[j].num <= x.num){
      i++;
      std::swap(A[i], A[j]);
    }
  }
  std::swap(A[i+1], A[r]);
  return i+1;
}

int quicksort(card* A, int p, int r){
  if(p < r){
    int q = partition(A, p, r);
    quicksort(A, p, q - 1);
    quicksort(A, q + 1, r);
  }
  return 0;
}

int main(){
  int n;
  card A[MAX_N];
  scanf("%d", &n);

  for(int i = 0; i < n; i++) {
    A[i] = {' ', 0, i};
    scanf("%s", &A[i].suit);
    scanf("%d", &A[i].num);
  }
  quicksort(A, 0, n-1);

  bool stable = true;
  for(int i = 0; i < n - 1; i++){
    for(int j = i + 1; j < n; j++){
      if(A[i].num != A[j].num){
	i = j - 1;
	break;
      }
      if(A[i].index > A[j].index){
	stable = false;
	break;
      }
    }
  }
  if(stable){
    printf("Stable\n");
  }else{
    printf("Not stable\n");
  }
  for(int i = 0; i < n; i++){
    printf("%s %d\n", &A[i].suit, A[i].num);
  }
}
