#include<iostream>
#include<vector>

using namespace std;
void print(vector<int>& values)
{
  for(int i=0;i<values.size()-1;i++) cout<<values[i]<<" ";
  cout<<values[values.size()-1]<<endl;
}
void insertionSort(std::vector<int>& numbers)
{
  int key;
  for(int i=1; i<numbers.size();i++){
    print(numbers);
    key = numbers[i];
    int j = i-1;
    while( (j>=0) and (numbers[j]>key) ){
      numbers[j+1]=numbers[j];
      j--;
    }
    numbers[j+1]=key;
  }
}
int main(void)
{
  int n;
  std::vector<int> numbers;
  std::cin >> n; numbers.resize(n);
  for(int i=0; i<n; i++) std::cin>>numbers[i];
  insertionSort(numbers);
  print(numbers);
  return 0;
}
