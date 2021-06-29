#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
vector<int> arr, tmp;
int cnt;

struct Card
{
	Card() {}
	char c;
	int v;
	//bool operator< (Card& other) { return v < other.v; }
	bool operator<= (Card& other) { return v <= other.v; }
	bool operator> (Card& other) { return !(*this <= other); }
	//bool operator>= (Card& other) { return !(*this < other); }
	//Card& operator= (const Card& other) { v = other.v; c = other.c; return *this; }
};

void swap(Card& a, Card& b) {
	swap(a.c, b.c);
	swap(a.v, b.v);
}

vector<Card> arrT, tmpT, tmpT2;


void print(vector<int>& arr) {
	int n = arr.size();
	for (int i = 0; i < n; ++i) {
		cout << arr[i];
		if (i != n - 1) cout << " ";
	}
	cout << endl;
}

void print(vector<Card>& arr) {
	int n = arr.size();
	for (int i = 0; i < n; ++i)
		cout << arr[i].c << " " << arr[i].v << endl;
}

void insert_sort(vector<int>& arr) {
	int n = arr.size();
	for (int i = 0; i < n; ++i) {
		for (int j = i; j > 0; --j) {
			if (arr[j - 1] > arr[j])
				swap(arr[j - 1], arr[j]);
		}
		print(arr);
	}
}

void bubble_sort(vector<int>& arr) {
	int n = arr.size();
	int cnt = 0;
	for (int i = 0; i < arr.size(); ++i) {
		for (int j = n - 1; j > i; --j) {
			if (arr[j] < arr[j - 1]) {
				swap(arr[j - 1], arr[j]);
				cnt++;
			}
		}
	}
	print(arr);
	cout << cnt << endl;
}

void select_sort(vector<int>& arr) {
	int n = arr.size();
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		int mi_idx = i;
		for (int j = i; j < n; ++j) {
			if (arr[j] < arr[mi_idx])
				mi_idx = j;
		}
		cnt += (i != mi_idx);
		swap(arr[i], arr[mi_idx]);
	}
	print(arr);
	cout << cnt << endl;
}

template<typename T>
void merge(vector<T> &arr, int a, int b, int c) {
	for (int i = a; i <= c; ++i)
		tmpT[i] = arr[i];

	int i = a;
	int j = b + 1;
	while (i <= b && j <= c) {
		cnt++;
		if (tmpT[i] <= tmpT[j]) arr[a++] = tmpT[i++];
		else arr[a++] = tmpT[j++];
	}
	while (i <= b) { arr[a++] = tmpT[i++]; cnt++; };
	while (j <= c) { arr[a++] = tmpT[j++]; cnt++; }
}

template<typename T>
void merge_sort(vector<T>& arr, int l, int r) {
	if (l < r) {
		int mid = l + (r - l) / 2;
		merge_sort(arr, l, mid);
		merge_sort(arr, mid+1, r);
		merge(arr, l, mid, r);
	}
}

// hoare
// lumuto
template<typename T>
int partition_lumuto(vector<T>& arr, int l, int r) {
	int i = l-1;
	int j = l;
	while (j <= r) {
		if (arr[j] <= arr[r])
			swap(arr[++i], arr[j]);
		++j;
	}
	return i;
}

template<typename T>
int partition_hoare(vector<T> &arr, int l, int r) {
	T so = arr[r];
	while (l < r) {
		while (l < r && arr[l] <= so) l++;
		if (l < r) arr[r--] = arr[l];
		while (l < r && arr[r] > so) r--;
		if (l < r) arr[l++] = arr[r];
	}
	arr[l] = so;
	return l;
}

template<typename T>
void quick_sort(vector<T> &arr, int l, int r) {
	if (l < r) {
		int p = partition_lumuto(arr, l, r);
		quick_sort(arr, l, p - 1);
		quick_sort(arr, p + 1, r);
	}
}

template<typename T>
void quick_sort2(vector<T> &arr, int l, int r) {
	if (l < r) {
		int p = partition_hoare(arr, l, r);
		quick_sort(arr, l, p - 1);
		quick_sort(arr, p + 1, r);
	}
}


int main() {
	int n;
	cin >> n;

	arrT.resize(n);
	tmpT.resize(n);
	cnt = 0;
	for (int i = 0; i < n; ++i)
		cin >> arrT[i].c >> arrT[i].v;
	vector<Card> ms_data = arrT;
	merge_sort(ms_data, 0, n-1);

	quick_sort(arrT, 0, n - 1);
	vector<Card> qs2_data = arrT;
	//quick_sort2(qs2_data, 0, (n - 1)/4);

	bool stable = true;
	for (int i = 0; i < n; ++i) {
		if (arrT[i].c != ms_data[i].c) {
			stable = false;
			break;
		}
	}
	cout << (stable ? "Stable" : "Not stable") << endl;

	for (int i = 0; i < n; ++i) {
		cout << arrT[i].c << " " << arrT[i].v << endl;
		//cout << arrT[i].c << " " << qs2_data[i].v << endl;
	}

	return 0;
}

