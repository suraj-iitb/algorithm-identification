#include <iostream>

using namespace std;
void swap(int &a,int &b){
  int tmp = a;
  a = b;
  b = tmp;
}
int main(int argc, char const *argv[]) {
  int count;
  cin >> count;
  int *a = new int[count];
  for (int i = 0; i < count; i++) {
    cin >> a[i];
  }
  int swap_count = 0;
  for (int i = 0; i < count; i++) {
    int miniIdx = i;
    for (int j = i; j < count; j++) {
      if( a[j] < a[miniIdx]){
        miniIdx = j;
      }
    }
    if(i != miniIdx){
      swap(a[i], a[miniIdx]);
      swap_count++;
    }
  }
  for(int i = 0; i < count; i++){
    cout << a[i];
    if (i == count - 1){
      cout << endl;
    }else{
      cout << " ";
    }
  }
  cout << swap_count << endl;
  delete [] a;
  return 0;
}
