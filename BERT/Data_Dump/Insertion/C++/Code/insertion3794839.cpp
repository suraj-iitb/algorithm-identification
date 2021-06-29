#include <iostream>
#include <string>

using namespace std;
int a[101],n;

void print(){
    for(int i=0;i<n-1;i++)
        cout << a[i]<<" ";
    cout <<a[n-1]<<endl;
}

int main(){
    
    cin >>n;
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    print();
    
    for(int i=1;i<n;i++){
        int v=a[i];
        int j=i-1;
        while(j>=0 && a[j]>v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1]=v;
        print();
    }
     
   
    
    return 0;
} 
