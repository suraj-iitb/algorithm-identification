#include <iostream>
using namespace std;
int main(){
        int N;
        int a[1000];
        cin >> N;
        for(int i=0 ; i<N ; i++ )
                cin >> a[i];
        int counter=0;
        int flag=1;
        while(flag){
                flag=0;
                for(int j=N-1 ; j>0 ; j-- ){
                        if( a[j]<a[j-1]){
                                swap(a[j],a[j-1]);
                                counter++;
                                flag=1;
                        }
                }
        }
        for(int i=0 ; i<N ; i++ ){
                cout << a[i];
                if(i!=N-1)
                        cout<<" ";
        }
        cout << endl << counter << endl;
        return 0;
}
