#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
void output_result(int a[], int n)
{
    for(int i=1; i<=n; i++) {
        if(i > 1)
            cout << " ";
        cout << a[i];
    }
    cout << endl;
}
int main()
{
	int n, a[105], i, j, flag = 0;
	cin >> n;
	for(i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	for(i = 1; i <= n - 1; i++){
		for(j = 1; j <= n - i; j++){
			if(a[j] > a[j+1]){
				swap(a[j], a[j+1]);
				flag++;
			}
		}
	}
	
	output_result(a, n);
	cout << flag << endl;
	return 0;
}
