/*------------------------------------------------------------------------
 * Test main file
 * ------------------------------------------------------------------------
 *  main.c: test
 * -----------------------------------------------------------------------*/

#include <stdio.h>
#include <grvy.h>

int main(){
	/* Open file */
	int open;
	open = grvy_input_fopen("./input.dat");
	
	/* Read contents */
	int intfoo;
	double doublefoo;
	char *charfoo;
	
	grvy_input_fread_int("intfoo", &intfoo);
	printf("value of infoo: %d\n", intfoo);

	grvy_input_fread_double("doublefoo", &doublefoo);
	printf("value of doublefoo: %f\n", doublefoo);
	
	grvy_input_fread_char("charfoo", &charfoo);
	printf("value of charfoo: %s\n", charfoo);

	return 0;

}
