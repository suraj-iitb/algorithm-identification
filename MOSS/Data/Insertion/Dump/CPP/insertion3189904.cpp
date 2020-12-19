#include<bits/stdc++.h>
using namespace std;

void print(vector<int> &a){
cout<<a[0];
for(int i=1;i<a.size();i++)cout<<' '<<a[i];
cout<<endl;
return ;
}
void swap(int *a,int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
	return ;
}
int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)cin>>a[i];

	for(int i=0;i<n;i++){
		int v= a[i];
		int j=i-1;
		while(j>=0&&a[j]>v){
		a[j+1]=a[j];
		a[j]=v;
		j--;
		}
	print(a);
	}


	return 0;
}

