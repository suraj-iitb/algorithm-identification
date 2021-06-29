#include <iostream>
using namespace std;
#include <algorithm>

int bubbleSort(int ary[], int num);

void printArray(int ary[], int num){
    for (int i=0; i<num; i++){if(i==num -1) cout << ary[i] << endl; else cout << ary[i] << ' ';}
}

int main(){
    int n, a[100];
    cin >> n;
    for(int i=0; i<n; i++){cin >> a[i];}
    int count = 0;
    count = bubbleSort(a, n);
    printArray(a, n);
    cout << count << '\n';

    return 0;
}
int bubbleSort(int ary[], int num){
    int count=0;
    bool flag = 1;
    for(int i=0; flag; i++){
        flag = 0;
        for (int j=num-1; j>i; j--){
            if (ary[j] < ary[j-1]){
                swap(ary[j], ary[j-1]);
                flag = 1;
                count += 1;
            }
        }
    }
    return count;
    
}
