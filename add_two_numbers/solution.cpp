#include "solution.hpp"

void increment(ListNode *node) {
  if (node->val >= 10) {
    if (node->next == nullptr) {
      node->next = new ListNode{1};
    } else {
      ++node->next->val;
    }
    node->val -= 10;
  }
}

ListNode *Solution::addTwoNumbers(ListNode *l1, ListNode *l2) {
  ListNode *sol = new ListNode{};
  auto ret = sol;
  while (true) {
    sol->val += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
    l1 = l1 ? l1->next : l1;
    l2 = l2 ? l2->next : l2;

    increment(sol);

    if (l1 == nullptr && l2 == nullptr)
      break;
    sol->next = sol->next ? sol->next : new ListNode{};
    sol = sol->next;
  }

  return ret;
}
