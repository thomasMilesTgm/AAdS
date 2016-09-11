/*
*  This is the main function for the imdb BST
*  Created by Tom Miles (626263), September 2015
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header2015.h"



int
main (int argc, char *argv[]) {
    FILE *data;
    FILE *output;
    FILE *search_key;
    Node *root;


    data = fopen(argv[1], "r");
    if (data == NULL) {
        printf("\nERROR: File not successfully opened!\n");
        exit(EXIT_FAILURE);
    }

    output = fopen(argv[2],"w");
    if (output == NULL) {
        printf("\nERROR: Output file not successfully created!\n");
        exit(EXIT_FAILURE);
    }

    search_key = fopen("keyfile.txt", "r");
    if (search_key == NULL) {
        printf("\nERROR: Search key file not successfully opened!\n");
        exit(EXIT_FAILURE);
    }

    root = scan_csv(data);
    fclose(data);

    read_keyfile(root, search_key, output);

    return 0;
}
