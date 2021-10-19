#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *file;
	char buffer[4096], word[255];
	int counter = 0, line_num = 0;
	
	if ((file = fopen("../test.txt", "r")) == NULL) {
		printf("Error opening file");
		
		exit(1);
	}
	
	printf("Enter a word to search:\n");
	scanf("%s", word);
	
	if(strlen(word) > 255) {
		printf("Word is too long");

		exit(1);
	}

	while (fgets(buffer, sizeof(buffer), file) != NULL) {
		line_num++;
		int i;
		for (i = 0; i < strlen(buffer); i++) {
			if (word[counter] == buffer[i]) {
				counter++;
			} else {
				counter = 0;
			}
			if (counter == strlen(word)) {
				printf("%i\n", line_num);
			}
		}
	}

	fclose(file);
	return 0;
}
