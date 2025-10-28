#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

void add_middle(ST **ptr)
{
    ST *temp = malloc(sizeof(ST));
    printf("Enter roll, name & marks: ");
    scanf("%d %s %f", &temp->roll, temp->name, &temp->marks);

    if ((*ptr == 0) || (temp->roll < (*ptr)->roll))
    {
        temp->next = *ptr;
        temp->prv = 0;
        if (*ptr)
            (*ptr)->prv = temp;
        *ptr = temp;
    }
    else
    {
        ST *last = *ptr;
        while ((last->next) && (temp->roll > last->next->roll))
            last = last->next;

        temp->prv = last;
        temp->next = last->next;
        if (last->next)
            last->next->prv = temp;
        last->next = temp;
    }
}

int count(ST *ptr)
{
    int c = 0;
    while (ptr)
    {
        c++;
        ptr = ptr->next;
    }
    return c;
}

void delete_node(ST **ptr, int n)
{
    if (*ptr == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    ST *temp = *ptr;
    while (temp)
    {
        if (temp->roll == n)
        {
            if (*ptr == temp)
            {
                *ptr = temp->next;
                if (*ptr)
                    (*ptr)->prv = 0;
            }
            else
            {
                temp->prv->next = temp->next;
                if (temp->next)
                    temp->next->prv = temp->prv;
            }
            free(temp);
            printf("Record deleted successfully.\n");
            return;
        }
        temp = temp->next;
    }
    printf("Record not found.\n");
}

void delete_all(ST **ptr)
{
    ST *temp = *ptr;
    while (temp)
    {
        ST *next = temp->next;
        free(temp);
        temp = next;
    }
    *ptr = NULL;
}

void print(ST *ptr)
{
    if (!ptr)
    {
        printf("No records available.\n");
        return;
    }

    printf("\n%-10s %-20s %-10s\n", "ROLL", "NAME", "MARKS");
    printf("---------------------------------------------\n");

    while (ptr)
    {
        printf("%-10d %-20s %-10.2f\n", ptr->roll, ptr->name, ptr->marks);
        ptr = ptr->next;
    }
}

void rev_data(ST *ptr)
{
    ST *p1, *p2, temp;
    int i, c = count(ptr);
    int size = sizeof(ST) - 2 * sizeof(ST *);
    p1 = p2 = ptr;
    while (p2->next)
        p2 = p2->next;

    for (i = 0; i < c / 2; i++)
    {
        memcpy(&temp.roll, &p1->roll, size);
        memcpy(&p1->roll, &p2->roll, size);
        memcpy(&p2->roll, &temp.roll, size);
        p1 = p1->next;
        p2 = p2->prv;
    }
}

void rev_links(ST **ptr)
{
    ST *temp = 0;
    while (*ptr)
    {
        temp = (*ptr)->prv;
        (*ptr)->prv = (*ptr)->next;
        (*ptr)->next = temp;
        *ptr = (*ptr)->prv;
    }
    if (temp)
        *ptr = temp->prv;
}

void rev_print(ST *ptr)
{
    if (!ptr)
        return;
    while (ptr->next)
        ptr = ptr->next;
    printf("\nReverse Order:\n");
    printf("%-10s %-20s %-10s\n", "ROLL", "NAME", "MARKS");
    printf("---------------------------------------------\n");
    while (ptr)
    {
        printf("%-10d %-20s %-10.2f\n", ptr->roll, ptr->name, ptr->marks);
        ptr = ptr->prv;
    }
}

void save(ST *ptr)
{
    FILE *fp = fopen("data.txt", "w");
    if (!fp)
    {
        printf("Error saving file.\n");
        return;
    }
    while (ptr)
    {
        fprintf(fp, "%d %s %f\n", ptr->roll, ptr->name, ptr->marks);
        ptr = ptr->next;
    }
    fclose(fp);
}

void load(ST **ptr)
{
    FILE *fp = fopen("data.txt", "r");
    if (!fp)
    {
        printf("No previous data found.\n");
        return;
    }
    ST temp;
    while (fscanf(fp, "%d %s %f", &temp.roll, temp.name, &temp.marks) == 3)
    {
        ST *new = malloc(sizeof(ST));
        *new = temp;
        new->next = new->prv = NULL;

        if (*ptr == 0)
            *ptr = new;
        else
        {
            ST *last = *ptr;
            while (last->next)
                last = last->next;
            last->next = new;
            new->prv = last;
        }
    }
    fclose(fp);
}

void search(ST *ptr, int roll)
{
    while (ptr)
    {
        if (ptr->roll == roll)
        {
            printf("Found: %d %s %.2f\n", ptr->roll, ptr->name, ptr->marks);
            return;
        }
        ptr = ptr->next;
    }
    printf("Record not found.\n");
}

