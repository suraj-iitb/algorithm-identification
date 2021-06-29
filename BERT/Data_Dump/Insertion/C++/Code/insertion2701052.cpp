#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;
void output(int out[],int n)
{
	int i;
	for(i=0;i<n;i++){
		if(i!=n-1)
			cout<<out[i]<<" ";
		else
			cout<<out[i]<<endl; 
	}
} 
int main(int argc, char *argv[]) {
	int tmp,j,i,k,n,input[101];
	cin>>n;
	for(i=0;i<n;i++){
		cin>>input[i];
	}
	output(input,n);
	for(i=1;i<n;i++){
		tmp=input[i];
		j=i-1;
		while(j>=0&&tmp<input[j]){
			input[j+1]=input[j];
			j--;
		}
		input[j+1]=tmp;
		output(input,n);
	}
	return 0;
}
