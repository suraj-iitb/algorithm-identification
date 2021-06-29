//	-*- mode: C++ -*-
//	Insertion Sort
//		Write a program of the Insertion Sort algorithm which sorts a sequence A in ascending order. The algorithm should be based on the following pseudocode:
//
//		for i = 1 to A.length-1
//		    key = A[i]
//		    /* insert A[i] into the sorted sequence A[0,...,j-1] */
//		    j = i - 1
//		    while j >= 0 and A[j] > key
//		        A[j+1] = A[j]
//		        j--
//		    A[j+1] = key
//		Note that, indices for array elements are based on 0-origin.
//
//		To illustrate the algorithms, your program should trace intermediate result for each step.
//
//	Input
//		The first line of the input includes an integer N, the number of elements in the sequence.
//
//		In the second line, N elements of the sequence are given separated by a single space.
//
//	Output
//		The output consists of N lines. Please output the intermediate sequence in a line for each step. Elements of the sequence should be separated by single space.
//
//	Constraints
//		1 ≤ N ≤ 100
//
//	Sample Input 1
//		6
//		5 2 4 6 1 3
//	Sample Output 1
//		5 2 4 6 1 3
//		2 5 4 6 1 3
//		2 4 5 6 1 3
//		2 4 5 6 1 3
//		1 2 4 5 6 3
//		1 2 3 4 5 6
//	Sample Input 2
//		3
//		1 2 3
//	Sample Output 2
//		1 2 3
//		1 2 3
//		1 2 3

#include <iostream>
#include <vector>

void	VPrint(unsigned int					N,
			   std::vector<unsigned int>&	V)
{
	unsigned int	count	{0};
	for(auto a : V){
		count++;
		std::cout << a;
		if(count < N){
			std::cout << ' ';
		}
		else{
			std::cout << '\n';
		}
	}
}

int	main(int	argc,
		 char*	argv[])
{
	unsigned int	N	{0};
	std::cin >> N;

	std::vector<unsigned int>	V	{};
	V.resize(N, 0);

	for(unsigned int i = 0; i < N; i++){
		std::cin >> V[i];
	}

	for(unsigned int i = 1; i < N; i++){
		VPrint(N, V);
		unsigned int	key	= V[i];
		int				j	= i - 1;

		while(j >= 0 && V[j] > key){
			V[j + 1] = V[j];
			j--;
		}

		V[j + 1]	= key;
	}
	
	VPrint(N, V);

    return 0;
}

