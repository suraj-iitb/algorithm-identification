#include <iostream>
using namespace std;
void insertion_sort(int a[], int n)
{ 
     int i,j;
     for (i=1;i<n;i++)
      {
        int key=a[i];
        j=i-1;	
        while((j>=0)&&(a[j]>key))
            {
            a[j+1] = a[j];
            j--; 
            }
        a[j+1] = key;

		for(j = 0; j < n; ++j){
            if(j) cout << " ";
            cout << a[j];
        }
        cout << endl;
     }
}
int main()
{
    int n,i;
    cin >> n;
    int a[101];
    for(int i=0;i<n;i++)
    {
        cin >>a[i];
    }
	for(i = 0; i < n; ++i){
        if(i) cout << " ";
        cout << a[i];
    }
	cout << endl;
    insertion_sort(a,n);
}
