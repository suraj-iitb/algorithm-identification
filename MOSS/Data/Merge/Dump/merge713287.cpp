#include <iostream>
#include <string>
#include <vector>
using namespace std;

int merge(vector <int> &A, vector <int> &buf, int low, int mid, int high){
	int i=low, j=low, k=mid;

	while (j<mid && k<high){
		if (A[j] < A[k])
			buf[i] = A[j++];
		else
			buf[i] = A[k++];
		i++;
	}

	if (j<mid)
		for(int h=j; h<mid; h++,i++)
			buf[i] = A[h];
	else
		for (int h=k; h<high; h++,i++)
			buf[i] = A[h];

	for (int i=low; i<high; i++)
		A[i] = buf[i];

	return high-low;
}

int mergesort(vector <int> &A, vector <int> &buf, int low, int high ){

	int m=(high+low)/2, counter=0;
	if (low+1 >= high){
		return 0;
	}

	counter += mergesort(A, buf, low, m );
	counter += mergesort(A, buf, m, high );
	counter += merge(A, buf, low, m, high);
	return counter;
}

int vector_out(vector <int> &A){
    int n=A.size();
    for (int i=0; i<n; i++){
        cout << A[i];
        if (i!= n-1) cout<<" ";
        else cout<<endl;
    }
    return 0;
}

int main(void){
	int n, counter;
	cin >> n;
	vector <int> A(n);
	vector <int> buf(n);
	for (int i=0; i<n; i++){
		cin >> A[i];
		buf[i]=0;
	}
		
	counter = mergesort(A, buf, 0, n);
	vector_out(A);
	cout << counter << endl;

	return 0;
}
