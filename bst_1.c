/**
Written by Thomas Miles (626263)
Last modified 10/09/16

Contains functions for creation of the bottom level binary search tree
*/
#include  <stdio.h>
#include  <stdlib.h>
#include <string.h>
#include "bst_1.h"

/*___________________________ setup functions  _______________________________*/
Node * initialize_node () {
	/**
	Safe node initialization, returns the pointer to the new node
	*/
	Node *node;
	node = (Node*) malloc(sizeof(Node));
	if (node == NULL) {
		printf("--> ERROR: ERROR: In initialize_node: malloc failure.");
		exit(EXIT_FAILURE);
	}
	return node;
}



Node * new_node (char *buffered_name, char *buffered_data) {
	/**
	Recieves pointers to name and data information stored in the buffer and
	saves them in a correctly sized node, returns a pointer to that node
	*/
	Node *node;
	int name_len=0;
	int data_len=0;
	node = initialize_node();
	/* find how much memory to allocate */
	name_len = CHAR * (strlen(buffered_name) + NULL_BYTE);
	data_len = CHAR * (strlen(buffered_data) + NULL_BYTE);
	/* allocate and save the strings and give pointers to a new node */
	node->key = (char*) (malloc(name_len));
	node->data = (char*) (malloc(data_len));
	/* check not out of memory */
	if (node->data == NULL || node->key == NULL) {
		printf ("--> ERROR: In new_node: malloc failure.");
		exit (EXIT_FAILURE);
	}
	strcpy(node->key, buffered_name);
	strcpy(node->data, buffered_data);
	node->left_child = NULL;
	node->right_child = NULL;
	return node;
}


/*___________________________ build functions  _______________________________*/
int insert (Node *root, Node *orphan, int n_prv) {
	/**
	Takes a pointer to an anassigned node and finds the appropriate place in
	the BST to save it. n_prv = number of previous comparisons done.
	*/
	int cmp = 0;
	int n_cmps = n_prv;

	cmp = strcmp (root->key, orphan->key);
	n_cmps ++;

	if (cmp < 0) {		/* if orphan's key > root's, go right */
		if (root->right_child == NULL) {
			root->right_child = orphan;
		} else {
			insert (root->right_child, orphan, n_cmps);
		}
	} else if (cmp >= 0) {
		if (root->left_child == NULL) {
			root->left_child = orphan;
		} else {
			insert (root->left_child, orphan, n_cmps);
		}
	}
	return n_cmps;
}


int search (Node *root, char *search_key, FILE *output, int n_prv, int found) {
	/**
	Finds all key mathces in the BST and prints them to 'output' file
	*/
	int n_cmps = n_prv;
	int cmp = 0;

	if (root == NULL) {
		/* we are at the end of the tree */
		if (found == NO) {
			fprintf (output, "NOTFOUND\n");
			return n_cmps;
		} else {
			return n_cmps;
		}
	} else {
		cmp = strcmp(root->key, search_key);
printf("Searching for:  	-%s-\nAgainst:	        -%s-\n",search_key,root->key);
printf("CMP: %d\n",cmp);
		n_cmps ++;
		if (cmp < 0){
			return (search (root->right_child, search_key, output, n_cmps,
				found) );
		} else {
			if (cmp == 0) {
				found = YES;
				fprintf (output, root->data);
			}
			return (search (root->left_child, search_key, output, n_cmps,
				found) );
		}
	}
}
