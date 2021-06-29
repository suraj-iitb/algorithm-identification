#include"iostream"
using namespace std;
void merge(int a[],int left,int mid,int right);
void mergesort(int a[], int left, int right);
int s = 0;
int main()
{
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	mergesort(a, 0, n - 1);
	cout << a[0];
	for (int i = 1; i < n; ++i)
		cout<<' '<<a[i];
	cout << endl << s << endl;
	delete[]a;
	return 0;
}
void mergesort(int a[], int left, int right)
{
	if (left== right)return;
	int mid = (left + right)/2;
	mergesort(a, left, mid);
	mergesort(a, mid+1, right);
	merge(a, left, mid+1, right);
}
void merge(int a[], int left, int mid, int right)
{
	int* tmp = new int[right - left + 1];
	int i = left, j = mid, k = 0;
	while (i < mid && j <= right)
	{
		if (a[i] < a[j])tmp[k++] = a[i++];
		else tmp[k++] = a[j++];
		s++;
	}
	while (i < mid)
	{
		tmp[k++] = a[i++]; s++;
	}
	while (j <= right)
	{
		tmp[k++] = a[j++]; s++;
	}
	for (i = 0, k = left; k <= right;)a[k++] = tmp[i++];
	delete[]tmp;
}
