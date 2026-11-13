/* 
programmer: Yusra Kamal
Section: BDS-1A
Roll NO: 26K-2518
Assignment: 2
Question: 1
Topic: Library managment system
*/






#include <stdio.h>
#include <string.h>

#define MAX_BORROW 3
#define TOTAL_BOOKS 5

void displayMenu();
void registerMember(char name[], int *studentID, int *memberType);
void displayBooks(int bookIDs[], char bookTitles[][50], int availableCopies[], int totalBooks);
void borrowBook(int bookIDs[], char bookTitles[][50], int availableCopies[], int totalBooks,
                int borrowedBookIDs[], int *borrowedCount, int memberType);
float returnBook(int bookIDs[], int availableCopies[], int totalBooks,
                 int borrowedBookIDs[], int *borrowedCount, int memberType, float *totalFine);
void displayMemberRecord(char name[], int studentID, int memberType,
                         int borrowedBookIDs[], int borrowedCount,
                         float totalFine, float fineAfterWaiver);

int main()
{
    int bookIDs[TOTAL_BOOKS] = {101, 102, 103, 104, 105};
    char bookTitles[TOTAL_BOOKS][50] = {
        "Programming in C",
        "Data Structures",
        "Database Systems",
        "Discrete Mathematics",
        "Operating Systems"
    };
    int availableCopies[TOTAL_BOOKS] = {3, 2, 1, 4, 2};

    char name[50] = "";
    int studentID = 0, memberType = 0;
    int borrowedBookIDs[MAX_BORROW];
    int borrowedCount = 0;
    float totalFine = 0, fineAfterWaiver = 0;
    int registered = 0, choice;

    do
    {
        displayMenu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (registered)
                printf("A member is already registered.\n");
            else
            {
                registerMember(name, &studentID, &memberType);
                registered = 1;
            }
            break;

        case 2:
            displayBooks(bookIDs, bookTitles, availableCopies, TOTAL_BOOKS);
            break;

        case 3:
            if (!registered)
                printf("Please register first (option 1).\n");
            else
                borrowBook(bookIDs, bookTitles, availableCopies, TOTAL_BOOKS,
                           borrowedBookIDs, &borrowedCount, memberType);
            break;

        case 4:
            if (!registered)
                printf("Please register first (option 1).\n");
            else
                fineAfterWaiver += returnBook(bookIDs, availableCopies, TOTAL_BOOKS,
                                              borrowedBookIDs, &borrowedCount,
                                              memberType, &totalFine);
            break;

        case 5:
            if (!registered)
                printf("Please register first (option 1).\n");
            else
                displayMemberRecord(name, studentID, memberType, borrowedBookIDs,
                                    borrowedCount, totalFine, fineAfterWaiver);
            break;

        case 6:
            printf("Exiting program. Goodbye!\n");
            break;

        default:
            printf("Invalid choice. Please enter a number from 1 to 6.\n");
        }
    } while (choice != 6);

    return 0;
}

