#include <iostream>
#include <fstream>

#include <string>

using namespace std;

void insertionSort(int *a, int N);
void pp_sorting(int *a,int N);

int main(){

    int N;
    int a[1000];

    cin >> N;
    for(int i=0;i<N;i++) cin >> a[i];

    pp_sorting(a,N);
    insertionSort(a,N);


    
    return 0;
}

void pp_sorting(int *a,int N){
    for(int i=0;i<N-1;i++) cout << a[i] << " ";
    cout << a[N-1] << endl;
}

void insertionSort(int *a, int N){
    for(int i=1;i<N;i++){
        int v = a[i];
        int j = i-1;
        while(j >= 0 && a[j] > v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        pp_sorting(a, N);
    }
}
