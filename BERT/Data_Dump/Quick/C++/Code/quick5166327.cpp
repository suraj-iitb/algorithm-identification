#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)

struct card{
  char mark,id;
  int number;
};

int partition(card A[], int p, int r){
  card x = A[r];
  int i = p - 1;
  for(int j = p; j < r; j++){
    if(A[j].number <= x.number){
      i++;
      swap(A[i],A[j]);
    }
  }
  swap(A[i+1],A[r]);
  return i+1;
}

void quicksort(card A[], int p, int r){
  if(p < r){
    int q = partition(A,p,r);
    quicksort(A,p,q-1);
    quicksort(A,q+1,r);
  }
}

void check(card A[], int n){
  for(int i = 1; i < n; i++){
    if(A[i-1].number < A[i].number) continue;
    if(A[i-1].id < A[i].id) continue;
    cout << "Not stable" << endl;
    return;
  }
  cout << "Stable" << endl;
}

int main(){
  int n;
  cin >> n;
  card cards[n];
  rep(i,n){
    cin >> cards[i].mark >> cards[i].number;
    cards[i].id = i;
  }

  quicksort(cards,0,n-1);
  check(cards,n);

  rep(i,n){
    cout << cards[i].mark << " " << cards[i].number << endl;
  }
}
