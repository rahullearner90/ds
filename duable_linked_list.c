#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *create(struct node *start);
struct node *display(struct node *start);
struct node *sort(struct node *start);

int main() {
    struct node *start = NULL;
    start = create(start);
    start = display(start);
    printf("Sorted List:\n");
    start = sort(start);
    display(start);
    return 0;
}

struct node *create(struct node *start) {
    struct node *new_node, *temp;
    int val;
    printf("Enter data or enter -1 to exit: ");
    scanf("%d", &val);
    
    while (val != -1) {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = val;
        new_node->next = NULL;
        new_node->prev = NULL;

        if (start == NULL) {
            start = new_node;
        } else {
            temp = start;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->prev = temp;
        }

        printf("Enter data or enter -1 to exit: ");
        scanf("%d", &val);
    }
    printf("Linked list successfully created.\n");
    return start;
}

struct node *display(struct node *start) {
    struct node *temp = start;
    printf("The Linked list is: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return start;
}

struct node *sort(struct node *start) {
    struct node *temp1, *temp2;
    int tempData;
    
    for (temp1 = start; temp1 != NULL; temp1 = temp1->next) {
        for (temp2 = temp1->next; temp2 != NULL; temp2 = temp2->next) {
            if (temp1->data > temp2->data) {
                tempData = temp1->data;
                temp1->data = temp2->data;
                temp2->data = tempData;
            }
        }
    }
    return start;
}
