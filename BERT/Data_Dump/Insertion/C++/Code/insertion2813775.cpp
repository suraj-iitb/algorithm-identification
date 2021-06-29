#include <iostream>
using namespace std;
int main(){
        int n;
        int array[100];
        cin >> n;
        for(int i=0 ; i<n ; i++ ){
                cin>> array[i];
                }
        for(int i=1 ; i<=n ; i++ ){
                int tmp=array[i];
                for(int l=0 ; l<n ; l++ ){
                        cout << array[l];
                        if(l<n-1)
                                cout<<" ";
                }
                cout << endl;
                int j=i-1;
                while(array[j]>tmp && j>=0){
                        array[j+1]=array[j];
                        j--;
                }
                array[j+1]=tmp;
        }
        return 0;
}


