#include <iostream>
#include <cmath>
using namespace std;

int main()
{
		int i,j,n,a[105],v,t,k=0;
		cin>>n;
		for(i=0;i<n;i++){
			cin>>a[i];
		}
		for(i=0;i<n-1;i++){
			for(j=0;j<n-1-i;j++){
				if(a[j]>a[j+1]){
					k++;
					t=a[j];a[j]=a[j+1];a[j+1]=t;
				}
			}
		}
		for(i=0;i<n-1;i++){
			cout<<a[i]<<" ";
		}
		cout<<a[i]<<endl;
		cout<<k<<endl;
		return 0;
}
