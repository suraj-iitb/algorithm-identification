#include"iostream"
using namespace std;
struct card
{
	char abc;
	int data;
};
void merge(card a[], int left, int mid, int right);
int partition(card a[],int p,int r)
{
	card t;
	int x = a[r].data;
	int i = p - 1;
	for(int j=p;j<r;++j)
		if (a[j].data <= x)
		{
			++i;
			t = a[j];
			a[j] = a[i];
			a[i] = t;
		}
	t = a[i + 1];
	a[i + 1] = a[r];
	a[r] = t;
	return i + 1;
}
void quicksort(card a[],int p,int r)
{
	if (p >= r)return;
	int q = partition(a, p, r);
	quicksort(a, p, q - 1);
	quicksort(a, q+1, r);
}
void mergesort(card a[], int left, int right)
{
	if (left == right)return;
	int mid = (left + right) / 2;
	mergesort(a, left, mid);
	mergesort(a, mid + 1, right);
	merge(a, left, mid + 1, right);
}
void merge(card a[], int left, int mid, int right)
{
	card* tmp = new card[right - left + 1];
	int i = left, j = mid, k = 0;
	while (i < mid && j <= right)
	{
		if (a[i].data <= a[j].data)tmp[k++] = a[i++];
		else tmp[k++] = a[j++];

	}
	while (i < mid)
	{
		tmp[k++] = a[i++];
	}
	while (j <= right)
	{
		tmp[k++] = a[j++];
	}
	for (i = 0, k = left; k <= right;)a[k++] = tmp[i++];
	delete[]tmp;
}
int main()
{
	int n;
	cin >> n;
	cin.get();
	card* a = new card[n];
	int i;
	for (i = 0; i < n; ++i)
		cin >> a[i].abc >> a[i].data;
	card* num1 = new card[n];
	for (i = 0; i < n; ++i)
	{
		num1[i] = a[i];
	}
	mergesort(a,0, n-1);
	quicksort(num1, 0,n-1);
	int flag = 1;
	for (i = 0; i < n; ++i)
		if (a[i].abc != num1[i].abc) {
			flag = 0; break;
		}
	if (flag == 0)cout << "Not stable" << endl;
	else cout << "Stable" << endl;
	for (i = 0; i < n; ++i)
		cout << num1[i].abc<<' '<<num1[i].data<<endl;
	return 0;
}

