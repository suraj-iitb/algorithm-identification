#include <iostream>

using namespace std;

void insertionSort(int array[],int size);

int main(void){
  int size;
  cin >> size;
  int array[size];
  for(int i = 0;i < size;i++){
    cin >> array[i];
  }
  insertionSort(array,size);

  return 0;
}

void insertionSort(int array[],int size){
  for(int j = 0;j < size;j++){
    int handle = array[j];
    int k = j-1;
    while((k >= 0) && (handle < array[k])){
      array[k+1] = array[k];
      k--;
    }
    array[k+1] = handle;
    for(int l = 0;l < size;l++){
      if(l == (size -1)){
        cout<<array[l]<<endl;
    }else{
      cout<<array[l]<<" ";
    }
    }
  }
}

