#include <iostream>
#include <cstdio>

using namespace std;

void mySwap(int &a, int &b, int &count) {
    int t = a; a = b; b = t;
    count++;
    return;
}

int main() {
    int a[101];
    int minj, n;
    int count = 0;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 0; i < n; i++) {
        minj = i;
        for(int j = i; j < n; j++) {
            if(a[j] < a[minj]) minj = j;
        }
        if(i!=minj) mySwap(a[i], a[minj], count);
    }
    for(int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if(i != n -1) printf(" ");
        else printf("\n");
    }
    cout << count << endl;
    return 0;
}
