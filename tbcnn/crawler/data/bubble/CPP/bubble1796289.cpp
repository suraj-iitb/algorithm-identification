/*
AIZU ONLINE JUDGE ??????
Bubble Sort ???????????????
--------------------------------------------------------*/


/*????????????????????????????????????*/
#include<iostream>
using namespace std;


/*???????????????????????¢??°?????????*/
int bubblesort(int A[],int N){
	
	/*?????°??????*/
	int count=0;//??????????????°??¨?????°????????????
	bool flag=1;//???????????¨bool???????????????
	
	/*??????????????????*/
	for(int i=0;flag;i++){
	
		/*?????????????????????????????????*/
		flag=0;
		
		/*?????????*/
		for(int j=N-1;j>=i+1;j--){
		
			if(A[j]<A[j-1]){
			
				swap(A[j],A[j-1]);
				flag=1;
				count++;//??????A[j]<A[j-1]?????£?????´??????A[j]??¨A[j-1]??????????????????????????????????????¨??????????????°???????¢???????
				
			}
		}
		
		
	}
	
	return count;//????????????????????°?????????
	
}



/*???????????¢??°*/
int main(){

	/*?????°?????????*/
	int A[100],N,count;
	cin>>N;
	for(int i=0;i<N;i++){cin>>A[i];}//???????????°????????\???
	
	/*?????????*/
	count=bubblesort(A,N);
	
	/*??????*/
	for(int i=0;i<N;i++){
	
		if(i){cout<<" ";}
		cout<<A[i];
		
	}
	
	cout<<"\n";
	cout<<count<<"\n";
	
	return 0;//??????

}