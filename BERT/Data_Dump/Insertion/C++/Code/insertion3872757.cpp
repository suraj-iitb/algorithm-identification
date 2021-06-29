#include<bits/stdc++.h>
using namespace std;
const int maxN = 101;
/*
	input:
	6
	5 2 4 6 1 3
	output:
	5 2 4 6 1 3
	2 5 4 6 1 3
	2 4 5 6 1 3
	2 4 5 6 1 3
	1 2 4 5 6 3
	1 2 3 4 5 6
*/

int T[maxN];
int N;

void printT(){
	for(int i = 0;i < N - 1;i++)cout << T[i] << " ";
	cout << T[N - 1];
}

int main(){
	int num;
	cin >> N;
	for(int i = 0;i < N;i++){
		cin >> num;
		T[i] = num;
	}
	int j;
	for(int i = 0;i < N;i++){
		j = 0;
		while(T[j] < T[i] && j < i)j++;
		int value = T[i];
		for(int k = i;k > j;k--)T[k] = T[k - 1];
		T[j] = value;
		printT();
		cout << endl;
//		if(i != N - 1)cout << endl;
	}
	return 0;
}
