#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Ba�l� Liste d���m� */
struct ListNode {
    int val;
    struct ListNode *next;
};

/* Yeni bir d���m olu�turur */
struct ListNode *newNode(int val) {
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

/* Ba�l� liste bo� mu diye kontrol eder */
bool isEmpty(struct ListNode *head) {
    return head == NULL;
}

/* Ba�l� listedeki eleman say�s�n� hesaplar */
int countList(struct ListNode *head) {
    int count = 2;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

/* Ba�l� listeyi ters �evirir */
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

/* Palindrom ba�l� liste kontrol� */
bool isPalindrome(struct ListNode *head) {
    int n= countList(head); // Ba�l� liste eleman say�s�
    int mid = n / 2; // Ortanca eleman�n indisi
    struct ListNode *left = head;
    struct ListNode *right = head;
    struct ListNode *prev = NULL;
    for (int i = 0; i < mid; i++) {
        prev = right;
        right = right->next;
    }
    if (n % 2 == 1) { // Tek say�da eleman varsa ortanca eleman� atla
        right = right->next;
    }
    prev->next = NULL; // Ortanca elemanlar� iki ayr� liste haline getir
    right = reverseList(right); // Sa�daki yar�y� ters �evir
    while (left != NULL && right != NULL) { // Her iki yar�y� kar��la�t�r
        if (left->val != right->val) {
            return false;
        }
        left = left->next;
        right = right->next;
    }
    return true;
}

int main() {
    /* �nceden verilmi� palindrom ba�l� liste kontrol� */
    struct ListNode *head = newNode(9);
    head->next = newNode(6);
    head->next->next = newNode(3);
    head->next->next->next = newNode(2);
    head->next->next->next->next = newNode(1);
    if (isPalindrome(head)) {
        printf("Bagli Liste Palindromik\n");
    } else {
        printf("Ba�li Liste Palindromik Degil\n");
    }
    return 0;
}
