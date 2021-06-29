#include <iostream>
#include <algorithm>
#define max 100000
using namespace std;
struct card
{
  char suit;
  int vaule;	
};
card a1[max],a2[max];
void Quick_sort(card a[],int p,int r);
int Partition(card a[],int p,int r);
void Merge_sort(card b[],int left,int right);
void Merge(card b[],int left,int mid,int right);
int main()
{
//	freopen ("E:\\编程\\程序\\挑战程序设计竞赛\\2\\测试文档\\Quick_sort.txt","r",stdin);
	int n,flag=1;
	cin >> n;
	card a[n];
	card b[n];
	for(int i=0;i<n;i++)
	 cin >> a[i].suit >> a[i].vaule;
	for(int i=0;i<n;i++)
	 b[i]=a[i];
	Quick_sort(a,0,n-1);
	Merge_sort(b,0,n);
    for(int i=0;i<n;i++) 
     if(a[i].suit!=b[i].suit) {
     	flag=0;
     	break;
	 }
    if(flag)
    cout << "Stable" << endl;
    else
    cout << "Not stable" << endl;
	for(int i=0;i<n;i++) {
		cout << a[i].suit << " " << a[i].vaule << endl;
	}
	return 0;
}
void Quick_sort(card a[],int p,int r)
{
	if (p<r) {
		int q;
		q=Partition(a,p,r);
		Quick_sort(a,p,q-1);
		Quick_sort(a,q+1,r);
	}
}
int Partition(card a[],int p,int r)
{
	int x=a[r].vaule,i=p-1;
	for(int j=p;j<r;j++) {
		if(a[j].vaule<=x) {
			i++;
			swap(a[j],a[i]);
		}
	}
	swap(a[i+1],a[r]); 
	return i+1;
}
void Merge_sort(card b[],int left,int right)
{
	if(left+1 < right) {
		int mid=left+(right-left)/2;
		Merge_sort(b,left,mid);
		Merge_sort(b,mid,right);
		Merge(b,left,mid,right);
	}
}
void Merge(card b[],int left,int mid,int right)
{
	int n1=mid-left,n2=right-mid;
	for(int i=0;i<n1;i++) a1[i]=b[left+i];
	for(int i=0;i<n2;i++) a2[i]=b[mid+i];
	a1[n1].vaule=a2[n2].vaule=max;
	int j=0,k=0;
	for(int i=left;i<right;i++) {
		if(a1[j].vaule>a2[k].vaule)
		b[i]=a2[k++];
		else
		b[i]=a1[j++];
	}
}
