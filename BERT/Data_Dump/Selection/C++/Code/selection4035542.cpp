#include<iostream>
#include<vector>

using namespace std;

void selectionSort(vector<int> vec , size_t N){
  size_t minj=0;
  size_t count=0;
  for(size_t i=0; i<N; i++){
    minj =i;
    for(size_t j=i; j< N ; j++ ){
      if(vec[j] < vec[minj] ){
        minj =j;


      }

    }
    swap(vec[i],vec[minj]);
    if(i!=minj){
      count++;
    }
  }

  for(size_t i=0 ; i< N ; i++){
     if(i == N-1){
       cout<< vec[i];
     }
 else    cout<< vec[i] << " " ;
  }
  cout <<endl;

  cout<< count << endl;
}



int main(){
  size_t N;
  cin >> N;
  vector<int> vec(N);
  for(size_t i=0; i< N ; i++){
    cin>> vec[i];
  }

  selectionSort(vec,N);

  return 0;
}

