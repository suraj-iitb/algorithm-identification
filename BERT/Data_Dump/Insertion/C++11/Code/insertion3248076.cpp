#include <iostream>
using namespace std;
const int Max_N = 101;
int A[Max_N], N;
void Cout_Sort(){
	for(int i=0; i<N; i++){
		cout << A[i];
		if(i != (N - 1)) cout << " ";
	}
	cout << endl;
} 
void Insertion_Sort(){
    int i;
	for(int P=1; P<N; P++){
	 int temp = A[P];  /*待插入的数*/
	 for( i = P; i>0 && A[i-1]>temp;i--)
	 A[i] = A[i-1];
     A[i] = temp; /*找到插入位置*/
     Cout_Sort();
	}
}
int main()
{   
    cin >> N;
    for(int i=0; i<N; i++)
      cin >> A[i];
	Cout_Sort();
    Insertion_Sort(); 
    return 0;
}
