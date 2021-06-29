#include<iostream>
#include<algorithm>

using namespace std;

void printArray(int * arr, int num) {
	for(int i=0; i<num; i++) {
		if (i == 0) {
			cout<<arr[i];
		} else {
			cout<<" "<<arr[i];
		}
	}
	cout<<endl;
}


int main(int argc, char const *argv[])
{
	int n;
	int arr[100] = {0};

	cin>>n;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}

	printArray(arr, n);
	for(int i=1; i<n; i++) {
		int v = arr[i];
		int j = i - 1;
		while (j >=0 && arr[j]>v) {
			arr[j+1] = arr[j]; 
			j--;
		}
		arr[j+1] = v;
		printArray(arr, n);
	}
	return 0;
}
