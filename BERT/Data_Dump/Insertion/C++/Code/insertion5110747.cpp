#include <iostream>
#include <cmath>
using namespace std;

int main()
{
		int i,j,n,a[105],v,t,k;
		cin>>n;
		for(i=0;i<n;i++){
			cin>>a[i];
			if(i!=n-1)cout<<a[i]<<' ';
			else cout<<a[i];
		}
		cout<<endl;
		for(i=1;i<n;i++){
			v=a[i];
			for(j=i-1;j>=0;j--){
				if(v<a[j]){
					a[j+1]=a[j];
				}
				else{
					break;
				}
			}
			a[j+1]=v;
			for(k=0;k<n-1;k++){
				cout<<a[k]<<' ';
			}
			cout<<a[k]<<endl;
			
		}
		return 0;
}
