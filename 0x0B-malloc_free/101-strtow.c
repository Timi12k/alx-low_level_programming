#include "main.h"
#include <stdlib.h>
#include <string.h>

char **strtow(char *str) {
	if (str == NULL || *str == '\0') {
		return NULL;
	}
	
	int word_count = 0;
	char *token = strtok(str, " ");
	
	// Count the number of words
	while (token != NULL) {
		word_count++;
		token = strtok(NULL, " ");
	}
	
	// Allocate memory for the array of strings
	char **words = (char **)malloc((word_count + 1) * sizeof(char *));
	if (words == NULL) {
		return NULL;
	}
	
	token = strtok(str, " ");
	int index = 0;
	
	// Copy words into the array
	while (token != NULL) {
		words[index] = strdup(token);
		if (words[index] == NULL) {
			// Memory allocation failed
			for (int i = 0; i < index; i++) {
				free(words[i]);
			}
			free(words);
			return NULL;
		}
		index++;
		token = strtok(NULL, " ");
	}
	
	words[word_count] = NULL; // Last element is NULL
	
	return words;
}

int main() {
	char input[] = "This is a test string";
	char **word_array = strtow(input);
	
	if (word_array != NULL) {
		for (int i = 0; word_array[i] != NULL; i++) {
			printf("%s\n", word_array[i]);
			free(word_array[i]);
		}
		free(word_array);
	} else {
		printf("Memory allocation failed.\n");
	}
	
	return 0;
}
