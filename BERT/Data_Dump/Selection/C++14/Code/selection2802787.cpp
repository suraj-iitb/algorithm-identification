#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin >> n;
    int array[100];
    bool flag=true;
    int count=0;
    for(int i=0;i<n;i++){
        cin >> array[i];
    }
    for(int i=0;i<n;i++){
        int minj=i;
        for(int j=i;j<n;j++){
            if(array[minj]>array[j]){
                minj=j;
            }
        }
        if(array[i]!=array[minj]){
            int tmp=array[i];
            array[i]=array[minj];
            array[minj]=tmp;
            count++;
        }
    }
    for(int i=0;i<n;i++){
        cout << array[i];
        if(i!=n-1){
            cout << " ";
        }
    }
    cout << endl;
    cout << count << endl;
    return 0;
}
