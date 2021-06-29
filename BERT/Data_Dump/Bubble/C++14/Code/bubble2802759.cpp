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
    while(flag){
        flag=false;
        for(int i=0;i<n-1;i++){
            if(array[i]>array[i+1]){
                int tmp=array[i];
                array[i]=array[i+1];
                array[i+1]=tmp;
                flag=true;
                count++;
            }
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
