#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *reverse_linkedlist(struct ListNode* head) {
  struct ListNode *curr = head;
  struct ListNode *upcoming = head;

  while (upcoming != NULL && curr->next != NULL) {
    if (curr == head) {
      struct ListNode *temp = curr;
      curr = curr->next;
      if (curr->next != NULL) {
        upcoming = curr->next;
      } else {
        upcoming = NULL;
      }
      curr->next = temp;
      temp->next = NULL;
    } else {
      struct ListNode *temp = curr;
      curr = upcoming;
      if (curr->next != NULL) {
        upcoming = curr->next;
      } else {
        upcoming = NULL;
      }
      curr->next = temp;      
    }
  }

  return curr;
}

struct ListNode *removeNthFromEnd(struct ListNode* head, int n){
  if (head->next == NULL && n > 0) {
    return NULL;
  }
  struct ListNode *reversed_head = reverse_linkedlist(head);
  struct ListNode *prev = reversed_head;
  struct ListNode *curr = curr = prev;

  for (int i = 1; i < n && curr->next != NULL; i++) {
    prev = curr;
    curr = curr->next;
  }
  
  if (n == 1 && curr->next->next == NULL) {
    return curr->next;
  } else if (n == 1 && curr->next->next != NULL) {
    head = reverse_linkedlist(curr->next);
  } else {
    prev->next = curr->next;
    head = reverse_linkedlist(reversed_head);
  }
  
  return head;
}

int main() {
  struct ListNode n1;
  struct ListNode n2;
  struct ListNode n3;
  struct ListNode n4;
  struct ListNode n5;

  struct ListNode n6;

  struct ListNode n7;
  struct ListNode n8;

  n1.val = 1;
  n1.next = &n2;
  n2.val = 2;
  n2.next = &n3;
  n3.val = 3;
  n3.next = &n4;
  n4.val = 4;
  n4.next = &n5;
  n5.val = 5;
  n5.next = NULL;

  n6.val = 1;
  n6.next = NULL;

  n7.val = 1;
  n7.next = &n8;
  n8.val = 2;
  n8.next = NULL;

  removeNthFromEnd(&n1, 2);
  removeNthFromEnd(&n6, 1);
  removeNthFromEnd(&n7, 2);

  return 0;
}