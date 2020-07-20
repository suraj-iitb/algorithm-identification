#include<iostream>
using namespace std;

int main(){
	int numOfElem;
	cin >> numOfElem;
	int elem[100];

	for(int i = 0; i < numOfElem; i++){
		cin >> elem[i];
	}

	int swapCounter = 0;
	int preSwapCounter = -1;

	for(int i = 0; i < numOfElem; i++){
		for(int j = numOfElem - 1; j - i >= 0; j--){
			if(elem[j] < elem[j-1]){
				int buf = elem[j];
				elem[j] = elem[j-1];
				elem[j-1] = buf;
				swapCounter ++;
			}
		}
		if(swapCounter == preSwapCounter) break;
		preSwapCounter = swapCounter;
	}

	for(int i = 0; i < numOfElem; i ++){
		cout << elem[i];
		if(i + 1 == numOfElem)cout << endl;
		else cout << " ";
	}
	cout << swapCounter << endl;

	return 0;
}
