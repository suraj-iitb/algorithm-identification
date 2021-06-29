#include <iostream>
using namespace std;
#define INF 1000000001
int N;
unsigned long long int counter=0;
int merge(long long int array[520000],int left ,int middle,int right){
        int N1=middle-left;
        int N2=right-middle;
        long long int l[300000],r[300000];
        for(int i=0 ; i<N1 ; i++ )
                l[i]=array[left+i];
        for(int i=0 ; i<N2 ; i++ )
                r[i]=array[middle+i];
        l[N1]=INF;r[N2]=INF;
        int i=0,j=0;
        for(int k=left ; k<right ; k++ ){
                counter++;
                if(l[i]<=r[j]){
                        array[k]=l[i];
                        i++;
                }else{
                        array[k]=r[j];
                        j++;
                }
        }
}
int mergesort(long long int array[520000],int left ,int right){
        if(left+1<right){
                int middle=(left+right)/2;
                mergesort(array,left,middle);
                mergesort(array,middle,right);
                merge(array,left,middle,right);
        }
        return true;
}
int main(){
        cin >> N;
        long long int array[520000];
        for(int i=0 ; i<N ; i++ )
                cin >> array[i];
        mergesort(array,0,N);
        for(int i=0 ; i<N ; i++ ){
                cout << array[i];
                if(i<N-1)
                        cout<<" ";
        }
        cout << endl<<counter<<endl;
        return 0;
}
