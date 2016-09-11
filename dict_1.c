/**
Written by Thomas Miles (626263)
Last modified 10/09/16

Contains functions for implimentation of the BST as a dictionary from a CSV file
*/
#include  <stdio.h>
#include  <stdlib.h>
#include "dict_1.h"

/*_______________________________ functions __________________________________*/
char * create_buffer (int buffer_size) {
	/**
	Creates the buffer for scanning data from the CSV file and returns a
	pointer to it
	*/
	char *buffer;
	buffer = (char*) malloc (buffer_size);

	if (buffer == NULL) {
		printf("--> ERROR: ERROR: In create_buffer: malloc failure.");
		exit(EXIT_FAILURE);
	}
	return buffer;
}

Node * scan_csv (FILE *csv) {
	/**
	Deliminates the CSV file and saves it into a BST, returning a pointer
	to the root node
	*/
	Node *root;
	Node *next;
	char *buffer;
	char *name_token;
	char *data_token;

	buffer = create_buffer(MAX_LINE);
	fgets (buffer, MAX_LINE, csv);
	name_token = strtok (buffer, ",");
	data_token = strtok (NULL, "\n");
	root = new_node (name_token, data_token);

	while (fgets (buffer, MAX_LINE, csv)) {
		name_token = strtok (buffer, ",");
		data_token = strtok (NULL, "\n");
		next = new_node (name_token, data_token);
		insert (root, next, 0);
	}
	return root;

}
