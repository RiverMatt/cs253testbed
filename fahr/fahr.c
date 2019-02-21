#include <stdio.h>

/*
 * Print fahr -> celcius table
 */

#define LOWER 0
#define UPPER 300
#define STEP 20

int main(void) {
	
	int fahr;
	char* title = "F -> C";
	char* barrier = "=-=-=-=-=-=-=-=-=-=";

	printf("\n%20s\n\n", title);
	printf("\t%s\n\n", barrier);

	for (fahr = LOWER; fahr <= UPPER; fahr += STEP) {
		printf("%15d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
	}
	
	printf("\n");

	return 0;
}
