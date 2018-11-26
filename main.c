/*------------------------------------------------------------------------
 * Test main file
 * ------------------------------------------------------------------------
 *  main.c: test
 * -----------------------------------------------------------------------*/

#include <stdio.h>
#include <grvy.h>

int foo(int *fooint)
{
	fooint=2;
	grvy_printf(GRVY_INFO, "Info message in a function! int is %d now\n", fooint);
	grvy_printf(GRVY_DEBUG, "Debug message in a function!\n");
	return 0;
}

int main(){
	/* Open file */
	int open;
	open = grvy_input_fopen("./input.dat");
	
	/* Get log levels */	
	int log;	
	grvy_input_fread_int("log",&log);
	printf("Log level: %d\n", log);
	
	if(log==0){
		grvy_log_setlevel(GRVY_NOLOG);
	} else if(log==1){
		grvy_log_setlevel(GRVY_INFO);
	} else if(log==2){
		grvy_log_setlevel(GRVY_DEBUG);
	} else {
		printf("Log level setting outside specified range. Setting to DEBUG for safety\n");
		grvy_log_setlevel(GRVY_DEBUG);
	}
		
	/* Read contents */
	int intfoo;
	double doublefoo;
	char *charfoo;
	
	grvy_printf(GRVY_INFO, "Info message: reading int\n");
	grvy_input_fread_int("intfoo", &intfoo);
	printf("value of infoo: %d\n", intfoo);
	
	grvy_printf(GRVY_INFO, "Info message: reading double\n");
	grvy_input_fread_double("doublefoo", &doublefoo);
	printf("value of doublefoo: %f\n", doublefoo);
	
	grvy_printf(GRVY_INFO, "Info message: reading char\n");	
	grvy_printf(GRVY_DEBUG, "This is a debug message!\n");
	grvy_input_fread_char("charfoo", &charfoo);
	printf("value of charfoo: %s\n", charfoo);

	int foo_return;
	foo_return = foo(&intfoo);

	return 0;

}
