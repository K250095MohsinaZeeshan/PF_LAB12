#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, updateStock;
    int *stock;
    int total = 0, minStock = 0;

    printf("Enter number of book categories: ");
    scanf("%d", &n);

    stock = (int *)malloc(n * sizeof(int));
    if (!stock) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    for (i = 0; i < n; i++) {
        printf("Enter stock for category %d: ", i);
        scanf("%d", &stock[i]);
        total += stock[i];
        if (stock[i] < stock[minStock])
            minStock = i;
    }
    printf("\nTotal Stock = %d\n", total);
    printf("Average Stock per category = %.2f\n", (float)total / n);
    printf("Category with lowest stock = %d\n", minStock);

    printf("\nEnter category index to update: ");
    scanf("%d", &updateStock);
    if (updateStock >= 0 && updateStock < n) {
        printf("Enter new stock value: ");
        scanf("%d", &stock[updateStock]);
    } else {
        printf("Invalid index!\n");
    }
    free(stock);
    return 0;
}

