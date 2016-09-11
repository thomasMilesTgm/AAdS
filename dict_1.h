/**
Written by Thomas Miles (626263)
Last modified 10/09/16

Contains functions for implimentation of the BST as a dictionary from a CSV file
*/
#ifndef DICT_1
#define DICT_1

#include <string.h>
#include "bst_1.h"
/*_______________________________ definitions ________________________________*/
#define MAX_NAME 64
#define MAX_DATA 1465
#define MAX_LINE 1529	/* maximum line length (MAX_NAME + MAX_DATA) */


/*__________________________ function prototypes _____________________________*/
char * create_buffer (int buffer_size);
Node * scan_csv (FILE *csv);

#endif
