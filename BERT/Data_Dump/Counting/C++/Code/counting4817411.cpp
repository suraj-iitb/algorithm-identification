/*
时间:2020-9-6
书籍：算法和数据结构
内容：计数排序     稳定排序
页数：P133
*/
#include<iostream>
using namespace std;
const int mmax = 2000000;
const int Amax = 10000;
int Aarray[mmax] = { 0 };
int Barray[mmax] = { 0 };
int Carray[Amax] = { 0 };
void CountingSort(int n)
{
	for (int i = 0; i < n; ++i)
		++Carray[Aarray[i]];
	for (int i = 1; i < Amax; ++i)
		Carray[i] += Carray[i-1];
	for (int i = 0; i < n; ++i)
	{
		Barray[Carray[Aarray[i]] - 1] = Aarray[i];
		--Carray[Aarray[i]];
	}

}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> Aarray[i];
	CountingSort(n);
	for (int i = 0; i < n - 1; ++i)
		cout << Barray[i] << " ";
	cout << Barray[n-1] << endl;
	return 0;
}
