#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

/**.......Display the never ending next command prompt of simple shell........*/
int display_prompt(char *argv[]);

#endif /* SHELL_H */
