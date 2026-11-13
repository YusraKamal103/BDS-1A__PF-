/* 
programmer: Yusra Kamal
Section: BDS-1A
Roll NO: 26K-2518
Assignment: 2
Question: 1
topic : daily sales bar chart
*/






#include <stdio.h>

int   getValidDays();
float calculateDailySales(int dayNumber);
int   findHighestSalesDay(float dailySales[], int numberOfDays);
void  displayBarChart(float dailySales[], int numberOfDays);

int main(void)
{
    float dailySales[7];
    int days, i, bestDay;
    float festivalTotal = 0;

    days = getValidDays();

    for (i = 0; i < days; i++)
    {
        dailySales[i] = calculateDailySales(i + 1);
        festivalTotal += dailySales[i];
    }

    bestDay = findHighestSalesDay(dailySales, days);

    printf("\n===== FESTIVAL SUMMARY =====\n");
    printf("Total festival sales: Rs. %.2f\n", festivalTotal);
    printf("Day with highest sales: Day %d\n", bestDay);
    printf("Highest daily sales: Rs. %.2f\n", dailySales[bestDay - 1]);

    displayBarChart(dailySales, days);

    return 0;
}

int getValidDays()
{
    int days;
    do
    {
        printf("Enter number of festival days (1-7): ");
        scanf("%d", &days);
        if (days < 1 || days > 7)
            printf("Invalid input. Please enter a value between 1 and 7.\n");
    } while (days < 1 || days > 7);

    return days;
}

float calculateDailySales(int dayNumber)
{
    int orders, i;
    float amount, total = 0, highest = 0;

    printf("\nDay %d - Number of orders: ", dayNumber);
    scanf("%d", &orders);

    for (i = 1; i <= orders; i++)
    {
        do
        {
            printf("  Enter amount for order %d: ", i);
            scanf("%f", &amount);
            if (amount <= 0)
                printf("  Invalid amount. Must be greater than zero.\n");
        } while (amount <= 0);

        total += amount;
        if (amount > highest)
            highest = amount;
    }

    printf("\nTotal sales: Rs. %.2f\n", total);
    printf("Average order: Rs. %.2f\n", total / orders);
    printf("Highest order: Rs. %.2f\n", highest);

    return total;
}

int findHighestSalesDay(float dailySales[], int numberOfDays)
{
    int i, bestIndex = 0;

    for (i = 1; i < numberOfDays; i++)
    {
        if (dailySales[i] > dailySales[bestIndex])   /* strict > keeps the earliest day on ties */
            bestIndex = i;
    }
    return bestIndex + 1;
}

void displayBarChart(float dailySales[], int numberOfDays)
{
    int i, j, stars;

    printf("\n===== DAILY SALES BAR CHART =====\n");
    for (i = 0; i < numberOfDays; i++)
    {
        stars = (int)(dailySales[i] / 100);
        printf("Day %d: ", i + 1);
        for (j = 0; j < stars; j++)
            printf("*");
        printf(" (Rs. %.2f)\n", dailySales[i]);
    }
}
