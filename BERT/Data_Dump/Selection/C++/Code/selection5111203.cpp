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
		int min;
		for(i=0;i<n-1;i++){
			min=i;
			for(j=i+1;j<n;j++){
				if(a[min]>a[j]){
					min=j;
				}
			}
			if(i!=min){
				t=a[i];a[i]=a[min];a[min]=t;
				k++;
			}
		}
		for(i=0;i<n-1;i++){
			cout<<a[i]<<" ";
		}
		cout<<a[i]<<endl;
		cout<<k<<endl;
		return 0;
}
