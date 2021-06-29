#include<iostream>
using namespace std;

int main(){
  int N,key,j=0;
  int a[100];
  cin >> N;
  for (int i=0;i<N;i++)
    cin >> a[i];

  for(int i=0;i<N;i++){
    key = a[i];
    j = i - 1;
    while(j>=0 && a[j] > key){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = key;
    for(int k=0;k<N;k++){
      cout << a[k];
      if(k != N-1)cout << " ";
    }
    cout << endl;
  }
    return 0;
}
		
