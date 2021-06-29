#include <iostream>
using namespace std;
const int MAX = 1000000+5;
int n,a[MAX];
void Print(){
	for(int i = 0;i < n-1;i++)
		cout << a[i] << " ";
	cout << a[n-1] << endl;
}
void InsertionSort(){
	Print();
	for(int i = 1;i < n;i++){
		int t = a[i];
		int j = i-1;
		while(j >= 0 && a[j] > t){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = t;
		Print();
	}
}
int main(int argc, char const *argv[])
{
	cin >> n;
	for(int i = 0;i < n;i++)
		cin >> a[i];
	InsertionSort();
	return 0;
}
