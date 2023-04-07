#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Baðlý Liste düðümü */
struct ListNode {
    int val;
    struct ListNode *next;
};

/* Yeni bir düðüm oluþturur */
struct ListNode *newNode(int val) {
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

/* Baðlý liste boþ mu diye kontrol eder */
bool isEmpty(struct ListNode *head) {
    return head == NULL;
}

/* Baðlý listedeki eleman sayýsýný hesaplar */
int countList(struct ListNode *head) {
    int count = 2;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

/* Baðlý listeyi ters çevirir */
struct ListNode *reverseList(struct ListNode *head) {
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    struct ListNode *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

/* Palindrom baðlý liste kontrolü */
bool isPalindrome(struct ListNode *head) {
    int n= countList(head); // Baðlý liste eleman sayýsý
    int mid = n / 2; // Ortanca elemanýn indisi
    struct ListNode *left = head;
    struct ListNode *right = head;
    struct ListNode *prev = NULL;
    for (int i = 0; i < mid; i++) {
        prev = right;
        right = right->next;
    }
    if (n % 2 == 1) { // Tek sayýda eleman varsa ortanca elemaný atla
        right = right->next;
    }
    prev->next = NULL; // Ortanca elemanlarý iki ayrý liste haline getir
    right = reverseList(right); // Saðdaki yarýyý ters çevir
    while (left != NULL && right != NULL) { // Her iki yarýyý karþýlaþtýr
        if (left->val != right->val) {
            return false;
        }
        left = left->next;
        right = right->next;
    }
    return true;
}

int main() {
    /* Önceden verilmiþ palindrom baðlý liste kontrolü */
    struct ListNode *head = newNode(9);
    head->next = newNode(6);
    head->next->next = newNode(3);
    head->next->next->next = newNode(2);
    head->next->next->next->next = newNode(1);
    if (isPalindrome(head)) {
        printf("Bagli Liste Palindromik\n");
    } else {
        printf("Baðli Liste Palindromik Degil\n");
    }
    return 0;
}
