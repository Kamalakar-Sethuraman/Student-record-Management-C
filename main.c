#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

int main()
{
    ST *hptr = 0;
    int choice, roll,roll_up;
    char op, choice2;

    load(&hptr);

    do
    {
        printf("\n========== STUDENT RECORD MANAGEMENT ==========\n");
        printf("1. Add a student record\n");
        printf("2. Display all records\n");
        printf("3. Delete a specific record\n");
        printf("4. Delete all records\n");
        printf("5. Reverse print\n");
        printf("6. Search by roll number\n");
        printf("7. Update a record\n");
        printf("8. Save to file\n");
        printf("0. Exit\n");
        printf("================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            do
            {
                add_middle(&hptr);
                printf("Add another record (Y/N)? ");
                scanf(" %c", &choice2);
            } while (choice2 == 'y' || choice2 == 'Y');
            break;
        case 2:
            print(hptr);
            break;
        case 3:
            printf("Enter roll number to delete: ");
            scanf("%d", &roll);
            delete_node(&hptr, roll);
            break;
        case 4:
            delete_all(&hptr);
            save(hptr);
            printf("All records deleted.\n");
            break;
        case 5:
            rev_print(hptr);
            break;
        case 6:
            printf("Enter roll number to search: ");
            scanf("%d", &roll);
            search(hptr, roll);
            break;
        case 7:
            printf("Enter the roll number to update the record:");
            scanf("%d",&roll_up);
            update(hptr,roll_up);
            printf("Data updated successfully.\n");
            break;
        case 8:
            save(hptr);
            printf("Data saved successfully.\n");
            break;
        case 0:
            printf("Saving before exit...\n");
            save(hptr);
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}
