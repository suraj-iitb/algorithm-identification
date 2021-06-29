#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

void output_buffer(const vector<int>& buffer)
{
	cout << buffer[0];
	for (int i = 1; i < buffer.size(); ++i) {
		cout << ' ' << buffer[i];
	}
	cout << endl;
}

void insert_sort(vector<int>& buffer)
{
	for (int j = 1; j < buffer.size(); ++j) {
		int v = buffer[j];
		int i = j - 1;
		for (; i >= 0 && buffer[i] > v; --i) {
			buffer[i + 1] = buffer[i];
		}
		buffer[i + 1] = v;
		output_buffer(buffer);
	}
}

int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);
	
	int N = 0;
	cin >> N;
	vector<int> buffer(N);
	copy(istream_iterator<int>(cin), istream_iterator<int>(), buffer.begin());
	output_buffer(buffer);
	insert_sort(buffer);
	return 0;	
}
