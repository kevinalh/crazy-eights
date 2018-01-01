#include <stdio.h>

#include "menuprinters.h"

void print_logo(void) {
	printf("\t8888888888888888888888888888\n");
	printf("\t8--------------------------8\n");
	printf("\t8-------CRAZY EIGHTS-------8\n");
	printf("\t8--------------------------8\n");
	printf("\t8888888888888888888888888888\n\n");
}

void print_menu_main(void) {
	printf("\n");
	print_logo();
	printf("\tSelect role: \n");
	printf("\t1. Player \t2. Server\n\n");
}

