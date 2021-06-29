#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char* argv[]){
  int num,input,move;
  vector<int> target;
  cin >> num;
  for(int i=0;i<num;i++){
    cin >> input;
    target.push_back(input);
  }
 for(int k=0;k<num;k++){
    if(k==num-1) cout << target[k] << endl;
    else cout << target[k] << " ";
  }
  for(int i=1;i<num;i++){
    int j=i-1;
    move=target[i];
    while(j>=0 and target[j]>move){
      swap(target[j],target[j+1]);
      j--;
      move=target[j+1];
    }
    for(int k=0;k<num;k++){
      if(k==num-1) cout << target[k] << endl;
      else cout << target[k] << " ";
    }
  }
}
