#include <iostream>
#include <vector>
using namespace std;


void BubbleSort(int Seq[], int n){
    int cnt=0;
    for(int i=0; i<n; i++){
        for(int j=n-1; j>i; j--){
            if(Seq[j] < Seq[j-1]){
                swap(Seq[j], Seq[j-1]);
                cnt++;
            }
        }
    }

    for(int i=0; i<n; i++){
        if(i != n-1){
            cout << Seq[i] << " ";
        }else{
            cout << Seq[i] << endl;
        }
    }
    cout << cnt << endl;

}


int main(){

    int n;
    cin >> n;
    int Seq[n];
    for(int i=0; i<n; i++){
        cin >> Seq[i];
    }

    BubbleSort(Seq, n);

    return 0;
}