void displayMenu()
{
    printf("\n===== UNIVERSITY LIBRARY SYSTEM =====\n");
    printf("1. Register Member\n");
    printf("2. Display Available Books\n");
    printf("3. Borrow a Book\n");
    printf("4. Return a Book\n");
    printf("5. Display Member Record\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

void registerMember(char name[], int *studentID, int *memberType)
{
    printf("Enter name: ");
    scanf(" %49[^\n]", name);

    do
    {
        printf("Enter student ID: ");
        scanf("%d", studentID);
        if (*studentID <= 0)
            printf("Invalid ID. Must be a positive number.\n");
    } while (*studentID <= 0);

    do
    {
        printf("Membership type (1 = Student, 2 = Faculty): ");
        scanf("%d", memberType);
        if (*memberType != 1 && *memberType != 2)
            printf("Invalid membership type. Enter 1 or 2.\n");
    } while (*memberType != 1 && *memberType != 2);

    printf("Registration successful. Allowed borrowing period: %d days.\n",
           (*memberType == 1) ? 14 : 30);
}

void displayBooks(int bookIDs[], char bookTitles[][50], int availableCopies[], int totalBooks)
{
    int i;
    printf("\n%-10s %-25s %-10s\n", "Book ID", "Title", "Available");
    printf("------------------------------------------------\n");
    for (i = 0; i < totalBooks; i++)
        printf("%-10d %-25s %-10d\n", bookIDs[i], bookTitles[i], availableCopies[i]);
}

void borrowBook(int bookIDs[], char bookTitles[][50], int availableCopies[], int totalBooks,
                int borrowedBookIDs[], int *borrowedCount, int memberType)
{
    int id, days, i, index = -1;
    int allowed = (memberType == 1) ? 14 : 30;

    if (*borrowedCount >= MAX_BORROW)
    {
        printf("Limit reached. You can borrow a maximum of %d books at a time.\n", MAX_BORROW);
        return;
    }

    printf("Enter book ID: ");
    scanf("%d", &id);

    for (i = 0; i < totalBooks; i++)
    {
        if (bookIDs[i] == id)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        printf("Invalid book ID.\n");
        return;
    }
    if (availableCopies[index] == 0)
    {
        printf("Sorry, no copies of \"%s\" are available.\n", bookTitles[index]);
        return;
    }
    for (i = 0; i < *borrowedCount; i++)
    {
        if (borrowedBookIDs[i] == id)
        {
            printf("You have already borrowed this book.\n");
            return;
        }
    }

    do
    {
        printf("Enter number of days you intend to keep the book: ");
        scanf("%d", &days);
        if (days <= 0)
            printf("Days must be positive.\n");
    } while (days <= 0);

    if (days > allowed)
        printf("Note: the permitted period is %d days. Late fines apply after that.\n", allowed);

    borrowedBookIDs[*borrowedCount] = id;
    (*borrowedCount)++;
    availableCopies[index]--;
    printf("You have borrowed \"%s\".\n", bookTitles[index]);
}

float returnBook(int bookIDs[], int availableCopies[], int totalBooks,
                 int borrowedBookIDs[], int *borrowedCount, int memberType, float *totalFine)
{
    int id, days, i, pos = -1, index = -1;
    int allowed = (memberType == 1) ? 14 : 30;
    int rate    = (memberType == 1) ? 20 : 10;
    float fine = 0, payable = 0;
    char code[30];

    if (*borrowedCount == 0)
    {
        printf("You have no borrowed books to return.\n");
        return 0;
    }

    printf("Enter book ID to return: ");
    scanf("%d", &id);

    for (i = 0; i < *borrowedCount; i++)
    {
        if (borrowedBookIDs[i] == id)
        {
            pos = i;
            break;
        }
    }
    if (pos == -1)
    {
        printf("You have not borrowed this book.\n");
        return 0;
    }

    do
    {
        printf("Enter actual number of days the book was kept: ");
        scanf("%d", &days);
        if (days <= 0)
            printf("Days must be positive.\n");
    } while (days <= 0);

    /* increase available copies */
    for (i = 0; i < totalBooks; i++)
        if (bookIDs[i] == id)
            index = i;
    availableCopies[index]++;

    /* remove from borrowed list by shifting left */
    for (i = pos; i < *borrowedCount - 1; i++)
        borrowedBookIDs[i] = borrowedBookIDs[i + 1];
    (*borrowedCount)--;

    /* fine */
    if (days > allowed)
    {
        fine = (days - allowed) * rate;
        *totalFine += fine;
        printf("Late return by %d day(s). Fine: Rs. %.2f\n", days - allowed, fine);

        printf("Enter membership code for waiver (or any other text to skip): ");
        scanf("%29s", code);

        if (strcmp(code, "LIB2026") == 0)
        {
            payable = fine * 0.5f;
            printf("Code accepted. 50%% waiver applied.\n");
        }
        else
        {
            payable = fine;
            printf("Incorrect code. No waiver applied.\n");
        }
        printf("Fine payable for this return: Rs. %.2f\n", payable);
    }
    else
    {
        printf("Book returned on time. No fine.\n");
    }

    return payable;
}

void displayMemberRecord(char name[], int studentID, int memberType,
                         int borrowedBookIDs[], int borrowedCount,
                         float totalFine, float fineAfterWaiver)
{
    int i;
    printf("\n===== MEMBER RECORD =====\n");
    printf("Name: %s\n", name);
    printf("Student ID: %d\n", studentID);
    printf("Membership type: %s\n", (memberType == 1) ? "Student" : "Faculty");

    printf("Currently borrowed books: ");
    if (borrowedCount == 0)
        printf("None");
    else
        for (i = 0; i < borrowedCount; i++)
            printf("%d ", borrowedBookIDs[i]);
    printf("\n");

    printf("Total fine before waiver: Rs. %.2f\n", totalFine);
    printf("Final fine payable after waiver: Rs. %.2f\n", fineAfterWaiver);
}
