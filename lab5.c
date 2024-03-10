#include <stdio.h>
#define MONTHS 12

// Function declerations
void readSales(double sales[]);
void printMonthlySales(double sales[]);
void printSalesSummary(double sales[]);
void printMovingAverages(double sales[]);
void printSalesHighToLow(double sales[]);
void printPossibleGoal(int score);

int main(void) {
  // Creating a Array to Store the Sales

  printf("First Problem \n\n");
  double sales[MONTHS];
  int score;
  readSales(sales);
  printMonthlySales(sales);
  printSalesSummary(sales);
  printMovingAverages(sales);
  printSalesHighToLow(sales);

  printf("Second Problem \n\n");

  do {
    printf("Enter the NFL score (0 or 1 to STOP): ");
    scanf("%d", &score);

    if (score <= 1) {
      break;
    }

    // Call the function to print scoring combinations
    printPossibleGoal(score);
  } while (score > 1);
  return 0;
}

// Function definitions
void readSales(double sales[]) {
  FILE *file = fopen("sales.txt", "r");
  if (file == NULL) {
    printf("Something Went Wrong");
    return;
  }
  for (int i = 0; i < MONTHS; i++) {
    fscanf(file, "%lf", &sales[i]);
  }
  fclose(file);
}

void printMonthlySales(double sales[]) {
  const char *months[MONTHS] = {
      "January", "February", "March",     "April",   "May",      "June",
      "July",    "August",   "September", "October", "November", "December"};

  printf("Monthly sales report for 2022: \n\n");
  for (int i = 0; i < MONTHS; i++) {
    printf("%s: $%.2f\n", months[i], sales[i]);
  }
}

void printSalesSummary(double sales[]) {
  double minSale = sales[0];
  double maxSale = sales[0];
  double sum = 0;
  double averageSale;

  for (int i = 0; i < MONTHS; i++) {
    if (sales[i] < minSale) {
      minSale = sales[i];
    }
    if (sales[i] > maxSale) {
      maxSale = sales[i];
    }
    sum += sales[i];
  }
  averageSale = sum / MONTHS;
  printf("\nSales Summary:\nMinimum Sales: $%.2f\nMaximum Sales: "
         "$%.2f\nAverage Sales: $%.2f\n",
         minSale, maxSale, averageSale);
}

void printMovingAverages(double sales[]) {
  printf("\nSix-Month Moving Averages:\n");
  double sum;
  double averageSales;

  // Jan to June
  sum = 0;
  for (int i = 0; i < 6; i++) {
    sum += sales[i];
  }
  averageSales = sum / 6;
  printf("January - June: $%.2f\n", averageSales);

  // Feburary to July
  sum = 0;
  for (int i = 1; i < 7; i++) {
    sum += sales[i];
  }
  averageSales = sum / 6;
  printf("February - July: $%.2f\n", averageSales);

  // March to August
  sum = 0;
  for (int i = 2; i < 8; i++) {
    sum += sales[i];
  }
  averageSales = sum / 6;
  printf("March - August: $%.2f\n", averageSales);

  // April to September
  sum = 0;
  for (int i = 3; i < 9; i++) {
    sum += sales[i];
  }
  averageSales = sum / 6;
  printf("April - September: $%.2f\n", averageSales);

  // May to October
  sum = 0;
  for (int i = 4; i < 10; i++) {
    sum += sales[i];
  }
  averageSales = sum / 6;
  printf("May - October: $%.2f\n", averageSales);

  // June to November
  sum = 0;
  for (int i = 5; i < 11; i++) {
    sum += sales[i];
  }
  averageSales = sum / 6;
  printf("June - November: $%.2f\n", averageSales);

  // July to December
  sum = 0;
  for (int i = 6; i < 12; i++) {
    sum += sales[i];
  }
  averageSales = sum / 6;
  printf("July - December: $%.2f\n", averageSales);
}

void printSalesHighToLow(double sales[]) {
  // array to copy over the original sales array
  double sortedSalesArray[MONTHS];
  const char *months[MONTHS] = {
      "January", "February", "March",     "April",   "May",      "June",
      "July",    "August",   "September", "October", "November", "December"};

  // copying to original array
  for (int i = 0; i < MONTHS; i++) {
    sortedSalesArray[i] = sales[i];
  }

  // using bubble sort to sort the array high to low
  for (int i = 0; i < MONTHS - 1; i++) {
    for (int j = 0; j < MONTHS - i - 1; j++) {
      if (sortedSalesArray[j] < sortedSalesArray[j + 1]) {
        double temp = sortedSalesArray[j];
        sortedSalesArray[j] = sortedSalesArray[j + 1];
        sortedSalesArray[j + 1] = temp;
      }
    }
  }

  // priting the sorted array
  printf("\nSales Report (Highest to Lowest):\n");
  for (int i = 0; i < MONTHS; i++) {
    for (int j = 0; j < MONTHS; j++) {
      if (sortedSalesArray[i] == sales[j]) {
        printf("%s: $%.2f\n", months[j], sortedSalesArray[i]);
      }
    }
  }
  printf("\n");
}

void printPossibleGoal(int score) {
  printf("Possible combinations of scoring plays\n");
  // Nested loops to iterate through possible combinations
  for (int touchDown = 0; touchDown <= score / 6;
       ++touchDown) {    
    // Touchdowns (6 points)                          
    for (int flag = 0; flag <= score / 3; ++flag) { 
        // Field goals (3 points)
      for (int safety = 0; safety <= score / 2;
           ++safety) { 
        // Safeties (2 points)
        for (int td2 = 0; td2 <= touchDown;
             ++td2) { 
           // Touchdowns followed by 2-point conversions
          for (int td1 = 0; td1 <= touchDown - td2;
               ++td1) { 
            // Touchdowns followed by 1-point field goals
            if (6 * touchDown + 3 * flag + 2 * safety + 2 * td2 + td1 ==
                score) {
              printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                     td2, td1, touchDown - td2 - td1, flag, safety);
            }
          }
        }
      }
    }
  }
  printf("\n");
}