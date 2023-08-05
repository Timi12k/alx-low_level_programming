#include <stdio.h>

/**
 *main- Print programme name
 *argc:Argument count
 *argv:Argument vector
 *return: 0
 **/
int main(int argc, char *argv[])
{
	if(argc >= 1)
	{
		printf("%s\n", argv[0]);

	}
	return 0;
}
