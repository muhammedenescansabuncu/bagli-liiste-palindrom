# bagli-liiste-palindrom
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* Tek Bağlı Liste için Düğüm Yapısı */
struct ListNode {
    int val;                  // Düğümün değeri
    struct ListNode *next;    // Düğümün bir sonraki elemanı işaretçisi
};

/* Yeni Düğüm Oluşturma Fonksiyonu */
struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

/* Bağlı Listenin Ortasını Bulma Fonksiyonu */
struct ListNode* findMiddle(struct ListNode* head) {
    struct ListNode *slow, *fast;
    slow = fast = head;
    while (fast != NULL && fast->next != NULL) {  // İki işaretçi hızlı bir şekilde sağa doğru hareket eder. Hızlı olan ilk olarak listenin sonuna ulaşır.
        slow = slow->next;                        // Yavaş işaretçi listenin ortasına ulaşır.
        fast = fast->next->next;
    }
    return slow;
}

/* Bağlı Listenin Ters Çevirilmesi Fonksiyonu */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev, *cur, *next;
    prev = NULL;
    cur = head;
    while (cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

/* Palindrom Kontrolü Fonksiyonu */
bool isPalindrome(struct ListNode* head) {
    struct ListNode *left, *right, *middle, *prev;
    left = right = middle = head;
    while (right != NULL && right->next != NULL) {   // Ortanca elemana ulaşmak için işaretçileri kullan
        prev = left;                  // Ortanca elemandan önceki elemanı takip et
        left = left->next;            // Sol yarı listesinde bir sonraki elemana ilerle
        right = right->next->next;    // Sağ yarı listesinde iki sonraki elemana ilerle
    }
    if (right != NULL) {               // Listenin uzunluğu tek sayı ise, ortanca elemanı bul
        middle = left;
        left = left->next;
    }
    prev->next = reverseList(left);   // Ortanca elemandan önceki elemanın sonraki elemanını ters çevirilen sol yarı listesiyle eşleştir
    left = head;                      // Yeni sol yarı listesi
    while (right != NULL) {           // Sağ yarı listesi sonuna kadar ilerle
        if (left->val != right->val) {  // Karşılaştırma yap
            return false;
        }
        left = left->next;             // Sol yarı listesinde bir sonraki elemana ilerle
        right = right->next;           // Sağ yarı listesinde bir sonraki elemana ilerle
    }
    return true;                      // Palindrom ise true, değilse false
