#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	printf("STUDENT FEEDBACK\n");
	printf("________________\n");
    int n, i, longestIndex = 0;
    char **feedback;
    char buffer[500];
    int totalCharacters = 0;

    printf("\nEnter number of feedback entries: ");
    scanf("%d", &n);
    getchar(); 

    feedback = (char **)malloc(n * sizeof(char *));
    if (!feedback) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    for (i = 0; i < n; i++) {
        printf("Enter feedback %d: ", i + 1);
        fgets(buffer, 500, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        feedback[i] = (char *)malloc(strlen(buffer) + 1);
        strcpy(feedback[i], buffer);

        totalCharacters += strlen(buffer);

        if (strlen(feedback[i]) > strlen(feedback[longestIndex]))
            longestIndex = i;
    }
    printf("\nAll Feedback:\n");
    for (i = 0; i < n; i++)
        printf("Feedback %d: %s\n", i + 1, feedback[i]);

    printf("\nTotal characters: %d\n", totalCharacters);
    printf("Longest feedback: %s\n", feedback[longestIndex]);

    for (i = 0; i < n; i++)
        free(feedback[i]);
    free(feedback);

    return 0;
}

