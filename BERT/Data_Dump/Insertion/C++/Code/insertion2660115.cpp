#include <iostream>
using namespace std;
int main(){
        int N;
        int array[100];
        cin >> N;
        for(int i=0 ; i<N ; i++ )
                cin>> array[i];
        for(int i=1 ; i<=N ; i++ ){
                int tmp=array[i];
                for(int l=0 ; l<N ; l++ ){
                        cout << array[l];
                        if(l<N-1)
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
