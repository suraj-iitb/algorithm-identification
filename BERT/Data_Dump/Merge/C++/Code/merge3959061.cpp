#include <iostream>

using namespace std;

int n;
int x = 0;

void merge_sort(int a[], int left, int right);
int main(){

  cin >> n;

  int a[n];

  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  merge_sort(a, 0, n-1);

  for(int i = 0; i < n-1; i++){
    cout << a[i] << " ";
  }
  cout << a[n-1];

  cout << "\n";

  cout << x << '\n';

  return 0;
}
void merge_sort (int a[], int left, int right) {

  int i, j, k, mid;
  int tmp[n];
  if(left < right){
    mid = (left + right) / 2;
    merge_sort(a, left, mid);
    merge_sort(a, mid+1, right);
    for(i = mid; i >= left; i--){
      tmp[i] = a[i];
    }
    for(j = mid + 1; j <= right; j++){
      tmp[right-(j-(mid+1))] = a[j];
    }
    i = left; j = right;
    for(k = left; k <= right; k++) {
      x++;
      if(tmp[i] < tmp[j]){
        a[k] = tmp[i++];
      }
      else{
        a[k] = tmp[j--];
      }
    }
  }
}

