#include<iostream>
using namespace std;

int main(){

	int numOfElement;
	int elem[100];

	cin >> numOfElement;

	for(int i = 0; i < numOfElement; i++){
		cin >> elem[i];
	}

	int swapCounter = 0;

	for(int i = 0; i < numOfElement; i++){
		int miniIndex = i;
		for(int j = i; j < numOfElement; j++){
			if(elem[miniIndex] > elem[j]){
				miniIndex = j;
			}
		}
		if(miniIndex != i){
			swapCounter ++;
			int buf = elem[i];
			elem[i] = elem[miniIndex];
			elem[miniIndex] = buf;
		}

	}

	for(int i= 0; i < numOfElement; i ++){
		cout << elem[i];
		if(i + 1 == numOfElement)cout << endl;
		else cout << " ";
	}

	cout << swapCounter << endl;



	return 0;
}
