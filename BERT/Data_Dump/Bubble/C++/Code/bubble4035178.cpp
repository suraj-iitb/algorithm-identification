#include<iostream>
#include<vector>

using namespace std;

void bubbleSort(vector<int> vec,size_t N){
  size_t flag = 1;
  size_t i=0;
  size_t count =0;
  for(size_t i=0; flag; i++){
    flag =0;
    for(size_t j=N-1 ; j>=i+1; j--){
      if(vec[j]<vec[j-1]){
      swap(vec[j],vec[j-1]);
        flag = 1;
        count++;
      }

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
  cin>> N;
  vector<int> vec(N);
  for(size_t i=0;i< N;i++){
    cin>> vec[i];
  }

  bubbleSort(vec,N);

 return 0;
}

