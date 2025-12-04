#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int containsDigit(char *str) {
    while (*str) {
        if (isdigit(*str))
            return 1;
        str++;
    }
    return 0;
}
int main() {
	printf("USERNAME MANAGEMENT SYSTEM\n");
	printf("__________________________\n");
    int n, i;
    char **users, buffer[100];

    printf("\nEnter 'n' number of usernames: ");
    scanf("%d", &n);
    getchar();

    users = (char **)malloc(n * sizeof(char *));
    if (!users) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    for (i = 0; i < n; i++) {
        printf("Enter username %d: ", i + 1);
        fgets(buffer, 100, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        users[i] = (char *)malloc(strlen(buffer) + 1);
        strcpy(users[i], buffer);
    }

    printf("\nUsernames without digits:\n");
    for (i = 0; i < n; i++) {
        if (!containsDigit(users[i]))
            printf("%s\n", users[i]);
    }
    for (i = 0; i < n; i++)
        free(users[i]);
    free(users);

    return 0;
}

