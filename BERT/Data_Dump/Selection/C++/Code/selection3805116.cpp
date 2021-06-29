#include<iostream>

using namespace std;

int selectionSort(int matrix[], int N){

  int minj;
  int cnt=0;

  int temp;

  for(int i=0;i<N-1;i++){
    minj = i; 

    for(int j=i+1;j<N;j++){
      if(matrix[j] < matrix[minj]){
        minj = j;
      }
    }
    
    if(i != minj){    
      temp = matrix[i];
      matrix[i] = matrix[minj];
      matrix[minj] = temp;    
      cnt = cnt + 1;
    }
  }

  return cnt;
}

void outputMatrix(int matrix[], int N){
  for(int i=0;i<N;i++){
    if(i>0){
      cout << " ";
    }
    cout << matrix[i];
  }
  cout << endl;
}


int main(void){

  int N_tot;
  cin >> N_tot;

  int* matrix = new int [N_tot];
  for(int i=0;i<N_tot;i++){
    cin >> matrix[i];
  } 
  
  int cnt;
  cnt = selectionSort(matrix, N_tot);

  outputMatrix(matrix, N_tot);
  cout << cnt << endl;

  delete [] matrix;

  return 0;
}
