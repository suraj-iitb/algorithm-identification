#include <iostream>
using namespace std;
int main()
{
	int N,aray[100];
	int t_count = 0;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> aray[i];
	int flag = 1;
	while (flag) {
		flag = 0;
		for (int j = N-1; j >= 1; j--) {
			if (aray[j] < aray[j - 1]) {
				int temp;
				temp = aray[j];
				aray[j] = aray[j - 1];
				aray[j - 1] = temp;
				t_count += 1;
				flag = 1;
			}
		}
	}
	for (int k = 0; k < N; k++) {cout << aray[k];
        if(k != N-1)cout << " ";
}
	cout << endl << t_count << endl;
    return 0;
}
