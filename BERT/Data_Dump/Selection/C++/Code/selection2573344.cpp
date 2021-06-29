#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

void print_vector(vector<int> num)
{
	for(int i = 0; i < num.size(); i++){
		if(i){
			cout << " ";
		}
		cout << num[i];
	}
	cout << endl;
}
int SelectionSort(vector<int> &A)
{	
	int count = 0;
	for(int i = 0; i <= A.size() - 1; i++){
		int mini= i;
		for(int j = i; j <= A.size() - 1; j++){
			if(A[j] < A[mini]){
				mini = j;
			}
		}
		if(i != mini){
			count++;
			int a = A[i];
			A[i] = A[mini];
			A[mini] = a;
		}
	}
	return count;
}
int main(void)
{
	int n;
	cin >> n;
	vector<int> A(n);
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	
	int count = SelectionSort(A);
	
	print_vector(A);
	cout << count << endl;
	return 0;
}
