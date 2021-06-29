#include<iostream>
using namespace std;
void pr(int a[],int n){
	int first=1;
	for (int i=0;i<n;i++){
		if(first)first=0;else cout<<" ";
		cout<<a[i];
	}
	cout<<endl;
}
int main(){
	int n,a[102];
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	pr(a,n);
	for(int i=1;i<n;i++){
		int v=a[i],j=i-1;
		while(j>=0&&a[j]>v){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=v;
		pr(a,n);
	}
	return 0;
}
