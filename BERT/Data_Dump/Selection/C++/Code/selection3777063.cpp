#include<iostream>
#include<cstdio>

using namespace std;

const int maxn = 100 + 10;

int main()
{
    int A[maxn];
    int n;
    while (scanf("%d",&n)!= EOF){
        int cot = 0 ;
        for (int i = 1 ; i <= n ; i ++){
            cin >> A[i];
        }
        for (int i = 1 ; i <= n ; i ++){
            int minA = A[i];
            int minj = i;
            for (int j = i + 1 ; j <= n ; j ++){
                if (A[j] < minA){
                    minA = A[j];
                    minj = j;
                }
            }
            if (minj != i){
                cot ++;
                int t = A[i];
                A[i] = A[minj];
                A[minj] = t;
            }
        }
        for (int i = 1 ; i <= n ; i ++){
            cout << A[i];
            if (i != n)
                cout << " ";
        }
        cout << endl;
        cout << cot << endl;
    }
    return 0;
}

