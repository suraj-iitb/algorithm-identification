#include <iostream>
using namespace std;

void printList(int num[], int n){
	for (int i = 0; i < n; i++){
		cout << num[i];
		if (i != n-1) cout << ' ';
	}
	cout << endl;
}

void swap(int *x, int *y){
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

int bubbleSort(int num[], int n){
	int flag = 1;
	int count = 0;
	while (flag){
		flag = 0;
		for (int j = n-1; j != 0; j--){
			if (num[j] < num[j-1]){
				swap (&num[j], &num[j-1]);
				count++;
				flag = 1;
			}
		}
	}
	return count;
}

int main(){
	int n[100];
	int limit;
	cin >> limit;
	for (int i = 0; i < limit; i++){
		cin >> n[i];
	}
//	printList(n, limit);
	int count;
	count = bubbleSort(n, limit);
	printList(n, limit);
	cout << count << endl;
	return 0;
}
