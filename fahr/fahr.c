#include <stdio.h>

/* Print fahr -> celcius table
 *
 */

#define LOWER 0
#define UPPER 300
#define STEP 20

int main(void) {
	
	int fahr;
	char* title = "F -> C";
	char* barrier = "=-=-=-=-=-=-=-=-=-=";

	printf("\n%20s\n\n", title);		// Insert the title with a specified width of 20
	printf("\t%s\n\n", barrier);		// Insert the barrier string

	for (fahr = LOWER; fahr <= UPPER; fahr += STEP) {
		printf("%15d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
	}
	
	printf("\n");

	return 0;
}
