#include <stdio.h>
#include <string.h>

int main() {
    int n;
    printf("Enter number of guests: ");
    scanf("%d", &n);

    float hotelRevenue = 0;

    for (int i = 1; i <= n; i++) {
        char season[20], roomType[20];
        int nights;
        float rate = 0, total, discount = 0;

        printf("\n--- Guest %d ---\n", i);

        printf("Enter season (Peak/OffPeak): ");
        
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        fgets(season, sizeof(season), stdin);
        season[strcspn(season, "\n")] = '\0';  

        printf("Enter room type (Standard/Deluxe/Suite): ");
        fgets(roomType, sizeof(roomType), stdin);
        roomType[strcspn(roomType, "\n")] = '\0';

        printf("Enter number of nights: ");
        scanf("%d", &nights);

        
        if (strcmp(season, "Peak") == 0) {
            if (strcmp(roomType, "Standard") == 0) {
                rate = 5000;
            }
            else if (strcmp(roomType, "Deluxe") == 0) {
                rate = 8000;
            }
            else if (strcmp(roomType, "Suite") == 0) {
                rate = 12000;
            }
        } else { 
            if (strcmp(roomType, "Standard") == 0) {
                rate = 3000;
            }
            else if (strcmp(roomType, "Deluxe") == 0) {
                rate = 5000;
            }
            else if (strcmp(roomType, "Suite") == 0) {
                rate = 8000;
            }
        }

        total = rate * nights;

        
        if (nights > 7) {
            discount = 0.15 * total;
            total -= discount;
        }

        printf("Guest %d Final Price: Rs. %.2f\n", i, total);
        hotelRevenue += total;
    }

    printf("\nHotel Total Revenue: Rs. %.2f\n", hotelRevenue);
    return 0;
}