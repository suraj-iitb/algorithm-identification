#include<iostream>
using namespace std;

void show(int* a, int n)
{
    for(int i = 0; i < n - 1; i++) cout << a[i] << " ";
    cout << a[n - 1] << endl;
}

int BubbleSort(int* a, int n)
{
    int i, c, count;
    bool inv = true;
    count = 0;

    while(inv){
        inv = false;
        for(i = n - 1; i > 0; i--){
            if(a[i] < a[i - 1]){
                c = a[i];
                a[i] = a[i - 1];
                a[i - 1] = c;
                count++;
                inv = true;
            }
        }
    };
    show(a, n);
    return count;
}

int main()
{
    int n, a[100];
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    cout << BubbleSort(a, n) << endl;
    return 0;
}
