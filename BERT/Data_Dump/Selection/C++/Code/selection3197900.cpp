#include <iostream>
int main()
{
	using namespace std;
	
	int N;
	int oper = 0;
	cin >> N;
	int Sort[N];
	for (int i = 0; i < N; i++) cin >> Sort[i];
	
	for (int i = 0; i < N; i++){
		int minj = i;
		for (int j = i; j < N; j++){
			if (Sort[j] < Sort[minj]){
				minj = j;
			}	
		}
			int v = 0;
			v = Sort[i];
			Sort[i] = Sort[minj];
			Sort[minj] = v;
			if (Sort[i] != Sort[minj]) oper++;
	}
	for (int i = 0; i < N; i++) {
		if (i) cout << " ";
		cout << Sort[i];
			}
	cout << endl << oper << endl;
	return 0;
}
