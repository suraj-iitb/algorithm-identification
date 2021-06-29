#include<iostream>
#include<cstdlib>

using namespace std;

struct card{
	char s;
	int n;
	int o;
}C[100000];


int partition(card *a, int p, int r)
{
	int x=a[r].n;
	int i=p-1;
	for(int j=p; j<r; j++) {
		if(a[j].n<=x) {
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i+1], a[r]);
	return i+1;
}

void quicksort(card *a, int p, int r)
{
	if(p<r) {
		int q=partition(a, p, r);
		quicksort(a, p, q-1);
		quicksort(a, q+1, r);
	}
}

bool isStable(card *a, int n)
{
	for(int i=1; i<n; i++) if(a[i-1].n==a[i].n && a[i-1].o>a[i].o) return false;

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	char str[16];
	cin.getline(str, 16);
	int n=atoi(str);

	for(int i=0; i<n; i++) {
		cin.getline(str, 16);
		C[i]=card{str[0], atoi(str+2), i};
	}
	quicksort(C, 0, n-1);

	cout<<(isStable(C, n) ? "Stable\n": "Not stable\n");
	for(int i=0; i<n; i++) cout<<C[i].s<<' '<<C[i].n<<'\n';
	return 0;
}

