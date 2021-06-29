#include<iostream>
using namespace std;
int main(){
	int n;
	int num=0;
	cin>>n;
	int *p=new int[n];
	for(int i=0;i<n;i++)
		cin>>p[i];
	for(int i=0;i<n-1;i++)
		for(int j=1;j<n;j++){
			if(p[j]<p[j-1]){
				int temp=p[j];
				p[j]=p[j-1];
				p[j-1]=temp;
				num++; 
			} 
		}
	for(int i=0;i<n-1;i++)
	cout<<p[i]<<" ";
	cout<<p[n-1]<<endl; 
	cout<<num<<endl;
	return 0;
} 
