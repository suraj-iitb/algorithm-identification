#include <vector>
#include <iostream>

using namespace std;

int comp = 0;

void merge(vector<int>& vec, size_t start, size_t start2, size_t end)
{
	size_t curr = 0;
	int finish = 0;
	vector<int> temp1;
	vector<int> temp2;
	temp1.reserve(start2-start);
	temp2.reserve(end-start2);
	for (size_t i=start; i<start2; i++) temp1.push_back(vec[i]);
	for (size_t i=start2; i<end; i++) temp2.push_back(vec[i]);

	size_t c1 = 0;
	size_t c2 = 0;
	for (size_t k=0; k<end-start; k++) {
		comp++;
		if (finish == 2) {
			vec[k+start] = temp1[c1];
			c1++;
			continue;
		} else if (finish == 1) {
			vec[k+start] = temp2[c2];
			c2++;
			continue;
		}

		if (temp1[c1] > temp2[c2]) {
			vec[k+start] = temp2[c2];
			c2++;
			if (c2 >= end-start2) finish = 2;
		} else {
			vec[k+start] = temp1[c1];
			c1++;
			if (c1 >= start2-start) finish = 1;
		}
	}

}

void mergesort(vector<int>& vec, size_t start, size_t end)
{
	if (start + 1 >= end) return;
	size_t mid = (start + end) / 2;
	mergesort(vec, start, mid);
	mergesort(vec, mid, end);
	merge(vec, start, mid, end);
}

int main(void)
{
	int N;
	cin >> N;
	vector<int> S;
	for (int i=0; i<N; i++) {
		int s;
		cin >> s;
		S.push_back(s);
	}
	mergesort(S, 0, N);

	for (size_t i=0; i<N; i++) {
		if (i != 0) cout << " ";
		cout << S[i];
	}
	cout << endl << comp << endl;
}
