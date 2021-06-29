#include <bits/stdc++.h>
using namespace std;
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<string> vs;

const int INF = 1000000000;

void printVi(vi &ar) {
	for (int i = 0; i < (int)ar.size(); i++) {
		if (i > 0) cout << " ";
		cout << ar[i];
	}
	cout << "\n";
}

int main() {FIN
    
    int n, i, j, k;
    cin >> n;
    vi ns(n);
    
    for (i = 0; i < n; i++)
		cin >> ns[i];
	
	printVi(ns);
	for (i = 1; i < n; i++) {
		k = ns[i];
		for (j = i - 1; j >= 0; j--) {
			if (ns[j] > k)
				swap(ns[j], ns[j + 1]);
			else
				break;
		}
		printVi(ns);
	}
    
    return 0;
}

