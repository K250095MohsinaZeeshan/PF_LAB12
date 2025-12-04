#include <stdio.h>
#include <stdlib.h>

int main() {
	
    int n, i, updateIndex, maxIndex = 0;
    int *ratings;
    int total = 0;

    printf("\nEnter number of movie categories: ");
    scanf("%d", &n);

    ratings = (int *)malloc(n * sizeof(int));
    if (!ratings) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    for (i = 0; i < n; i++) {
        printf("Enter rating count for category %d: ", i);
        scanf("%d", &ratings[i]);
        total += ratings[i];
        if (ratings[i] > ratings[maxIndex])
            maxIndex = i;
    }
    printf("\nTotal Ratings = %d\n", total);
    printf("Average Ratings = %.2f\n", (float)total / n);
    printf("Category with highest ratings = %d\n", maxIndex);

    printf("\nEnter category index to update: ");
    scanf("%d", &updateIndex);

    if (updateIndex >= 0 && updateIndex < n) {
        printf("Enter new rating count: ");
        scanf("%d", &ratings[updateIndex]);
    } else {
        printf("Invalid index!\n");
    }
    free(ratings);
    return 0;
}

