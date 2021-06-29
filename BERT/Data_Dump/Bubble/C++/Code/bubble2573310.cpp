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
int bubbleSort(vector<int> &A)
{	
	int count = 0;
	for(int i = 0; i <= A.size() - 1; i++){
		for(int j = A.size() - 1; j >= i + 1; j--){
			if(A[j] < A[j - 1]){
				count++;
				int a = A[j];
				A[j] = A[j - 1];
				A[j - 1] = a;
			}
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
	
	int count = bubbleSort(A);
	
	print_vector(A);
	cout << count << endl;
	return 0;
}
