#pragma once

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data);

struct Node* reverse(struct Node* head);

void printList(struct Node* head);