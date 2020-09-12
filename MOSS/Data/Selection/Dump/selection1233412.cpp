#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <map>
#include <functional>
#include <iomanip>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <typeinfo>
#define PI 3.14159265359
#define INF 99999999
#define rep(i, n) for(int i=0; i<n; i++)
#define REP(n) rep(i, n)
#define EPS 1e-10
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;
typedef pair<int, int> P;

bool isLeap(int y);
ll gcd(ll a, ll b);
ll lcm(ll a, ll b);
double distanceAB(double xa, double ya, double xb, double yb);
void trace(int A[], int N);

/*
class Target
{
public:
	vector <string> draw(int n)
	{

	}
};
*/


int selectionSort(int A[], int N)
{
	int i, j, t, sw = 0, mini;
	rep(i, N - 1)
	{
		mini = i;
		for (j=i; j<N; j++)
		{
			if (A[j] < A[mini]) mini = j;
		}
		t = A[i]; A[i] = A[mini]; A[mini] = t;
		if (i != mini) sw++;
	}
	return sw;
}


int main()
{
	int A[100], N, i, sw;
	
	scanf("%d", &N);
	rep(i, N) scanf("%d", &A[i]);
	
	sw = selectionSort(A, N);
	
	rep(i, N)
	{
		if (i > 0) printf(" ");
		printf("%d", A[i]);
	}
	printf("\n");
	printf("%d\n", sw);
	
	return 0;
}


bool isLeap(int y)
{
	return y % 400 == 0
						? true : y % 100 == 0
						? false : y % 4 == 0
						? true : false;
}

ll gcd(ll a, ll b)
{
	return (b > 0) ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b)
{
	return a / gcd(a, b) * b;
}

void trace(int A[], int N)
{
	REP(N)
	{
		if (i > 0) cout << " ";
		cout << A[i];
	}
	cout << endl;
}

double distanceAB(double xa, double ya, double xb, double yb)
{
	return sqrt((xb-xa)*(xb-xa) + (yb-ya)*(yb-ya));
}
