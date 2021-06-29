#include <iostream>
using namespace std;
void Bubble_sort (int a[],int n);
int count=0;
int main()
{
//	freopen("E:\\编程\\程序\\挑战程序设计竞赛\\2\\测试文档\\Bubble_sort.txt","r",stdin);
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
	 cin >> a[i];
	Bubble_sort(a,n); 
	for(int i=0;i<n;i++) {
	 if(i>0)
	 cout << " ";
	 cout << a[i];
    }
	cout << endl;
	cout << count <<endl ;
	return 0;
}
void Bubble_sort (int a[],int n)
{
	for(int i=0;i<n;i++)
	 for(int j=n-1;j>=i;j--) {
	 	if(a[j]<a[j-1]) {
	 		int t=a[j];
	 		a[j]=a[j-1];
	 		a[j-1]=t;
	 		count++;
		 }
	 }
}
