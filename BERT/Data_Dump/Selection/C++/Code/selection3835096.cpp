#include<iostream>
#include<cmath>
#include<vector>
//#include<string>

using namespace std;

void elem_swap(int &a,int &b){
  int temp=a;
  a=b;
  b=temp;
}

int selectionSort(vector<int> &vec,int size){
  int min_index,count=0;
  for(int i=0;i<size-1;i++){
    min_index=i;
    for(int j=i;j<size;j++){
      if(vec.at(min_index)>vec.at(j)){
        min_index=j;
      }
    }
    if(min_index>i){
      elem_swap(vec.at(i),vec.at(min_index));
      count++;
    }
  }
  return count;
}

int main(void){

  int size,count;
  cin>>size;
  vector<int> vec(size);
  for(int i=0;i<size;i++) cin>>vec.at(i);

  count=selectionSort(vec,size);

  for(int i=0;i<size-1;i++) cout<<vec.at(i)<<" ";
  cout<<vec.at(size-1)<<endl;
  cout<<count<<endl;

  return 0;
}

