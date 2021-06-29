#include <iostream>
#include <vector>


using namespace std;

//変数デバッグ
#define DEB(variable) cout <<#variable <<"="<<variable<<endl
//for簡易表記(引数ミス防止) a<bにすること！
#define FOR(inc,a,b) for(int inc =(a);(inc)<(b);(inc)++) //incをaにし、b-a回(iがb未満 の間)処理を行う
#define DEFOR(de,a,b) for(int de =(a);(de)>(b);(de)--)

int main() {
	int n;
	int space;
	cin >> n;

	vector<int> v(n, 0);

	FOR(i, 0, n) {
		cin >> v[i];
	}

	FOR(i, 1, n) {
FOR(k, 0, n - 1) {
					cout << v[k] << " ";
				}
				cout << v[n-1] << endl;
		FOR(j, 0, i) {
			if (v[i] < v[j]) {
				space = v[i];
				DEFOR(k, i, j) {
					v[k] = v[k - 1];
				}v[j] = space;
				
			}
		}
		
	}
	FOR(k, 0, n - 1) {
		cout << v[k] << " ";
	}
	cout << v[n - 1] << endl;
	return 0;
}
