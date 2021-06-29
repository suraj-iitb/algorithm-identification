#include<iostream>
using namespace std;int n;void d(int *a, bool f){for(int k=0;k<n;k++){if(f)cin >> a[k];cout << a[k];cout << (k == n-1?"\n":" ");}}int main(){cin >> n;int a[n];d(a,1);for(int i=0;i<n-1;i++){int j=i;while(j>=0&&a[j]>a[j+1]){swap(a[j],a[j+1]);j--;}d(a,1);}return 0;}

