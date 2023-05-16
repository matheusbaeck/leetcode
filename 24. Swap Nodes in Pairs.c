/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   24. Swap Nodes in Pairs.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 03:08:02 by marvin            #+#    #+#             */
/*   Updated: 2023/05/16 03:08:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

 

Example 1:

https://assets.leetcode.com/uploads/2020/10/03/swap_ex1.jpg

Input: head = [1,2,3,4]
Output: [2,1,4,3]
Example 2:

Input: head = []
Output: []
Example 3:

Input: head = [1]
Output: [1]
 

Constraints:

The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100

https://leetcode.com/problems/swap-nodes-in-pairs/submissions/951118049/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *swap(struct ListNode *head)
{
    struct ListNode *node;

    node = head->next;
    head->next = node->next;
    node->next = head;
    return (node);
}



struct ListNode* swapPairs(struct ListNode* head)
{
    struct ListNode *node;

    if (head == NULL || head->next == NULL)
        return head;
    head = swap(head);
    node = head->next;
    while (node->next && node->next->next != NULL)
    {
        node->next = swap(node->next);
        node = node->next->next;
    }
    return (head);
}
