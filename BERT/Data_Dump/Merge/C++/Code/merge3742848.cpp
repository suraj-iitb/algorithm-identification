
#include <iostream>
using namespace std;
//核心：分而治之
#define TOTAL  500000
#define  INFTY  1000000000//标志
int S[TOTAL];
int  t=0;
int L[(TOTAL / 2) + 2], R[(TOTAL / 2) + 2];
void merge(int x[], int left, int mid, int right)
{
	int n1, n2;

	n1 = mid - left;//左部分的元素个数+1；
	n2 = right - mid;//右部分的元素个数+1;
	
	
	for (int i = 0; i < n1; i++) L[i] = x[left+i];//先将原数组的值复刻过来，当然了这会占用大量的内存
	for (int i = 0; i < n2; i++) R[i] = x[mid+i];
	L[n1] = INFTY, R[n2] = INFTY;//将数组最后一个值均为一个极大的值
	int i = 0, j = 0;//最后那个用来算交换的次数
	for (int k = left; k <right; k++)//循环的次数
	{		t++;//计算总的交换次数；
		if (L[i]<= R[j])//若右边的数大于左边的数
			x[k] = L[i++];
		else
			x[k] = R[j++];

	}

}
void mergeSort(int x[], int left, int right)
{
	if (left + 1 < right)//非只有一个元素时
	{
		int mid = ((left + right) / 2);//分开两个部分进行递归
		mergeSort(x, left, mid);
		mergeSort(x, mid, right);
		merge(x, left, mid, right);

	}
	else
		return;
}
int main()
{
	int n = 0,input;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		S[i] = input;

	}
	mergeSort(S, 0, n);
	for (int i = 0; i < n; i++)
	{
		if (i)cout << " ";
		cout << S[i];
	}
	cout << endl << t<<endl;
	return 0;
}
