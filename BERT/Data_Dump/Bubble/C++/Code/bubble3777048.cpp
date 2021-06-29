#include<iostream>
#include<cstdio>

using namespace std;

const int maxn = 100 + 10;

int main()
{
    int A[maxn];
    int n;
    while (scanf("%d",&n)!= EOF){
        int cot = 0;
        for (int i = 1 ; i <= n ; i ++){
            cin >> A[i];
        }

        for (int i = 1 ; i <= n ; i ++){
            for (int j = n ; j >= i + 1 ; j --){
                if (A[j] < A[j - 1]){
                    int t = A[j];
                    A[j] = A[j - 1];
                    A[j - 1] = t;
                    cot ++;
                }
            }
        }

        for (int i = 1 ; i <= n ; i ++){
            cout << A[i] ;
            if (i != n){
                cout << " ";
            }
        }
        cout << endl;
        cout << cot << endl;

    }
    return 0;
}

