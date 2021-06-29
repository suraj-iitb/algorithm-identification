#include <iostream>
#include <vector>
using namespace std;

int print_arr(vector<int> a, int n){
    for(int j=0; j<n; j++){
        cout << a[j];
        if(j<n-1){
            cout << " ";
        }
    }
    cout << endl;
    return 0;    
}

int insertion_sort(vector<int> a, int n){
    for(int i=1; i<n; i++){
        print_arr(a, n);
        int v = a[i];
        int j = i - 1;
        while(j>=0 and a[j]>v){
            a[j+1] = a[j];
            j--;
            a[j+1] = v;
        }
    }
    print_arr(a, n);
    return 0;
}

int main(void){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    insertion_sort(a, n);
    return 0;
}
