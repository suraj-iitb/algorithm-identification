#include<iostream>

using namespace std;

void trace(int matrix[], int N){
  for(int i=0;i<N;i++){
    if(i>0){
      cout << " ";
    }
    cout << matrix[i];
  }
  cout << endl;
}

void insertSort(int matrix[], int N){
  
  int temp;

  for(int i=1;i<N;i++){
    temp = matrix[i];
    int j = i-1;

    while( j>=0 && matrix[j] > temp){
      matrix[j+1] = matrix[j];
      j = j-1;
    }
    matrix[j+1] = temp;  
    trace(matrix, N);
  }

}


int main(void){
  
  //Input Unit
  int N_tot=0;

  cin >> N_tot;

  int* matrix = new int [N_tot];

  for(int i=0;i<N_tot;i++){
    cin >> matrix[i];
  }

  //Sort Unit
  trace(matrix, N_tot);
  insertSort(matrix, N_tot);

  delete [] matrix ;

  return 0;
}
