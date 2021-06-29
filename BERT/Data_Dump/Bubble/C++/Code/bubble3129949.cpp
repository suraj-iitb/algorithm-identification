#include<iostream>
using namespace std;

int main(){
  int size;

  cin>>size;

  int array[size],exchange,count=0;
  for(int i = 0;i < size;i++)
    cin >> array[i];

  bool flag = true;

  while(flag){
    flag = false;
    for(int i = 0;i < size-1;i++){
      if(array[i]>array[i+1]){
        exchange = array[i];
        array[i] = array[i+1];
        array[i+1] = exchange;
        count++;
        flag = true;
      }
    }
  }

  for(int i = 0;i < size-1;i++)
    cout << array[i] << " ";
  cout<<array[size-1]<<endl;
  cout<<count<<endl;

  return 0;
}

