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
    for (int j = count - 1; j > 0; j--) {
      if( a[j] < a[j - 1]){
        swap(a[j], a[j - 1]);
        swap_count++;
      }
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
