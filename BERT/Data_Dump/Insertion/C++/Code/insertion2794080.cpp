#include<iostream>
using namespace std;
int main()
{
  int n,j=0,v=0;
  int a[100];
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
	for(int i=0;i<n;i++){
		v=a[i];
		j=i-1;
		while(j>=0 && a[j]>v){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=v;
		for(int i=0;i<n;i++){
			cout<<a[i];
			if(i!=n-1){
				cout<<" ";
			}
		}
		cout<<"\n";
	}
  return 0;
}
