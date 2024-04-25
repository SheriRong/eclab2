#include <stdio.h>

void saleReport(float 
sales[],char *month[]){
  for(int i=0;i<12;i++){
    printf("%-9s $%.2f\n",month[i],sales[i]);
  }
}
  void saleSummary(float sales[], char*month[]){
  float max, min = sales[0];
  int maxIndex, minIndex =0;
  float sum, avg = 0;
  for(int i=0; i< 12;i++){
    if(sales[i]> max){
      max = sales[i];
      maxIndex = i;
    }
    }
  for(int i=0;i<12;i++){
      if(sales[i]<min){
        min = sales[i];
        minIndex=i;
      }
    }
  for(int i =0; i<12;i++){
    sum+=sales[i];
  }
    avg =sum/12;
    printf("Minimum sales:   $%.2f   (%s)\n",min,month[minIndex]);
    printf("Maximum sales:   $%.2f   (%s)\n",max,month[maxIndex]); 
    printf("Average sales:   $%.2f\n",avg);
  }
float average(float sales[], int index, int numMonth) {
  float sum = 0;
  for (int i = index; i < index + numMonth; i++) {
    sum += sales[i];
  }
  return sum / numMonth;
}

void sixMonthSales(float sales[], char *month[]) {
  
  for (int i = 0; i < 7; i++) { 
    printf("%-9s - %-9s $%.2f\n", month[i], month[i + 5], average(sales, i, 6));
  }
}
void descendingOrder(float sales[],char*month[]){
  printf("  Month     Sales\n");
  float temp;
  char *temp2;
  for (int i = 0; i<12;i++){
    for (int j = i+1; j<12; j++){
      if (sales[i]<sales[j]){
        temp = sales[i];
        temp2 = month[i];
        sales[i] = sales[j];
        month[i] = month[j];
        sales[j] = temp;
        month[j] = temp2;
      }
    }
  }
  for (int i =0; i<12; i++)
    {
      printf("%-9s $%.2f\n", month[i], sales[i]);
    }
  
}
int main(void) {
  float sales[12];
  char *month [] ={"January","February","March","April","May","June","July","August","September","October","November","December"};
  for(int i=0; i<12;i++){
    scanf("%f\n", &sales[i]);
  }
  printf("Monthly sales report for 2022:\n\n");
  saleReport (sales,month);
  printf("\nSales summary:\n\n");
  saleSummary(sales, month);
  printf("\nSix-Month Moving Average Report:\n\n");
  sixMonthSales(sales,month);
  printf("\nSales Report (Highest to Lowest):\n\n");
    descendingOrder(sales,month);
    return 0;
}
