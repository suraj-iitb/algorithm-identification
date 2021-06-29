#include<iostream>
#include<cstdio>
#include<algorithm> 
using namespace std;
int main()
{
	int n,count=0;
	int a[110];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	bool f=1;
	int j=0;
	while(f){
		f=0;
		for(int i=n-1;i>=j+1;i--){
			if(a[i]<a[i-1]){
				swap(a[i],a[i-1]);		
				count++;
			}
		
			f=1;	
		}
		j++; 
	}
	cout<<a[0];
	for(int i=1;i<n;i++){
		cout<<" "<<a[i];
	}
	cout<<endl;
	cout<<count<<endl;
	return 0;
}
 

