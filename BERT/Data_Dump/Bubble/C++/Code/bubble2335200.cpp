#include<iostream>
using namespace std;
int main(){
	int n,*a,d=0;
	cin>>n;
	a=new int[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
	{
		for(int j=n-1;j>i;j--){
			if(a[j]<a[j-1]){
				int b=a[j];
				a[j]=a[j-1];
				a[j-1]=b;
				d++;
			}

		}
	}
	for(int i=0;i<n;i++)
		{cout<<a[i];
		if(i<n-1)
			cout<<" ";
	}
	cout << endl << d << endl;

	return 0;
}
