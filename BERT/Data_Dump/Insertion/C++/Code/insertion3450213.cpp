#include <iostream>
using namespace std;
#include <algorithm>

void insertionSort(int ary[], int num);

void printArray(int ary[], int num){
    for (int i=0; i<num; i++){if(i==num -1) cout << ary[i] << endl; else cout << ary[i] << ' ';}
}

int main(){
    int n, a[100];
    cin >> n;
    for(int i=0; i<n; i++){cin >> a[i];}
    insertionSort(a, n);

    return 0;
}
void insertionSort(int ary[], int num){
    int v, j;
    for (int i=1; i<num; i++){
        printArray(ary, num);
        v = ary[i];
        j = i - 1;
        while (j >= 0 && ary[j] > v){
            ary[j+1] = ary[j];
            j--;
        }
        ary[j+1] = v;
    }
    printArray(ary, num);
}
