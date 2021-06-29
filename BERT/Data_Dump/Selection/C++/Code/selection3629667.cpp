#include<iostream>
#include<math.h>

using namespace std;

const long MIN = -1234567890;

long gcd(long n, long m) {
    if (n < m)swap(n, m);
    if (n == m || m == 0)return n;
    return gcd(m, n % m);
}

long pri(){
    long ans = 0;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int m;
        bool flag = false;
        cin >> m;
        for(int j = 2; j <= sqrt(m); j++){
            if(m % j == 0) {
                flag = true;
                break;
            }
        }
        if(!flag) ans++;
    }
    return ans;
}

long max_gap(){
    long n,m, ans = MIN, min;
    cin >> n;
    cin >> m;
    min = m;
    for(int i = 1; i < n; i++){
        cin >> m;
        if(ans < (m - min)) ans = (m - min);
        if(min > m)min = m;
    }
    return ans;
}

void selection_sort(){
    long n,a[101],scou = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        long min = i;
        for(int j = i+1; j < n; j++){
            if(a[min] > a[j]) min = j;
        }
        if(min != i) {
            scou++;
            swap(a[min], a[i]);
        }
        cout << a[i];
        if(i == (n - 1))cout << endl;
        else cout << " ";
    }
    cout << scou << endl;
}

int main() {
    selection_sort();
}
