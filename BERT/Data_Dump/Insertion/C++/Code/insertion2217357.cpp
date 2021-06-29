#include <iostream>

using namespace std;
class sorter {
  int count;
  int *array;
public:
  sorter(int count){
    this->count = count;
    array = new int[count];
  }
  ~sorter(){
    delete [] array;
  }
  void input();
  void output();
  void sort();
};

void sorter::input(){
  for (int i = 0; i < count; i++) {
    cin >> array[i];
  }
}

void sorter::output(){
  for (int i = 0; i < count; i++) {
    cout << array[i];
    if(i < count - 1){
      cout << " ";
    }else{
      cout << endl;
    }
  }
}

void sorter::sort(){
  for (int i = 1; i < count; i++) {
    output();
    int key = array[i];
    int j = i - 1;
    while (j >= 0 && array[j] > key) {
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = key;
  }
  output();
}
int main(int argc, char const *argv[]) {
  int count;
  cin >> count;
  sorter s = sorter(count);
  s.input();
  s.sort();
  return 0;
}
