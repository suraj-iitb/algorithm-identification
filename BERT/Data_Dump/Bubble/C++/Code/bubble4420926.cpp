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

int bubbleSort(int A[],int N){
    int flag,temp,count;
    count =0;
    flag = 1;
    while(flag){
        flag = 0;
        for(int j=N-1;j>0;j--){
            if(A[j]<A[j-1]){
                temp = A[j];
                A[j] = A[j-1];
                A[j-1] = temp;
                flag =1;
                count++;
            }
        }
    }
    return count;
}

int main(){
    int N,count;
    int A[MAX];
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    count = bubbleSort(A,N);
    output(A,N);
    cout << count << endl;
    return 0;
}
