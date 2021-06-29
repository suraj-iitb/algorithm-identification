#include <iostream>
using namespace std;
#include <algorithm>

int selectionSort(int ary[], int num);

void printArray(int ary[], int num){
    for (int i=0; i<num; i++){if(i==num -1) cout << ary[i] << endl; else cout << ary[i] << ' ';}
}

int main(){
    int n, a[100];
    cin >> n;
    for(int i=0; i<n; i++){cin >> a[i];}
    int count = 0;
    count = selectionSort(a, n);
    printArray(a, n);
    cout << count << '\n';

    return 0;
}
int selectionSort(int ary[], int num){
    int count=0;
    int minj;
    for(int i=0; i<num; i++){
        minj = i;
        for (int j=i; j<num; j++){
            if (ary[minj] > ary[j]){
                minj = j;
            }
        }
        if (minj != i){
            swap(ary[i], ary[minj]);
            count ++;
        }
    }
    return count;
    
}
