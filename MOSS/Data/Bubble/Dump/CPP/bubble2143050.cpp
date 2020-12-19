#include <iostream>
using namespace std;
int main() {
	int n,a[100],num=0;
	cin>>n;
	for(int i=0; i<n;i++) {
		cin>>a[i];
		int tmp=a[i],j;
		for (j=i-1;j>=0 && tmp<a[j];j--) a[j+1]=a[j],num++;
		a[j+1]=tmp;
	}
	for (int i=0;i<n-1;i++) cout<<a[i]<<" ";
	cout<<a[n-1]<<endl<<num<<endl;
	return 0;
}
