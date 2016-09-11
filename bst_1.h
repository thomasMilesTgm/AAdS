/**
Written by Thomas Miles (626263)
Last modified 10/09/16

This is the header file for creation of the bottom level binary search tree
*/
#ifndef BST_1
#define BST_1
/*_______________________________ definitions ________________________________*/
#define NULL_BYTE 1
#define YES 1
#define NO 0
#define CHAR 4	/* size of a charachter; 4 bytes */

typedef struct Node {
	/**
	All data in the BST is stored in these 'nodes'.
	key = name
	*/
	char *key;
	char *data;
	struct Node *right_child;
	struct Node *left_child;
} Node;


/*__________________________ function prototypes _____________________________*/
struct Node *initialize_node ();
struct Node *new_node (char *buffered_name, char *buffered_data);
int insert (Node *root, Node *orphan, int n_prv);
int search (Node *root, char *search_key, FILE *output, int n_prv, int found);

#endif
