#include <bits/stdc++.h>
using namespace std;
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<string> vs;

const int INF = 1000000000;
const int MOD = 1000000007;

int main() {FIN
    
    int n, i, j, k, sw = 0;
    cin >> n;
    vi ar(n);
    for (i = 0; i < n; i++)
		cin >> ar[i];
		
	for (i = 0; i < n - 1; i++) {
		k = i;
		for (j = i + 1; j < n; j++) {
			if (ar[j] < ar[k])
				k = j;
		}
		if (k != i) {
			swap(ar[i], ar[k]);
			sw++;
		}
	}
	
	for (i = 0; i < n; i++) {
		if (i > 0) cout << " ";
		cout << ar[i];
	}
	cout << "\n" << sw << "\n";
    
    return 0;
}

