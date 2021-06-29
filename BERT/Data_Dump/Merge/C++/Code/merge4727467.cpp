/*
时间:2020-7-31
书籍：算法和数据结构
内容：归并排序
页数：P121 
*/
#include<iostream>
using namespace std;
int cnt;
const int Max =99999999999;                //最大值
const int MAX2 = 500000;
int N1[MAX2 / 2 + 2];
int N2[MAX2 / 2 + 2];                     //在merge中使用固定长的数组，使用共同一个数组。
void merge(int A[],int n,int left,int mid,int right)   //对于长度为n的数组，left=0；right=n，right不是n-1,不然接下来的算法无法包括mid
{
	int n1, n2;
	n1 = mid - left;
	n2 = right - mid;
	for (int i = 0; i < n1; ++i)
		N1[i] = A[left + i];
	N1[n1] = Max;
	for (int i = 0; i < n2; ++i)
		N2[i] = A[mid + i];
	N2[n2] = Max;                             //最后一个储存单元用于存取最大值，以防后面排序时数组下标越界
	int i = 0, j = 0;
	for (int k = left; k < right; ++k)
	{
		++cnt;
		if (N1[i] <= N2[j])
		{
			A[k] = N1[i];
			++i;
		}
		else
		{
			A[k]=N2[j];
			++j;
		}
	}
;
}
void mergeSort(int A[],int n, int left, int right)
{
	int mid = (left + right) / 2;
	if (left + 1 >= right)                  //注意递归结束的条件
		return;
	mergeSort(A, n, left, mid);
	mergeSort(A, n, mid, right);
	merge(A, n, left, mid, right);
	return;

}
int main() 
{
	int n;
	cin >> n;
	int* A = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> A[i];
	mergeSort(A, n, 0, n);
	for (int i = 0; i < n - 1; ++i)
		cout << A[i] << " ";
	cout << A[n - 1] << endl;
	cout << cnt << endl;
	return 0;
}
