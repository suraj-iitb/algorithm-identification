#include <iostream>
using namespace std;

int n, a[110], i, j, t, mini;

void selectionsort() {
	for (i=0; i<n; i++) {
		int mini = i; //mini is the minimum value
		for (j=i; j<n; j++) //j is unsorted
			if (a[j]<a[mini])
				mini=j;
			if ( i != mini) {
				swap (a[i], a[mini]);
				t++;
	}
		
			}
}

int main() {
	cin>>n; //input a value of n where n = number of values eg. 5
		for (i=0; i<n; i++) cin>>a[i]; //input the values eg. 1 3 6 2 5
			selectionsort();
		for (i=0; i<n-1; i++) cout<<a[i]<< " "; //output sorted values with space in between eg. 1 2 3 5
	cout<<a[n-1]<<endl; //output value a[n-1] and then end of line(\n)
	cout<<t<<endl;
	return 0;
}

// I not sure where is the problem since I'm not fimilar to C++ but you can try to to print out some word on each command that you think might make your program not working.
