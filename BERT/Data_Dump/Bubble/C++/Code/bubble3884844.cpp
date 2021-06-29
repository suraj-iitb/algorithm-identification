// alds1_2_a bubble sort
#include <iostream>
using namespace std;

int cnt = 0;

void printline(int a[], int n, int cnt){
    // cout << cnt << " > " ;
    for(int i=0; i<n; i++){
        cout << a[i] ;
        if (i != n-1){ cout << " ";}
    }
    cout << endl;
}

void bubbleSort(int a[], int n){
    int flag = 1;
    int temp;
    while(flag){
        flag = 0;
        for(int j=n-1; j>0; j--){
            if(a[j] < a[j-1]){
                temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
                flag = 1;
                cnt++;

                // printline(a,n,cnt);
            }
        }
    }
    printline(a,n,cnt);
}



int main(){
    int i,n;
    int a[100];

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    bubbleSort(a, n);
    
    cout << cnt << endl;
    return 0;
}
