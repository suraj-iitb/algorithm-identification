#include<iostream>
#include<cmath>
#include<vector>
#define buff 10001

using namespace std;

int main(void){

  int size,cumsum=0;
  cin>>size;
  size=size;
  vector<int> vec(size);
  vector<int> res(size);
  vector<int> cstore(buff);
  for(int i=0;i<size;i++){
    cin>>vec.at(i);
    cstore.at(vec.at(i))++;
  }
  for(int i=0;i<buff;i++){
    cumsum+=cstore.at(i);
    cstore.at(i)=cumsum;
  }
  for(int i=size-1;i>=0;i--){
    res.at(--cstore.at(vec.at(i)))=vec.at(i);
  }
  for(int i=0;i<size-1;i++) cout<<res.at(i)<<" ";
  cout<<res.at(size-1)<<endl;
  return 0;
}

