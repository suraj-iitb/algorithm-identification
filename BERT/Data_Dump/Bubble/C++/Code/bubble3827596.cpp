#include <iostream>

using namespace std;


/**
 * @brief bubble sort
 * @param int &Array 
 * @param int N
 * @return count 
 * @detail print sort data
 */
int bubbleSort(int *Array, int N)
{
  int count = 0;
  for(int i = 0; i < N; i++){
    for(int j = i; j > 0; j--){
      if (Array[j] < Array[j-1]){
        int temp = Array[j];
        Array[j] = Array[j-1]; 
        Array[j-1] = temp;
        count++;
      }
    }
  }

  for(int i = 0; i < N; i++){
    if ( i == N -1 ) cout << Array[i] << endl;
    else cout << Array[i] << " ";
  }

  return count;
}

int main(int argc, char const *argv[])
{
  int n, array[101];
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> array[i];
  }

  cout << bubbleSort(array, n) << endl;
  return 0;
}


