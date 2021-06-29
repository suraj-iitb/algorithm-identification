#include <iostream>
using namespace std;

void bubbleSort();

int A[100];
int X;
int count = 0;

int main() {
	cin >> X;
	for(int i=0; i<X; i++){
		cin >> A[i];
	}
	bubbleSort();
	for(int i=0; i<X; i++){
		if(i==X-1){
			cout << A[i];
		}else{
			cout << A[i] << " ";
		}
	}
	cout << endl;
	cout << count << endl;
	return 0;
}

void bubbleSort(){
  for(int i=0; i<X; i++){
  	for(int j=X-1; j>i; j--){
  		if(A[j]<A[j-1]){
  			swap(A[j], A[j-1]);
  			count++;
  		}
  	}
  }
}
