#include <stdio.h>
#include <malloc.h>
#include <conio.h>

struct link {
    int coeff, pow;
    struct link *next;
};

struct link *poly1 = NULL, *poly2 = NULL, *poly3 = NULL;    

void create (struct link *node)
{
    char ch;
    do 
    {
        printf("\nEnter coefficient: ");
        scanf("%d", &node->coeff);
        printf("Enter power: ");
        scanf("%d", &node->pow);
        node->next = (struct link *)malloc(sizeof(struct link));
        node = node->next;
        node->next = NULL;
        printf("Do you want to add more terms (y/n)? ");
        fflush(stdin);
        scanf("%c", &ch);
    } 
    while (ch == 'y' || ch == 'Y');
}


void show (struct link *node)
{
    while (node->next != NULL) 
    {
        printf("%dx^%d", node->coeff, node->pow);
        node = node->next;
        if (node->next != NULL)
            printf(" + ");
    }
}



void add (struct link *poly1, struct link *poly2, struct link *poly3)
{
    while (poly1->next != NULL && poly2->next != NULL)
    {
        if (poly1->pow > poly2->pow) 
        {
            poly3->pow = poly1->pow;
            poly3->coeff = poly1->coeff;
            poly1 = poly1->next;
        } 
        else if (poly1->pow < poly2->pow) 
        {
            poly3->pow = poly2->pow;
            poly3->coeff = poly2->coeff;
            poly2 = poly2->next;
        } 
        else 
        {
            poly3->pow = poly1->pow;
            poly3->coeff = poly1->coeff + poly2->coeff;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        poly3->next = (struct link *)malloc(sizeof(struct link));
        poly3 = poly3->next;
        poly3->next = NULL;
    }
    while (poly1->next != NULL) 
    {
        poly3->pow = poly1->pow;
        poly3->coeff = poly1->coeff;
        poly1 = poly1->next;
        poly3->next = (struct link *)malloc(sizeof(struct link));
        poly3 = poly3->next;
        poly3->next = NULL;
    }
    while (poly2->next != NULL) 
    {
        poly3->pow = poly2->pow;
        poly3->coeff = poly2->coeff;
        poly2 = poly2->next;
        poly3->next = (struct link *)malloc(sizeof(struct link));
        poly3 = poly3->next;
        poly3->next = NULL;
    }
}



int main() 
{
    poly1 = (struct link *)malloc(sizeof(struct link));
    poly2 = (struct link *)malloc(sizeof(struct link));
    poly3 = (struct link *)malloc(sizeof(struct link));

    printf("Create first polynomial:\n");
    create(poly1);
    printf("\nFirst polynomial is: ");
    show(poly1);

    printf("\n\nCreate second polynomial:\n");
    create(poly2);
    printf("\nSecond polynomial is: ");
    show(poly2);

    add(poly1, poly2, poly3);
    printf("\n\nSum of polynomials is: ");
    show(poly3);

    getch();
    return 0;
}