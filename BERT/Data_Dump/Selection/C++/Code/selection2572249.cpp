#include <iostream>
using namespace std;

void trace(int[], int);
int selectionSort(int[], int);

void trace(int a[], int n){
  for(int i = 0; i < n; i++){
    if(i>0) cout << " ";
    cout << a[i];
  }
  cout << endl;
}

int selectionSort(int a[], int n){
    int count = 0;
    for(int i = 0; i < n; i++){
        int minj = i;
        for(int j = i; j < n; j++){
            if(a[j] < a[minj]){
                minj = j;
            }
        }
        if(i != minj){
            count++;
            swap(a[i], a[minj]);
        }
    }
    return count;
}

int main(){
    int n;
    int a[100];
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    int count = selectionSort(a, n);
    trace(a, n);
    cout << count << endl;
    return 0;
}
