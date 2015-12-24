#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int ar[15],i,j, n=15, key;

	// Populate array to sort	
	for( i=0; i<n; i++ ) {
		ar[i] = rand()%100;
		printf("%d  ",ar[i] );
	}
	printf("\n");


	// Insertion sort
	for( j=1; j<n; j++ ) {
		// First element trivially sorted


		// Select the current element as the key		
		key = ar[j];

		// Find place of key in the sorted array
		i = j;
		while(i>0 && ar[i-1] > key )
		{
			/*
				A great idea I saw here(CLRS) was how index was manipulated 
				to avoid the use of 'if' statement.
				Reducing runtime in the process. 
			*/
			ar[i] = ar[i-1];
			i--;
		}

		// Insert key into its right position
		ar[i] = key;
	}


	for( i=0; i<n; i++ ) {
		printf("%d  ",ar[i] );
	}
	printf("\n");
	return 0;
}