#include <iostream>
#include <vector>
using namespace std;
typedef vector <int> ivector;

int selectionsort(ivector &A){
	int n = A.size(), mini, count=0;
	for (int i=0; i<n; i++){
		mini = i;
		for (int j=i; j<n; j++)
			if (A[j] < A[mini])
				mini = j;
		if (i!=mini){
			swap(A[i], A[mini]);
			count++;
		}
	}
	return count;
}

int nums_out(ivector &A){
    int n=A.size();
    for (int i=0; i<n; i++){
        cout << A[i];
        if (i!= n-1) cout<<" ";
        else cout<<endl;
    }
    return 0;
}

int main(void){
	int n, count;
	cin>>n;
	ivector A(n);
	
	for (int i=0; i<n; i++)
		cin>>A[i];

	count = selectionsort(A);

	nums_out(A);
	cout << count << endl;
	return 0;
}
