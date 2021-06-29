#include<iostream>
#include<algorithm>
using namespace std;
void pr(int a[],int n){
	int first=1;
	for (int i=0;i<n;i++){
		if(first)first=0;else cout<<" ";
		cout<<a[i];
	}
	cout<<endl;
}
int BubbleSort(int a[],int n){
	int cnt=0;
	for(int i=0;i<n;i++){
		for(int j=n-1;j>i;j--){
			if(a[j]<a[j-1]){
				swap(a[j],a[j-1]);
				cnt++;
			}
		}
	}
	return cnt;
}
int main(){
	int n,a[102];
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	int cnt=BubbleSort(a,n);
	pr(a,n);
	cout<<cnt<<endl;
	return 0;
}
