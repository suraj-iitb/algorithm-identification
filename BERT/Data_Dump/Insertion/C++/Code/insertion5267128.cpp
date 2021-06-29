#include <iostream>
using namespace std;
void Insertion_sort (int a[],int n);
int main()
{
//	freopen("E:\\编程\\程序\\挑战程序设计竞赛\\2\\测试文档\\Insertion_sort.txt","r",stdin);
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
	 cin >> a[i];
	for(int i=0;i<n;i++) {
	 if(i>0)
	 cout << " ";
	 cout << a[i] ;
    }
    cout << endl;
	Insertion_sort(a,n);
    return 0;
}
void Insertion_sort (int a[],int n)
{
	for(int i=1;i<n;i++ ) {
		int k = i;
	  for(int j=i-1;j>=0;j--) {
	  	if(a[k]<a[j]) {
	  		int t=a[k];
	  		a[j+1]=a[j];
	  		a[j]=t;
	  		k--;
	  	}
	  }
	  for(int i=0;i<n;i++) {
	  	if(i>0)
	  	cout << " ";
	  	cout << a[i] ;
      }
      cout << endl;
	}
}
