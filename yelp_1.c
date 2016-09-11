/**
Written by Thomas Miles (626263)
Last modified 10/09/16

This is the top level program to impliment the dictionary
*/
#include  <stdio.h>
#include  <stdlib.h>
#include "dict_1.h"
#include "bst_1.h"

#define FIRST_KEY 3 	/* argv[3] is first key from stdin */
#define FIRST 0		/* first search, used for counting comparisons */

int main (int argc, char *argv[]) {
	FILE *csv;
	FILE *output;
	Node *root;
	int i = FIRST_KEY;
	int cmps = 0;

	csv = fopen(argv[1], "r");

	if (csv == NULL) {
            printf("\nERROR: File not successfully opened!\n");
            exit(EXIT_FAILURE);
        }

	output = fopen(argv[2],"w");
        if (output == NULL) {
            printf("\nERROR: Output file not successfully opened!\n");
            exit(EXIT_FAILURE);
        }

	printf ("--> Scanning CSV\n");
	root = scan_csv (csv);
	printf ("--> CSV scanned\n");
	fclose (csv);

	/* Search keys from stdin */
	while (i < argc) {
		fprintf (output, "%s --> ", argv[i]);
		cmps = search (root, argv[i], output, FIRST, NO);
		printf ("%s --> %d\n", argv[i], cmps);
		i++;
	}

	fclose (output);

	return 0;
}
