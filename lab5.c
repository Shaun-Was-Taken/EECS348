#include <stdio.h>
#include <stdlib.h>

#define MONTHS 12

void readSales(double sales[], const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("File cannot be opened\n");
        exit(1);
    }
    for (int i = 0; i < MONTHS; i++) {
        if (fscanf(file, "%lf", &sales[i]) != 1) {
            printf("Error reading sales data\n");
            fclose(file);
            exit(1);
        }
    }
    fclose(file);
}

void printSales(const double sales[]) {
    printf("Sales Report:\n");
    for (int i = 0; i < MONTHS; i++) {
        printf("Month %d: %.2f\n", i + 1, sales[i]);
    }
}

int main() {
    double sales[MONTHS];
    const char* filename = "sales.txt"; // Ensure this file exists and is correctly formatted

    readSales(sales, filename);
    printSales(sales);

    // Add the rest of the functionality here

    return 0;
}
