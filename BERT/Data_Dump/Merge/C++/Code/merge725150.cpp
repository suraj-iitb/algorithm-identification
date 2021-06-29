#include <iostream>
#include <vector>
using namespace std;
vector<int> m;
int c=0;
void Merge(int left,int mid,int right)
{
	int i,j;
	int n1=mid-left;
	int n2=right-mid;
	vector<int> L(n1+1);
	vector<int> R(n2+1);
	for(i=0;i<n1;i++)	L[i]=m[left+i];
	for(i=0;i<n2;i++) R[i]=m[mid+i];
	L[n1]=1000000001;
	R[n2]=1000000001;
	i=0;j=0;
	for(int k=left;k<right;k++){
		if(L[i]<=R[j]){
			m[k]=L[i];
			i+=1;
		}
		else{
			m[k]=R[j];
			j+=1;
		}
		c+=1;
	}
}
void Mergesort(int left,int right)
{
	int mid;
	if(left+1<right){
		mid=(left+right)/2;
		Mergesort(left,mid);
		Mergesort(mid,right);
		Merge(left,mid,right);
	}
}
int main(void)
{
	int n;
	cin >> n;
	m.resize(n);
	for(int i=0;i<n;i++) cin >> m[i];
	Mergesort(0,n);
	cout << m[0];
	for(int i=1;i<m.size();i++) cout << " " << m[i];
	cout << endl << c << endl;
	return 0;
}
