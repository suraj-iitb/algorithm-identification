#include <iostream>
using namespace std;
int main(){
        int N;
        int array[100];
        cin >> N;
        for(int i=0 ; i<N ; i++ )
                cin >> array[i];
        int counter=0;
        for(int i=0 ;i<N ; i++ ){
                int now=i;
                for(int j=i+1 ;j<N ; j++ )
                        if(array[j]<array[now])
                                now=j;
                if(now!=i){
                        int tmp=array[now];
                        array[now]=array[i];
                        array[i]=tmp;
                        counter++;
                }
        }
        for(int i=0 ; i<N ; i++ ){
                cout << array[i];
                if(i<N-1)
                        cout<<" ";
        }
        cout << endl << counter << endl;
        return 0;
}
