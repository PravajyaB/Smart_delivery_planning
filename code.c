#include <stdio.h>

#define MAX 100

struct Package {
    int packageNo;
    float value;
    float weight;
    float ratio;
    float fraction;
};

void enterPackageDetails(struct Package p[], int *n, float *capacity);
void displayPackageDetails(struct Package p[], int n, float capacity);
void calculateRatio(struct Package p[], int n);
void sortPackages(struct Package p[], int n);
float findMaximumValue(struct Package p[], int n, float capacity);
void displaySelectedPackages(struct Package p[], int n, float capacity);

int main() {
    struct Package packages[MAX];
    int n = 0;
    int choice;
    float capacity = 0.0;
    float maxValue;

    do {
        printf("\n============================================\n");
        printf("       SMART DELIVERY PLANNING\n");
        printf("       FRACTIONAL KNAPSACK\n");
        printf("============================================\n");
        printf("1. Enter Package Details\n");
        printf("2. Display Package Details\n");
        printf("3. Calculate Value/Weight Ratio\n");
        printf("4. Sort Packages by Ratio\n");
        printf("5. Find Maximum Value\n");
        printf("6. Display Selected Packages\n");
        printf("7. Exit\n");
        printf("============================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enterPackageDetails(packages, &n, &capacity);
                break;

            case 2:
                if (n == 0)
                    printf("\nPlease enter package details first.\n");
                else
                    displayPackageDetails(packages, n, capacity);
                break;

            case 3:
                if (n == 0) {
                    printf("\nPlease enter package details first.\n");
                } else {
                    calculateRatio(packages, n);
                    printf("\nValue/Weight ratios calculated successfully.\n");
                }
                break;

            case 4:
                if (n == 0) {
                    printf("\nPlease enter package details first.\n");
                } else {
                    calculateRatio(packages, n);
                    sortPackages(packages, n);
                    printf("\nPackages sorted by decreasing Value/Weight ratio.\n");
                }
                break;

            case 5:
                if (n == 0) {
                    printf("\nPlease enter package details first.\n");
                } else {
                    calculateRatio(packages, n);
                    sortPackages(packages, n);
                    maxValue = findMaximumValue(packages, n, capacity);
                    printf("\nMaximum Value Obtained = %.2f\n", maxValue);
                }
                break;

            case 6:
                if (n == 0) {
                    printf("\nPlease enter package details first.\n");
                } else {
                    calculateRatio(packages, n);
                    sortPackages(packages, n);
                    findMaximumValue(packages, n, capacity);
                    displaySelectedPackages(packages, n, capacity);
                }
                break;

            case 7:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 7);

    return 0;
}

void enterPackageDetails(struct Package p[], int *n, float *capacity) {
    int i;

    printf("\nEnter number of packages: ");
    scanf("%d", n);

    if (*n <= 0 || *n > MAX) {
        printf("Invalid number of packages.\n");
        *n = 0;
        return;
    }

    printf("Enter vehicle capacity: ");
    scanf("%f", capacity);

    for (i = 0; i < *n; i++) {
        p[i].packageNo = i + 1;

        printf("\nPackage %d\n", i + 1);

        printf("Enter value: ");
        scanf("%f", &p[i].value);

        printf("Enter weight: ");
        scanf("%f", &p[i].weight);

        p[i].ratio = 0.0;
        p[i].fraction = 0.0;
    }

    printf("\nPackage details entered successfully.\n");
}

void displayPackageDetails(struct Package p[], int n, float capacity) {
    int i;

    printf("\n============================================\n");
    printf("          PACKAGE DETAILS\n");
    printf("============================================\n");

    printf("%-10s %-10s %-10s %-12s\n",
           "Package", "Value", "Weight", "Value/Weight");

    for (i = 0; i < n; i++) {
        printf("%-10d %-10.2f %-10.2f %-12.2f\n",
               p[i].packageNo,
               p[i].value,
               p[i].weight,
               p[i].ratio);
    }

    printf("\nVehicle capacity = %.2f\n", capacity);
}

void calculateRatio(struct Package p[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        if (p[i].weight > 0)
            p[i].ratio = p[i].value / p[i].weight;
        else
            p[i].ratio = 0.0;
    }
}

void sortPackages(struct Package p[], int n) {
    int i, j;
    struct Package temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (p[j].ratio < p[j + 1].ratio) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

float findMaximumValue(struct Package p[], int n, float capacity) {
    int i;
    float remainingCapacity = capacity;
    float totalValue = 0.0;

    for (i = 0; i < n; i++) {
        p[i].fraction = 0.0;
    }

    for (i = 0; i < n; i++) {
        if (p[i].weight <= remainingCapacity) {
            p[i].fraction = 1.0;
            remainingCapacity -= p[i].weight;
            totalValue += p[i].value;
        } else {
            if (remainingCapacity > 0) {
                p[i].fraction = remainingCapacity / p[i].weight;
                totalValue += p[i].value * p[i].fraction;
                remainingCapacity = 0;
            }
            break;
        }
    }

    return totalValue;
}

void displaySelectedPackages(struct Package p[], int n, float capacity) {
    int i;
    float totalWeight = 0.0;
    float totalValue = 0.0;

    printf("\n============================================\n");
    printf("        SELECTED PACKAGES\n");
    printf("============================================\n");

    printf("%-10s %-10s %-10s %-12s %-12s\n",
           "Package", "Value", "Weight",
           "Ratio", "Fraction");

    for (i = 0; i < n; i++) {
        if (p[i].fraction > 0) {
            printf("%-10d %-10.2f %-10.2f %-12.2f %-12.2f\n",
                   p[i].packageNo,
                   p[i].value,
                   p[i].weight,
                   p[i].ratio,
                   p[i].fraction);

            totalWeight += p[i].weight * p[i].fraction;
            totalValue += p[i].value * p[i].fraction;
        }
    }

    printf("\nVehicle capacity = %.2f\n", capacity);
    printf("Total weight     = %.2f\n", totalWeight);
    printf("Maximum value    = %.2f\n", totalValue);
}
