#include<iostream>
#include<algorithm>
using namespace std;

void Cout(int a[], int n) {
	int i;
	for(int i = 0; i < n; i++){
	    if(i != n-1){
		    cout<<a[i]<<" ";
	    }
	    else{
			cout<<a[i]<<endl;
	    }
	}
}

int Bubble_Sort(int a[], int n) {
	int flag = 1, i, swap_num = 0;
	while (flag) {
		flag = 0;

		for (i = n - 1; i > 0; i--) {
			if (a[i] < a[i - 1]) {
				swap(a[i], a[i - 1]);
				swap_num++;
				flag = 1;
			}
		}
	}

	return swap_num;
}

int main() {
	int n, a[100], i,swap_num;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	swap_num = Bubble_Sort(a, n);
	Cout(a, n);
	cout << swap_num<<endl;

	return 0;
}
