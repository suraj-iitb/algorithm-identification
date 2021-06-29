#include <iostream>

using namespace std;

int main(){
    int n, i, j, mini, tmp, count = 0;
    cin >> n;
    int a[n];
    for(i = 0; i < n; i++) cin >> a[i];
    for(i = 0; i < n; i++){
        mini = i;
        for(j = i; j < n; j++) if(a[j] < a[mini]) mini = j;
        tmp = a[i];
        a[i] = a[mini];
        a[mini] = tmp;
        if(a[i] != a[mini]) count++;
    }
    for(i = 0; i < n-1; i++) cout << a[i] << " ";
    cout << a[i] << endl << count << endl;
    return 0;
}
