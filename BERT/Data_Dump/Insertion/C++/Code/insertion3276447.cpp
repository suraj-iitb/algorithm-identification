#include <iostream>
using namespace std;

void iS(int x[],int y){
    for(int i=1;i<y;i++){
        int v = x[i];
        int j = i-1;
        while(j>=0&&x[j]>v){
            x[j+1] = x[j];
            j--;
        }
        x[j+1]=v;
        for(int r=0;r<y;r++){
            if(r != y-1){
                cout << x[r] << " " ;
            }else{
                cout << x[r] << endl;
            }
        }
    }
}

int main(){
    int n;
    int a[100];
    cin >> n;
    for(int i=0;i<n;i++){
        int b;
        cin >> b;
        a[i] = b;
    }
    for(int i=0;i<n;i++){
        if(i != n-1){
            cout << a[i] << ' ';
        }else{
            cout << a[i] << endl;
        }
    }
    iS(a,n);
    
}

