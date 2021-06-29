#include <iostream>
using namespace std;
int t;
void merge(int *a,int l,int mid,int r)
{
		int n1,n2,i,j=0,k=0;
		n1=mid-l;
		n2=r-mid;
		int p1[n1+1],p2[n2+1];
		for(i=l;i<mid;i++){
			p1[i-l]=a[i];
		}
		for(i=mid;i<r;i++){
			p2[i-mid]=a[i];
		}
		p1[n1]=2000000000;
		p2[n2]=2000000000;
		for(i=l;i<r;i++){
			t++;
			if(p1[j]<=p2[k]){
			
				a[i]=p1[j];
				j++;
			}
			else {
				a[i]=p2[k];
				k++;
			}
		} 
}
void mergesort(int *a,int l,int r)
{
		int mid;
		mid=(l+r)/2;
		if(l+1<r){
			mergesort(a,l,mid);
			mergesort(a,mid,r);
			merge(a,l,mid,r);
		}
}
int main()
{
		int a[500005];
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		mergesort(a,0,n);
		for(int i=0;i<n;i++){
			if(i)cout<<' ';
			cout<<a[i];
		}
		cout<<endl<<t<<endl;
		return 0;
}
