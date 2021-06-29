#include<bits/stdc++.h>

using namespace std;


int main(){
	int n;
	cin >> n;
	vector<int> A(n);

	for(int i = 0;i < n;i++){
		cin >> A[i];
	}

int count = 0;
int minj;
	for(int i = 0;i < n-1;i++){
		minj = i;
		for(int j = i;j < n-1;j++){
			if(A[minj] > A[j+1]){
				minj = j+1;
			} 

		}
if(A[i] != A[minj]){
 swap(A[i],A[minj]);
  count++;
}

	}

for(int i = 0;i < n-1;i++){
	cout << A[i] <<' ' ;
}
cout << A[n-1] <<endl;

cout << count <<endl;


}
