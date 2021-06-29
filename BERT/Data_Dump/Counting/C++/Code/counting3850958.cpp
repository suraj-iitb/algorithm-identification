//标准库排序
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin>>n;
	int A[n];
	for(int i=0;i<n;i++)
		cin>>A[i];
	
	sort(A,A+n);
	
	for(int i=0;i<n-1;i++)
		cout<<A[i]<<" ";
	cout<<A[n-1]<<endl;
		
	return 0;
} 
