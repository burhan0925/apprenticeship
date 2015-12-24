#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 16


void mergeSort(int ar[], int s, int e);
void merge(int ar[], int s, int m, int e);


int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int ar[MAX_SIZE], i, j;


	// Randomly fill array to sort
	for( i=0; i<MAX_SIZE; i++ ) {
		ar[i]= rand()%100;
		printf("%d ",ar[i] );
	}
	printf("\n");

	// Call merge sort on the original array
	mergeSort(ar,0,MAX_SIZE-1);


/*	int A[] = {1,3,5,2,4,6,7};
	merge(A,0,2,7);
	for( i=0; i<7; i++ ) {
		printf("%d ",A[i] );
	}
	printf("\n");
*/


	// Sorted array print
	for( i=0; i<MAX_SIZE; i++ ) {
		printf("%d ",ar[i] );
	}
	printf("\n");

	return 0;
}


void mergeSort(int ar[], int s, int e) {
	
	// If start and end indices are not same i.e. there are more than 1 
	// element in the subarray	
	if( e-s > 0) {
		
		// Find boundary sharing index( or mid index)
		int m = (s+e)/2;
		
		// Recursively sort the left and right subarrays		
		mergeSort(ar, s, m);
		mergeSort(ar,m+1,e);

		// Merge them into a single larger array
		merge(ar,s,m,e);
	}
}

void merge(int ar[], int s, int m, int e) {
	// Store left and right subarrays
	int L[m-s+1+1], R[e-m+1];
	int j=s, i, k=0;
	
	for( i=s; i<m+1; i++ ) {
		L[k++] = ar[j++];
	}
	L[k] = 999999;


	k=0;
	for( i=m+1; i<e+1; i++ ) {
		R[k++] = ar[j++];
	}
	R[k] = 999999;

	/*
		Great idea to use sentinel cards in the left and right sub-arrays, 
		which are like the bounding limits of the values, such that no element 
		has a value larger than the sentinel value.

		This makes sure sure we don't have to use an 'if statement'.
		Mindbogglingly smart of CLRS.

	*/


	// Compare individual elements and merge
	int l=0, r=0;

	for( i=s; i<e+1; i++ ) {
		if( L[l] <= R[r])
			ar[i] = L[l++];
		else
			ar[i] = R[r++];	
	}
}
