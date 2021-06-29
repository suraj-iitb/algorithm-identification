#include <iostream>
using namespace std;
int b[2000005];
void countingsort(int *a,int n,int max)
{
		int i,j,c[10005]={0};
		for(i=0;i<n;i++){
			c[a[i]]++;
		}
		for(i=1;i<=max;i++){
			c[i]+=c[i-1];
		}
		for(i=n-1;i>=0;i--){
			b[c[a[i]]--]=a[i];
		}
}
int main()
{
		int n,a[2000005],max=-1010000;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(max<a[i]){
				max=a[i];
			}
		}
		countingsort(a,n,max);
		for(int i=1;i<=n;i++){
			if(i!=1)cout<<' ';
			cout<<b[i];
		}
		cout<<endl;
		return 0;
}
