#include "iostream"
#include "algorithm"
#include "vector"
#include "stack"
#include "queue"
#include "string"

using namespace std;

int k = 5000001;

int a[5000001];
int b[5000001];
int c[5000001];

int couting_sort(int n)
{
	int i;

	for(i=0;i<n;i++){
		c[a[i]]++;
	}

	for(i=1;i<k;i++){
		c[i] = c[i] + c[i-1];
	}

	for(i=n-1;i>=0;i--){
		b[c[a[i]]-1] = a[i];
		c[a[i]]--;
	}

  	for(int i=0;i<n;i++) cout<< b[i] <<" \n"[i==n-1];

	return 0;
}
int main()
{
	long long n;

	cin >> n;

	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	
	for(int i=0;i<k;i++){
		c[i] = 0;
	}

	couting_sort(n);
	return 0;
}


