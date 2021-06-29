# include<iostream>
using namespace std;
static const int MAX = 100;

void output(int A[],int N){
    for(int i=0;i<N;i++){
        cout << A[i];
        if(i == N-1){
            cout << endl;
        }else{
            cout << " ";
        }
    }
}

int selectionSort(int A[],int N){
    int minj,sw;
    sw=0;
    for(int i=0;i<N;i++){
        minj = i;
        for(int j=i;j<N;j++){
            if(A[j]<A[minj]){
                minj = j;
            }
        }
        if(i != minj){
            swap(A[i],A[minj]);
            sw++;
        }
    }

    return sw;
}

int main(){
    int N,count;
    int A[MAX];
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    count = selectionSort(A,N);
    output(A,N);
    cout << count << endl;
    return 0;
}
