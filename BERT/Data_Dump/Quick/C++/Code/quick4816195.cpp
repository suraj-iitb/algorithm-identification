/*
时间:2020-8-13
书籍：算法和数据结构
内容：快速排序
页数：P129
*/
#include<iostream>
using namespace std;
const int Cmax = 100000;
const int Nmax = 1000000001;
class Card
{
public:
	char suit;
	int value;
	Card() {
		suit = ' ';
		value = 0;
	}
	Card& operator=(Card& c)
	{
		this->suit = c.suit;
		this->value = c.value;
		return *this;
	}
};
Card N1[Cmax / 2 + 2];
Card N2[Cmax / 2 + 2];
//归并排序   稳定排序
void mergeSort(Card A[], int left, int mid, int right)
{
	int n1 = mid - left;
	int n2 = right - mid;
	for (int i = 0; i < n1; ++i)
		N1[i] = A[left + i];
	N1[n1].value = Nmax;
	for (int j = 0; j < n2; ++j)
		N2[j] = A[mid + j];
	N2[n2].value = Nmax;
	int i = 0, j = 0;
	int cur = left;
	for (; cur < right;++cur)
	{
		if (N1[i].value <= N2[j].value)
		{
			A[cur] = N1[i];
			++i;
		}
		else
		{
			A[cur] = N2[j];
			++j;
		}
	}

}
void merge(Card A[], int left, int right)            //排序的时候这个函数排序时下标包括left，不包括right
{
	if (left + 1 >= right)
		return;
	int mid = (left + right) / 2;
	merge(A, left, mid);
	merge(A, mid, right);
	mergeSort(A, left, mid, right);
}
//快速排序
int partition(Card A[], int left, int right)         //以right为基准进行分割        排序的时候包含left和right的下标
{
	Card base = A[right];
	int p = left;
	for (int j = left; j <right; ++j)             //j不到right，注意取值范围！！！
	{
		if (A[j].value <= base.value)                    //<=！！！
		{
			swap(A[p], A[j]);
			++p;
		}
	}
	swap(A[p], A[right]);
	return p;                     //返回分割点！！！！1
}
void quickSort(Card A[],int left,int right)
{
	if (left >= right)
		return;
	int p=partition(A, left, right);
	quickSort(A, left, p-1);
	quickSort(A, p + 1, right);
}
int main()
{
	int n;
	cin >> n;
	Card* A = new Card[n];
	Card* B = new Card[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> A[i].suit >> A[i].value;
		B[i] = A[i];
	}
	merge(A, 0, n);
	quickSort(B, 0, n - 1);
	bool judge = true;
	for (int i = 0; i < n; ++i)
	{
		if (A[i].suit != B[i].suit)
		{
			judge = false;
			break;
		}
	}
	if (judge)
		cout << "Stable" << endl;
	else
		cout << "Not stable" << endl;
	for (int i = 0; i < n; ++i)
		cout << B[i].suit << " " << B[i].value << endl;
	return 0;
}
