#include<iostream>
using namespace std;
class sort{
private:
  void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
  }
public:
  void sort_insert(int data[],int num){
    
   for(int j=0;j<num;j++){
	cout<<data[j];
	if(j!=num-1)
	  cout<<" ";
      }
      cout<<endl;
    for(int i=1;i<num;i++){
      for(int j=i;j>0;j--){
	if(data[j]<data[j-1])
	  swap(&data[j],&data[j-1]);
      }
      for(int j=0;j<num;j++){
	cout<<data[j];
	if(j!=num-1)
	  cout<<" ";
      }
      cout<<endl;
    }
  }
};

int main(){
  sort Sort;
  int n;
  cin>>n;
  int data[n];
  for(int i=0;i<n;i++)
    cin>>data[i];
  Sort.sort_insert(data,n);
  return 0;
}
