#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void print(int n, int a[]);
void print(int n, int a[]);

int n;
int a[1024];

void InsertionSort(int n, int a[]){
    for(int i = 0; i < n; i++){
        int v = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        print(n, a);
        if(i != n-1){
            cout << endl;
        }
    }
    
}

void print(int n, int a[]){
    for(int i = 0; i < n-1; i++){
        cout << a[i] << " ";
    }
    cout << a[n-1];
}
int main() {
   
    cin >> n; 
    //int arr[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    InsertionSort(n, a);
    //print(n, a);
    cout << endl;
    

}
