/* Header file for functions that build and scan the BST */
#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>

#define MAX_MOVIELIST 422498
#define AVG_MOVIELIST 450
#define MAX_NAME 128
#define MAX_LINE 422627
#define ENTER 13
#define NULL_BYTE 1
#define SUCESS 1
#define FAIL 1




typedef struct  Node
  {
/*
all data in the tree will be stored as these nodes
*/
    char *key;
    char *movie_list;
    struct Node *right_child;
    struct Node *left_child;
    } Node;

/*
    function declerations
*/
Node *initialize_node();
Node *new_node(char *key, char *movie_list);
void insert(Node root, char *key, char* movie_list);
char *create_buffer(int buffer_size);
Node scan_csv(FILE *data);
void search(Node root, char *key, FILE *output);
void read_keyfile(Node root, FILE *keyfile, FILE *output);



Node
*initialize_node() {
/*
safe node initialization
*/
    Node *node;

    node = (Node*) malloc(sizeof(Node));
    if (node == NULL) {
        printf("ERROR: node fail");
        exit(EXIT_FAILURE);
    return node;
    }
}

Node
*new_node(char *key, char *movie_list) {
/*
creates and fills in a new node
*/
    Node *node;

    node = initialize_node();

    node->key = (char*) malloc(sizeof(char)*(strlen(key)+1));
    node->movie_list = (char*) malloc(sizeof(char)*(strlen(movie_list)+1));

    strcpy(node->key, key);
    strcpy(node->movie_list, movie_list);


    return node;
}



void
insert(Node root, char *key, char* movie_list) {
/*
goes through BST looking of a leaf position to store a new node,
and does as such
*/

    int c;
    Node *x;
    x = &root;

    while (x->key!= NULL) {
         c = strcmp(key, x->key);
        if (c < 0) {
            if (x->left_child==NULL) {
                x->left_child = new_node(key, movie_list);
                return;
            } else {
                x = x->left_child;
            }
        } else {
            if (x->right_child==NULL) {
                x->right_child = new_node(key, movie_list);
                return;
            } else {
            x = x->right_child;
            }
        }
    }
    return;
}



char
*create_buffer(int buffer_size) {
/*
creates a buffer for data scanning
*/
    char *buffer;

    buffer = (char*)malloc(buffer_size);
    if (buffer == NULL) {
        printf("\nERROR: Out of memory!\n");
        exit(EXIT_FAILURE);
    }
    return buffer;
}




Node
scan_csv(FILE *data) {
/*
scan_csv function for reading data and storing as a sorted binary search tree
returns a pointer to the root node
*/

    Node root;

    char *key_token;
    char *movie_token;
    char *buffer;
    int k_len, m_len;

/*
make root node, then continue scaning and sorting
*/
    buffer = create_buffer(MAX_LINE);
    fgets(buffer, MAX_LINE, data);


    key_token = strtok(buffer,";");
    k_len = sizeof(char)*(strlen(key_token)+NULL_BYTE);
    root.key = (char*) malloc(k_len);
    strcpy(root.key, key_token);

    movie_token = strtok(NULL,"\n");
    m_len = sizeof(char)*(strlen(movie_token)+NULL_BYTE);
    root.movie_list = (char*) malloc(m_len);
    strcpy(root.movie_list,movie_token);

    root.left_child = NULL;
    root.right_child = NULL;

/*
now repetedly scan file, adding and sorting nodes
*/
    while (fgets(buffer,MAX_LINE,data)) {

        key_token = strtok(buffer,";");
        movie_token = strtok(NULL,"\n");

        insert(root, key_token, movie_token);
    }
    printf("scan complete!\nroot key: %s\n",root.right_child->key);


    return root;
}																																																  																																																								 							/*****************************  Search Functions  ****************************/

void
search(Node root, char *key, FILE *output) {
    int c;
    int comp=0;
    int sucess = FAIL;
    Node *x;

    x = &root;

    while (x->key!= NULL) {
        c = strcmp(key, x->key);
        comp++;
        if (c < 0) {
            if (!x->left_child) {
                break;
            } else {
                x = x->left_child;
            }
        } else if (c > 0) {
            if (!x->right_child) {
                break;
            } else {
            x = x->right_child;
            }
        } else {
            sucess = SUCESS;
            fprintf(output, "%s --> %s\n", key, root.movie_list);
        }
    }
    if (sucess == SUCESS) {
        printf("%s --> %d", key, comp);
    } else if (sucess == FAIL) {
        printf("NOTFOUND");
    }
    return;
}

void
read_keyfile(Node root, FILE *keyfile, char *key) {
    char *key_token;

        key_token = strtok(key, "\n");
        printf("strcmp: %d", strcmp(key_token, "Lunde, Heidi Nordby"));
        printf("\nSearching for: %s\n",key_token);
        search(root, key_token, output);

    return
}
