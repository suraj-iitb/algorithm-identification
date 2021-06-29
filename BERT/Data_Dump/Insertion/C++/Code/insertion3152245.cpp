#include <iostream>
using namespace std;

void printElements(int elements[], int n){
	for(int i = 0; i < n; i++){
		cout << elements[i];
		if(i != n - 1){
			cout << " ";
		}
	}
	cout << endl;
}

void insertionSort(int elements[], int n){
	int tmp;
	int j;
	for(int i = 1; i < n; i++){
		tmp = elements[i];
		j = i - 1;
		while( j >= 0 && elements[j] > tmp){
			elements[j+1] = elements[j];
			j--;
		}
		elements[j+1] = tmp;
		printElements(elements, n);
	}
}

int main(){
	int n;
	int elements[100];

	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> elements[i];
	}
	printElements(elements, n);
	insertionSort(elements, n);
	return 0;
}
