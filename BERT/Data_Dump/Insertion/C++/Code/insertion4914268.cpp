#include<bits/stdc++.h>

using namespace std;

void insertionSort(int a[], int n) {
	for(int i=1; i<n; ++i) {
		int j = i-1, v = a[i];
		while(j>=0 && a[j]>v) {
			a[j+1] = a[j];
			--j;
		}
		a[j+1] = v;
    for(int i=0;i<n;i++)
        if(i<n-1)
        {cout<<a[i]<<" ";}
        else
        {cout<<a[i];}
    cout<<endl;
}
}


int main()
{

	int n, a[110];
	cin>>n;
	for(int i=0; i<n; ++i)
        cin>>a[i];



    for(int i=0;i<n;i++)
        if(i<n-1)
        {cout<<a[i]<<" ";}
        else
        {cout<<a[i];}
    cout<<endl;

	insertionSort(a, n);


	return 0;
}

