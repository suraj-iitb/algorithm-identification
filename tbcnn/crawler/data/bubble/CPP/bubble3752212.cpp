#include<iostream>
using namespace std;

//使用flag的冒泡排序法(升序),返回交换次数
int bubblesort(int A[], int N)
{
	int sw = 0;//记录次数
	bool flag = 1;
	for( int i = 0; flag; i++)
	{
		flag = 0;
		for (int j = N - 1; j >= i + 1; j--)//从最后一项查找
		{
			if (A[j] < A[j-1]) 
			{
				//交换相邻元素
				swap(A[j], A[j - 1]);
				flag = 1;
				sw++;
			}
		}
	}
	return sw;
}

int main()
{
	int A[100], N, sw;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];

	sw = bubblesort(A, N);
	for (int i = 0; i < N; i++)
	{
		if (i)cout << " ";
		cout << A[i];
	}
	cout << endl;
	cout << sw << endl;
	return 0;

}
