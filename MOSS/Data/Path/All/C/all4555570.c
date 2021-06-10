#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

int min(int x, int y)
{
	return x>y ? y : x;
}

int main ()
{
	int n, m, r;
	std::cin >> n >> m;
	
	int** D = new int*[n];
	for (int i=0; i<n; i++) D[i] = new int[n];
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) D[i][j] = (i==j) ? 0 : INT_MAX;
	}
	
	for (int k=0; k<m; k++) {
		int i, j, w;
		std::cin >> i >> j >> w;
		D[i][j] = min(D[i][j], w);
	}
	
	for (int k=0; k<n; k++) {
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				if (D[i][k] == INT_MAX || D[k][j] == INT_MAX) continue;
				if (D[i][j] > D[i][k] + D[k][j]) D[i][j] = D[i][k] + D[k][j];
			}
		}
	}
	
	bool negative_cycle = false;
	for (int i=0; i<n; i++) {
		if (D[i][i] < 0) {
			negative_cycle = true; break;
		}
	}
	
	if (negative_cycle) {
		std::cout << "NEGATIVE CYCLE" << std::endl;
	}
	else {
		for (int i=0; i<n; i++) {
			if(D[i][0] < INT_MAX) std::cout << D[i][0];
			else std::cout << "INF";
			for (int j=1; j<n; j++) {
				if(D[i][j] < INT_MAX) std::cout << " " << D[i][j];
				else std::cout << " INF";
			}
			std::cout << std::endl;
		}
	}

	
	return 0;
}

