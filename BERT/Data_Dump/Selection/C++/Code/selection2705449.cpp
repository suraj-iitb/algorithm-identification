#include <iostream>
#include <vector>


using namespace std;

//変数デバッグ
#define DEB(variable) cout <<#variable <<"="<<variable<<endl
//for簡易表記(引数ミス防止) a<bにすること！
#define FOR(inc,a,b) for(int inc =(a);(inc)<(b);(inc)++) //incをaにし、b-a回(iがb未満 の間)処理を行う
#define DEFOR(de,a,b) for(int de =(a);(de)>(b);(de)--)

int sesort(vector<int> &V, int N) {
	
	int trade=0, min=0, space;

	FOR(i,0,N){
		
		min = i;
		FOR(j, i, N) {
			if (V[min]>V[j]) {
				min = j;
			}

		}
	
		
		if (i != min) {
			space = V[min];
			V[min] = V[i];
			V[i] = space;
			trade++;
		}
	}	
	return trade;
}

int main() {
	int n;
	
	cin >> n;

	vector<int> v(n, 0);

	FOR(i, 0, n) {
		cin >> v[i];
	}

	int trade = sesort(v,n);

	FOR(k, 0, n - 1) {
		cout << v[k] << " ";
	}


	cout << v[n - 1] << "\n"<<trade<<endl;
	return 0;
}
