#include <iostream>
using namespace std;

void swap(int *a, int *b){
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
  return ;
}

void selectionSort(int a[], int n){
  int count  = 0;
  for(int i = 0; i < n; i++){
    int min_j = i;
    for(int j = i; j < n; j++){
      if(a[j] < a[min_j]) min_j = j;
    }
    if(i != min_j){
      swap(&a[i], &a[min_j]);
      count++;
    }
  }
  for(int i = 0; i < n-1; i++){
    cout << a[i] << " ";
  }
  cout << a[n-1] << endl;
  cout << count << endl;

  return ;
}

int main(){
  int n, a[101];
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  selectionSort(a, n);
  return 0;
}
