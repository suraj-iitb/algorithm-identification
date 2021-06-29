#include <iostream>
using namespace std;
#define MAX 100
int count = 0;

void bubbleSort(int a[], int n){
    int flag = 1;
    while(flag){
        flag = 0;
        for(int i = n-1; i > 0; i--){
            if(a[i] < a[i-1]){
                int tmp = a[i];
                a[i] = a[i-1];
                a[i-1] = tmp;
                flag = 1;
                count++;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    int a[MAX];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    bubbleSort(a, n);
    for(int i = 0; i < n; i++){
        cout << a[i];
        if(i != n-1) cout << " ";
    }
    cout << endl;
    cout << count << endl;
    return 0;
}

