#include <iostream>
#include <algorithm>
using namespace std;

int BubbleSort(int* a, int n) {
    int flag = 1;
    int num = 0;
    while (flag == 1) {
        flag = 0;
        for (int j=n-1; j>0; j--){
            if ( a[j] < a[j-1] ){
                swap(a[j], a[j-1]); 
                num++; 
                flag = 1;
            }
        }
    }
    return num;
}

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n;
    int a[n];
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    int* ap;
    ap = a;

    k = BubbleSort(ap, n);

    for (int i=0; i<n; i++){
        if (i == n-1){ cout << a[i] << endl; }
        else{ cout << a[i] << " "; }
    }

    cout << k << endl;

    return 0;
}

