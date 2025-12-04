#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char category(char c) {
    if (isupper(c)) return 'U';
    if (islower(c)) return 'L';
    if (isdigit(c)) return 'D';
    return 'M'; 
}

int main() {
	printf("PASSWORD-PATTERN STRENGTH CHECKER\n");
	printf("_________________________________\n");
    int n, i, bestIndex = 0;
    char *pattern;
    char **passwords;
    char buffer[200];
    float *scores;

    printf("\nEnter number of participants: ");
    scanf("%d", &n);
    getchar();

    printf("Enter password pattern: ");
    fgets(buffer, 200, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';

    pattern = (char *)malloc(strlen(buffer) + 1);
    strcpy(pattern, buffer);

    passwords = (char **)malloc(n * sizeof(char *));
    scores = (float *)malloc(n * sizeof(float));

    for (i = 0; i < n; i++) {
        printf("Enter password %d: ", i + 1);
        fgets(buffer, 200, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        passwords[i] = (char *)malloc(strlen(buffer) + 1);
        strcpy(passwords[i], buffer);

        int j, match = 0;
        int len = strlen(pattern);
        for (j = 0; j < len && j < strlen(passwords[i]); j++) {
            if (category(pattern[j]) == category(passwords[i][j]))
                match++;
        }

        scores[i] = (match / (float)len) * 100;

        if (scores[i] > scores[bestIndex])
            bestIndex = i;
    }
    printf("\nPassword Similarities:\n");
    for (i = 0; i < n; i++)
        printf("%s -> %.2f%%\n", passwords[i], scores[i]);

    printf("\nBest Password: %s (%.2f%%)\n", passwords[bestIndex], scores[bestIndex]);

    free(pattern);
    for (i = 0; i < n; i++)
        free(passwords[i]);
    free(passwords);
    free(scores);

    return 0;
}

