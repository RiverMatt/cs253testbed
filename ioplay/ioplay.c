#include <stdio.h>

/* Copy input to output
 *
 */

int main(int argc, char** argv) {
	
	int c;
	long nc, nl;
	
	nc = 0;
	nl = 0;

	while ((c = getchar()) != EOF) {
		putchar(c);
		++nc;
		if (c == '\n') {
			++nl;
		}
	}
	
	printf("\nNumber of characters read: %ld\nNumber of lines read: %ld\n", nc, nl);

	return 0;
}
