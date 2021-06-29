#include<cstdio>
#include<iostream>

using namespace std;

void trace(int a[],int n){
    for (int i = 0; i < n; ++i) {
        cout << a[i];
        if (i != n-1)
            cout << " ";
    }
    cout << "\n";
}

void insertion_sort(int a[], int n){

    int cursor,temp;

    for (int i = 1; i < n; ++i) {
        cursor = i-1;
        temp = a[i];
        while (cursor >= 0 && a[cursor] > temp){
            a[cursor+1] = a[cursor];
            cursor--;
        }
        cursor++;
        a[cursor] = temp;

        trace(a,n);
    }

}

int main(){

    int a[100],n;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }


    trace(a,n);

    insertion_sort(a,n);


    return 0;
}
