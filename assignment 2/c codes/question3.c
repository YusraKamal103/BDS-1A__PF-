/*
programmer: Yusra Kamal
Section: BDS-1A
Roll NO: 26K-2518
Assignment: 2
Question: 3
Topic: Green House Temperature Monitoring system

*/

#include <stdio.h>



void sensor_calc(int array[10][10], int rows, int cols) {
    int avg_array[rows];
    // Function implementation for sensor calculation
    for (int i = 0; i < rows; i++) {
        int sum = 0;
        int critical = 0;
        int warning = 0;
        for (int j = 0; j < cols; j++) {
            sum += array[i][j];
            if (array[i][j]>=40){
                critical ++;

            }
            if (array[i][j]>=35 && array[i][j]<39){
                warning ++;
            }
        }
        float average = (float)sum / cols;
        avg_array[i] = average;

        //consective streak
        int streak = 0;
        for (int j = 0; j < cols; j++) {
            if (array[i][j]>=35){
                streak = 1;
                for (int k = j + 1; k < cols && array[i][k] >= 35; k++) {
                    streak++;
                }
                
            }
       

        int max_temp = array[i][0];
        int min_temp = array[i][0];
        for (int j = 1; j < cols; j++) {
            if (array[i][j] > max_temp) {
                max_temp = array[i][j];
            }
            if (array[i][j] < min_temp) {
                min_temp = array[i][j];
            }
        }
        //printing the results
        printf("Sensor %d: ", i + 1);
        printf("total %d ", sum);
        printf("average %.2f ", average);
        printf("Max %d ", max_temp);
        printf("Min %d \n", min_temp);
        printf("Warning %d ", warning);
        printf("Critical %d ", critical);
        printf("Longest Hot Streak %d \n", streak);
        
    }
    int max_avg = 0;
    int j;
    for (int i = 0; i < rows; i++) {
        if (avg_array[i] > max_avg) {
            max_avg = avg_array[i];
            j=i;

        }
    }
    printf("Highest Average:sensor %d: %.2f\n", j + 1, (float)max_avg);

    return 0;
}

int main(){
    int sensor , reading ;
    printf("Enter the number of sensors: ");

    return 0;
}
