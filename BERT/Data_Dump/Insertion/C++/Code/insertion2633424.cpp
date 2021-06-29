#include<iostream>
#define REP(i,n) for(int i = 0; i < n; i++)

using namespace std;

void insertionSort(short a[], short n)
{
	for(short i = 1; i < n; i++){
		short v = a[i];
		short j = i -1;
		while(j >= 0 && a[j] > v){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = v;
		REP(i,n-1) cout << a[i] << ' ';
		cout << a[n-1];
		cout << endl;
	}
	return;
}

int main(void)
{
	short n;
	short a[100];
	cin >> n;
	REP(i,n) cin >> a[i];

	REP(i,n-1) cout << a[i] << ' ';
	cout << a[n-1];
	cout << endl;
	insertionSort(a,n);

        return 0;
}
