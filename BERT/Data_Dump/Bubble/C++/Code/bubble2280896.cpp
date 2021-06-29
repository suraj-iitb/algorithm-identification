#include <iostream>
#include <vector>


void trace(std::vector<int> v) {
	std::string s;
	for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i) {
		if (i != v.end() - 1)
			std::cout << *i << " ";
		else
			std::cout << *i;
	}
	std::cout << std::endl;
}

int main() {
	
	{
		using namespace std;
		int n;

		cin >> n;

		vector<int> a;
		a.resize(n, 0);
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int c = 0;

		for (int i = 0; i < n; i++) {
			for (int j = n-1; j > i; j--) {
				if (a[j] < a[j - 1]) {
					int t = a[j];
					a[j] = a[j - 1];
					a[j - 1] = t;
					c++;
				}
			}
		}
		trace(a);
		cout << c << endl;

	}



	return 0;
}
