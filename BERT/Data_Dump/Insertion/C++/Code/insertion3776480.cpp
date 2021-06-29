#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

const int maxn = 100 + 10;

int main()
{
    int A[maxn];
    int n ;
    cin >> n;
    for (int i = 1 ; i <= n ; i ++){
        cin >> A[i];
    }
    for (int i = 1 ; i <= n ; i ++){
            cout << A[i];
            if (i != n){
                 cout << " ";
            }
        }
        cout << endl;
    for (int i = 2 ; i <= n ; i ++){
        int j = i - 1;
        int key = A[i];
        while (j >= 1 && A[j] > key){
            A[j + 1] = A[j];
            j --;
            A[j + 1] = key;
        }
        for (int i = 1 ; i <= n ; i ++){
            cout << A[i];
            if (i != n){
                 cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

