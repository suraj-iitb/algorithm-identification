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


void bubbleSort(int matrix[], int N){
  
  int temp=0;
  int cnt=0;

  for(int i=0;i<N;i++){
    for(int j=N-1;j>i;j--){
      if(matrix[j-1] > matrix[j]){
        temp = matrix[j];
        matrix[j] = matrix[j-1];
        matrix[j-1] = temp;
        cnt = cnt + 1;
      }else{
      }
    }
  }

  trace(matrix, N);
  cout << cnt << endl;

}

int main(void){
  
  int N_tot;
  cin >> N_tot;

  int* matrix = new int [N_tot];
  for(int i=0;i<N_tot;i++){
    cin >> matrix[i];
  }

  bubbleSort(matrix, N_tot);

  delete [] matrix;
  
  return 0;

}
