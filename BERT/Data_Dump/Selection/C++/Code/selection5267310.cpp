#include <iostream>
using namespace std;
void Selection_sort (int a[],int n);
int count=0;
int main()
{
//	freopen ("E:\\编程\\程序\\挑战程序设计竞赛\\2\\测试文档\\Selection_sort.txt","r",stdin);
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
	 cin >> a[i];
    Selection_sort(a,n);
    for(int i=0;i<n;i++) {
    	if(i)
    	cout << " ";
    	cout << a[i];
	}
	cout << endl;
	cout << count <<endl;
	return 0;
}
void Selection_sort (int a[],int n)
{
	int min;
	for(int i=0;i<n;i++) {
	 min=i;
	 for(int j=i+1;j<n;j++) {
	 	if(a[j]<a[min]) {
	 	min=j;
		}
     }
	 if(i!=min) {
	 swap(a[min],a[i]);
	 count++;
	 }
    }
}

