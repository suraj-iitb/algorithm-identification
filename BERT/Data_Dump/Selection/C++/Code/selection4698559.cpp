/*
时间:2020-7-25
书籍：算法和数据结构
内容：选择排序
页数：P44
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
void selectionSort(int a[], int length)
{
	int count = 0;
	for (int i = 0; i < length; ++i)
	{
		int min = i;
		for (int j = i + 1; j < length; ++j)
			if (a[j] < a[min])
				min = j;
		if (i != min)
		{
			++count;
			swap(a[i], a[min]);
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
	selectionSort(a, n);
	delete[]a;
	return 0;
}
