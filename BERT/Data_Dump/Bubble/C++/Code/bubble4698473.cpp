/*
时间:2020-7-25
书籍：算法和数据结构
内容：冒泡排序
页数：P40
*/
#include<iostream>
using namespace std;
void printArray(int a[],int length)
{
	for (int i = 0; i < length - 1; ++i)
		cout << a[i] << " ";
	cout << a[length-1];                       //防止行元素后的空格多余导致PE
	cout << endl;                             //每一行结束输出要换行

}
void bubbleSort(int a[], int length)
{
	bool flag = true;               //排序提前完成时用来判断，避免不必要的比较。
	int temp=0;
	int count = 0;
	for (int i = 0; i < length && flag; ++i)
	{
		flag = false;                                          
		for (int j = 0; j < length - i - 1; ++j)
		{
			if (a[j] > a[j + 1])
			{
				++count;
				flag = true;
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	printArray(a, length);
	cout << count << endl;
}
int main()
{
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	bubbleSort(a, n);
	delete[]a;
	return 0;
}
