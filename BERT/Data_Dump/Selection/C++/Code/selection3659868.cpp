#include<iostream>
using namespace std;

void swap(int *v, int *u){
    int temp = *v;
    *v = *u;
    *u = temp;
}

void SelectionSort(int a[], int n, int *count){
    int minj;
    for(int i = 0; i < n; i++){
        minj = i;
        for(int j = i; j < n;j++){
            if(a[j]<a[minj])
                minj = j;
        }
        swap(&a[i], &a[minj]);
        if(i != minj)   *count = *count + 1;
    }
}

int main(void){
    int n, count=0;
    cin >> n;
    int a[n];
    for(int i = 0; i<n;i++){
        cin >> a[i];
    }
    SelectionSort(a, n, &count);
    for(int i=0;i<n;i++){
        if(i)   cout << " ";
        cout << a[i];
    }
    cout << endl;
    cout << count << endl;
    return 0;
}
