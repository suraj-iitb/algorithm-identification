#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<tgmath.h>
using namespace std;

void insertionSort(int a[],int n){
    for (int i = 1; i < n; i++)
    {
        int v = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > v) 
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        for (int i = 0; i < n; i++)
        {
            cout << a[i];
            if(i != n-1) cout << " ";
            else cout << endl;
        }
    }
}

int main(){
    int a[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
        if(i != n-1) cout << " ";
        else cout << endl;
    }
    insertionSort(a,n);
}
