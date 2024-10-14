#include <stdio.h>
#define months 12

int main(){

    FILE * salesFile;
    salesFile = fopen("salesData.txt", "r"); //opens the input file

    float salesFigures[months]; //stores the sales figures
    char *monthsList[months] = {"January","February","March","April","May","June","July","August","September","October","November","December"}; //stores the months

    int i = 0;

    while (!feof(salesFile) && i < months){ //adds each line of the input file to the array of sales figures
        fscanf(salesFile, "%f", &salesFigures[i]);
        i++;
    }
    fclose(salesFile);
    

    //sales sumary report----------------------------------------------
    printf("Sales summary report:\n\n");

    int minPosition = 0; 
    for (int i = 1;i < months;i++){ //finds the position in the array of the smallest sales figure
        if (salesFigures[i] < salesFigures[minPosition]){
            minPosition = i;
        }
    }
    printf("Minimum sales:\t$%.02f (%s)\n", salesFigures[minPosition], monthsList[minPosition]); //prints the smallest sales figure


    int maxPosition = 0;
    for (int i = 1;i < months;i++){ //finds the position in the array of the largest sales figure
        if (salesFigures[i] > salesFigures[maxPosition]){
            maxPosition = i;
        }
    }
    printf("Maximum sales:\t$%.02f (%s)\n", salesFigures[maxPosition], monthsList[maxPosition]); //prints the largest sales figure

    float total = 0.0;
    for (int i = 0;i < months;i++){ //finds the total sales amount
        total += salesFigures[i];
    }
    float avg = total/12.0; //divides the total sales amount by the number of months to get the average
    printf("Average sales:\t$%.02f\n", avg); //prints the average sales amount


    //Six-Month moving average report----------------------------------
    printf("\nSix-Month moving average report:\n\n");

    total = 0.0;
    for (int i = 0;i < 6;i++){ //finds the average sales for January-June
        total += salesFigures[i];
    }
    avg = total/6.0;
    printf("January-June\t$%.02f\n", avg); //prints the average sales for January-June
        
    total = 0.0;
    for (int i = 1;i < 7;i++){ //finds the average sales for February-July
        total += salesFigures[i];
    }
    avg = total/6.0;
    printf("February-July\t$%.02f\n", avg); //prints the average sales for February-July

    total = 0.0;
    for (int i = 2;i < 8;i++){ //finds the average sales for March-August
        total += salesFigures[i];
    }
    avg = total/6.0;
    printf("March-August\t$%.02f\n", avg); //prints the average sales for March-August
    
    total = 0.0;
    for (int i = 3;i < 9;i++){ //finds the average sales for April-September
        total += salesFigures[i];
    }
    avg = total/6.0;
    printf("April-September\t$%.02f\n", avg); //prints the average sales for April-September

    total = 0.0;
    for (int i = 4;i < 10;i++){ //finds the average sales for May-October
        total += salesFigures[i];
    }
    avg = total/6.0;
    printf("May-October\t$%.02f\n", avg); //prints the average sales for May-October

    total = 0.0;
    for (int i = 5;i < 11;i++){ //finds the average sales for June-November
        total += salesFigures[i];
    }
    avg = total/6.0;
    printf("June-November\t$%.02f\n", avg); //prints the average sales for June-November

    total = 0.0;
    for (int i = 6;i < 12;i++){ //finds the average sales for July-December
        total += salesFigures[i];
    }
    avg = total/6.0;
    printf("July-December\t$%.02f\n", avg); //prints the average sales for July-December

    //Sales report (highest to lowest):--------------------------------
    printf("\nSales report (highest to lowest):\n\n");
 
    for (int i = 0; i < months - 1; i++) { //sorts the sales data array into descending order (highest to lowest)
        for (int j = 0; j < months - i - 1; j++) { 
            if (salesFigures[j] < salesFigures[j+1]) { 
                float temp = salesFigures[j]; 
                salesFigures[j] = salesFigures[j+1]; 
                salesFigures[j+1] = temp; 

                //makes sure the months array is ordered the same way as the sales figures array
                char *monthTemp = monthsList[j];
                monthsList[j] = monthsList[j+1];
                monthsList[j+1] = monthTemp;
            } 
        } 
    } 

    printf("Month\tSales\n");
    for (int i = 0; i < months; i++){ //prints the sales and month data in the correct order
        printf("%s\t$%.02f\n", monthsList[i], salesFigures[i]);
    }

    system("Pause");
    return 0;
}