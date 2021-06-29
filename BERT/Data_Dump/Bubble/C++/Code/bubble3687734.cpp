#include<iostream>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n-1;j++){
				if(a[j]>a[j+1]){
					ans++;
					int temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
			}
		}
		cout<<a[0];
		for(int i=1;i<n;i++)
			cout<<' '<<a[i];
		cout<<endl;
		cout<<ans<<endl;
	}
	return 0;
}
