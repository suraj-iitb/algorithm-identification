#include<iostream>
#include<string>

using namespace std;
int main()
{
	int N,a[100]={},i,j,k,key;
	cin>>N;
	for(i=0;i<N;i++)
		cin>>a[i];
	for(k=0;k<N-1;k++)
		cout<<a[k]<<" ";
	cout<<a[N-1]<<endl;

	for(i=1;i<N;i++){
		key = a[i];
		j = i-1;
		while(j>=0&&a[j]>key){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
			
		for(k=0;k<N-1;k++)
			cout<<a[k]<<" ";
		cout<<a[N-1]<<endl;	
	}
	return 0;
}
