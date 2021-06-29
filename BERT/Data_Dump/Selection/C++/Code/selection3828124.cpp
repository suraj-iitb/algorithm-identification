#include <iostream>

using namespace std;

void selectionSort(int *Array, int N)
{
  int mini = 0;
  int counter = 0;
  for(int i = 0; i < N; i++ ){
    mini = i;
    for(int j = i; j < N; j++){
      if( Array[j] < Array[mini]){
        mini = j;
        
      }
    }
    if ( i != mini ){
      swap(Array[i], Array[mini]);
      counter++;
    }
    
  }

  for(int i = 0; i < N; i++){
    if ( i == N -1 ) cout << Array[i] << endl;
    else cout << Array[i] << " ";
  }

  cout << counter << endl;
  return;
}


int main(int argc, char const *argv[])
{
  int n, array[101];
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> array[i];
  }
  
  selectionSort(array, n);
  return 0;
}

