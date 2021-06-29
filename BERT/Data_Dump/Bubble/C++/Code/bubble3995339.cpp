#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n)
		cin >> a[i];
	int count = 0;
int	flag = 1;
while (flag == 1)
{
	flag = 0;
	for (int j = n - 1; j >= 1; j--) {
		if (a[j] < a[j - 1]) {
			int x = a[j];
			a[j] = a[j - 1];
			a[j - 1] = x;
			flag = 1;
			count++;
		}
}
}
rep(i, n) {
	if (i != n - 1)
		cout << a[i] << " ";
	else
		cout << a[n - 1] << endl;
}
cout << count << endl;
}
