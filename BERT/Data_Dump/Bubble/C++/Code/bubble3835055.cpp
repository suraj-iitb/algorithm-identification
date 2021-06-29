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

int bubbleSort(vector<int> &vec,int size){
  bool flag=true;
  int count=0;
  for(int i=0;i<size-1;i++){
    for(int j=0;j<size-1-i;j++){
      if(vec.at(j)>vec.at(j+1)){
        elem_swap(vec.at(j),vec.at(j+1));
        flag=false;
        count++;
      }
    }
    if(flag) break;
  }
  return count;
}

int main(void){
  int size,count;
  cin>>size;
  vector<int> vec(size);
  for(int i=0;i<size;i++) cin>>vec.at(i);
  count=bubbleSort(vec,size);
  for(int i=0;i<size-1;i++) cout<<vec.at(i)<<" ";
  cout<<vec.at(size-1)<<endl;
  cout<<count<<endl;

}

