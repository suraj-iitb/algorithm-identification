#include <iostream>
#include <fstream>

#include <cmath>

using namespace std;


int bubbleSort(int *a, int N);
void pp_sorting(int *a,int N);
int main(){

    int n, a[100];
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    int counter = bubbleSort(a,n);
    pp_sorting(a,n);
    cout << counter << endl;

    return 0;
}

int bubbleSort(int *a, int N){
    int counter = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N-1-i;j++){
            if(a[j] > a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1] = temp;
                counter++;
            }
        }
    }
    return counter;
}

void pp_sorting(int *a,int N){
    for(int i=0;i<N-1;i++) cout << a[i] << " ";
    cout << a[N-1] << endl;
}


