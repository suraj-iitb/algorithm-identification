#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

namespace {

	//const int NIL = -1;
	const int64_t INFTY = std::numeric_limits<int64_t>::max();

	class Graph {
	public:
		Graph() {}
		Graph(const vector<vector<int64_t>>& D) :
			D_(D)
		{
			n_ = D_.size();
		}

		vector<vector<int64_t>> warshallFloyd() {
			vector<vector<int64_t>> A_ = D_; // 最短距離を表す隣接行列

			//for (int i = 0;i < n_;i++) {
			//	for (int j = 0;j < n_;j++) {
			//		if (j > 0) {
			//			cout << " ";
			//		}
			//		if (A_[i][j] >= INFTY) {
			//			cout << "INF";
			//		}
			//		else {
			//			cout << A_[i][j];
			//		}
			//	}
			//	cout << endl;
			//}

			for (int k = 0;k < n_;k++) {
				for (int i = 0;i < n_;i++) {
					for (int j = 0;j < n_;j++) {
						int64_t b;
						if (A_[i][k] == INFTY || A_[k][j] == INFTY) {
							b = INFTY;
						}
						else {
							b = A_[i][k] + A_[k][j];
						}
						A_[i][j] = std::min(A_[i][j], b);
					}
				}

				//cout << "k=" << k << endl;
				//for (int i = 0;i < n_;i++) {
				//	for (int j = 0;j < n_;j++) {
				//		if (j > 0) {
				//			cout << " ";
				//		}
				//		if (A_[i][j] >= INFTY) {
				//			cout << "INF";
				//		}
				//		else {
				//			cout << A_[i][j];
				//		}
				//	}
				//	cout << endl;
				//}
			}

			return A_;
		}

	private:
		int n_ = 0;
		vector<vector<int64_t>> D_; // 距離を表す隣接行列

	};
}

int main()
{
	//init

	// input
	int n;
	std::cin >> n;
	vector<vector<int64_t>> D(n, vector<int64_t >(n, INFTY));
	for (int i = 0;i < n;i++) {
		D[i][i] = 0;
	}

	int m;
	std::cin >> m;
	for (int k = 0;k < m;k++) {
		int i, j, d;
		std::cin >> i >> j >> d;
		D[i][j] = d;
	}
	auto graph = Graph(D);

	vector<vector<int64_t>> A = graph.warshallFloyd();
	bool is_negative = false;
	for (int i = 0;i < n;i++) {
		for (int j = i;j < n;j++) {
			if (A[i][j]  == INFTY || A[j][i] ==INFTY) {
				continue;
			}
			else if (A[i][j]+ A[j][i] < 0) {
				is_negative = true;
				break;
			}
		}
	}
	if (is_negative) {
		cout << "NEGATIVE CYCLE" << endl;
	}
	else {
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				if (j > 0) {
					cout << " ";
				}
				if (A[i][j] >= INFTY) {
					cout << "INF";
				}
				else {
					cout << A[i][j];
				}
			}
			cout << endl;
		}
	}

	return 0;
}
