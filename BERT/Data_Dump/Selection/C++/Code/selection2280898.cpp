# include <iostream>
# include <vector>

void trace(std::vector<int> v) {
	for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i){
		if (i != v.end() - 1)
			std::cout << *i << " ";
		else
			std::cout << *i << std::endl;
	}
}


int main(){

	int n;
	std::cin >> n;

	std::vector<int> a;
	a.resize(n, 0);

	for (int i = 0; i < n; i++)
		std::cin >> a[i];

	int c = 0;
	for (int i = 0; i < n; i++) {
		int min = i;
		bool need_swap = false;
		for (int j = i; j < n; j++) {
			if (a[j] < a[min]) {
				min = j;
				need_swap = true;
			}

		}
		int t = a[i];
		a[i] = a[min];
		a[min] = t;
		if (need_swap)
			c++;
	}

	trace(a);
	std::cout << c << std::endl;




	return 0;
}
