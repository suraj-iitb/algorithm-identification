#include <iostream>
#include <vector>

using namespace std;

void SelectionSort(int Seq[], int n){

    int mini;
    int cnt=0;

    for(int i=0; i<n; i++){
       mini = i;
       for(int j=i; j<n; j++){
           if(Seq[j] < Seq[mini]){
               mini = j;
           }
       }
       swap(Seq[i], Seq[mini]);
       if(i != mini) cnt++;
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
    for(int i=0; i<n; i++) cin >> Seq[i];

    SelectionSort(Seq, n);

    return  0;
}
