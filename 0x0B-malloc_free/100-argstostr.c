#include "main.h"
#include <stdlib.h>
#include <string.h>

char *argstostr(int ac, char **av) {
	if (ac == 0 || av == NULL) {
		return NULL;
	}
	
	int total_length = 0;
	
	for (int i = 0; i < ac; i++) {
		total_length += strlen(av[i]) + 1;
	}
	
	char *result = (char *)malloc(total_length * sizeof(char));
	if (result == NULL) {
		return NULL;
	}
	
	int position = 0;
	
	for (int i = 0; i < ac; i++) {
		strcpy(result + position, av[i]);
		position += strlen(av[i]);
		result[position++] = '\n';
	}
	
	result[position - 1] = '\0';
	
	return result;
}

int main(int argc, char *argv[]) {
	if (argc <= 1) {
		printf("No arguments provided.\n");
		return 1;
	}
	
	char *concatenated = argstostr(argc - 1, argv + 1);
	
	if (concatenated != NULL) {
		printf("Concatenated arguments:\n%s\n", concatenated);
		free(concatenated);
	} else {
		printf("Memory allocation failed.\n");
	}
	
	return 0;
}
