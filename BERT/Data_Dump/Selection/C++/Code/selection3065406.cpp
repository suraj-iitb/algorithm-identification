#include <iostream>
#include <fstream>

#include <cmath>

using namespace std;


int Sort(int *a, int N);
void pp_sorting(int *a,int N);
int main(){

    int n, a[100];
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    int counter = Sort(a,n);
    pp_sorting(a,n);
    cout << counter << endl;

    return 0;
}

int Sort(int *a, int N){
    int counter = 0;
    for(int i=0;i<N;i++){
        int minj = i;
        for(int j=i;j<N;j++){
            if(a[j] < a[minj]) minj = j;
        }
        if(minj != i){
            int temp = a[i];
            a[i] = a[minj];
            a[minj] = temp;
            counter++;
        }
    }
    return counter;
}

void pp_sorting(int *a,int N){
    for(int i=0;i<N-1;i++) cout << a[i] << " ";
    cout << a[N-1] << endl;
}


