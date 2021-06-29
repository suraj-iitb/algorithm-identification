#include<iostream>
using namespace std;

int main(){
	int numOfElement;
	int elem[100] = {};

	cin >> numOfElement;

	for(int i = 0; i < numOfElement; i++){
		cin >> elem[i];
	}

	for(int i = 0; i < numOfElement; i++){
		for(int j = i; j > 0 && elem[j] < elem[j -1]; j--){
			int buf = elem[j -1];
			elem[j - 1] = elem[j];
			elem[j] = buf;
		}
		for(int j = 0; j < numOfElement; j++){
			if(j + 1 >= numOfElement){
				cout << elem[j];
				break;
			}
			cout << elem[j] << " ";
		}
		cout << endl;

	}


	return 0;
}
