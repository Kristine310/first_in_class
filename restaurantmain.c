/*
For this program, I plan to create a random number generator that will select a number between 0 to 3. Each of the four meals will be stored in a string array and 
the prices for each will be stored in a double array in the same index its corresponding food is in the string array. The program then gets the data at the randomly
chosen index as the meal cost that the tax and tip will go by (they may be stored in a separate double variable). 

The program will then prompt the user to input the tax and tip percentages which are then turned into decimals (using percent/100). A double variable will be made 
to store the tax amount data and it will be calculated by multiplying the decimal form of the tax percentage and the meal cost. This same process will be done for 
the tip amount. 

Another double variable will be made to add up all of the amounts (meal cost, tax, and tip) for the total cost. 

A few printf statements will then print out the numbers for that data.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    const char * foodItem[] = {"salad", "soup", "sandwich", "pizza"};
    const double foodPrice[] = {9.95, 4.55, 13.25, 22.35};
    double mealCost, taxCost, tipCost, totalCost, taxPercent, tipPercent;

    time_t t;
    srand((unsigned) time(&t));
    int foodIndex = rand() % 4;
    mealCost = foodPrice[foodIndex];

    // Use %lf to load doubles from scanf
    printf("Enter the tax percentage: ");
    scanf("%lf", &taxPercent);
    printf("Enter the tip percentage: ");
    scanf("%lf", &tipPercent);

    taxCost = mealCost * (taxPercent / 100);
    tipCost = mealCost * (tipPercent / 100);
    totalCost = mealCost + taxCost + tipCost;

    printf("You have purchased a %s.\n", foodItem[foodIndex]);
    printf("Meal Cost: $%.2f\n", mealCost);
    printf("Tax Amount: $%.2f\n", taxCost);
    printf("Tip Amount: $%.2f\n", tipCost);
    printf("Total Bill: $%.2f\n", totalCost);
    return 0;
}