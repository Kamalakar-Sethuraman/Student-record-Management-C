#ifndef HEADER_H
#define HEADER_H

typedef struct student
{
    struct student *prv;
    int roll;
    char name[20];
    float marks;
    struct student *next;
} ST;

void add_middle(ST **);
void print(ST *);
void rev_print(ST *);
void rev_data(ST *);
void rev_links(ST **);
void delete_node(ST **, int);
void delete_all(ST **);
void save(ST *);
int count(ST *);
void load(ST **);
void search(ST *, int);

#endif
