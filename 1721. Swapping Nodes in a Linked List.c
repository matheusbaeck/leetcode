/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1721. Swapping Nodes in a Linked List.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 01:32:44 by marvin            #+#    #+#             */
/*   Updated: 2023/05/16 01:32:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).

 https://assets.leetcode.com/uploads/2020/09/21/linked1.jpg

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]
Example 2:

Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]
 

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 105
0 <= Node.val <= 100
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int lstlen(struct ListNode* node)
{
    int i;
    
    i = 0;
    while (node->next != NULL && ++i)
        node = node->next;
    return (i);
}

struct ListNode* lstgoto(struct ListNode *node, int n)
{
    int i = -1;

    while (++i < n)
        node = node->next;
    return (node);
}

struct ListNode* swapNodes(struct ListNode* head, int k)
{  
    int i;
    int temp;

    i = k - 1;
    k = lstlen(head);
    if (i == k - i)
        return (head);
    else
    {
        temp = lstgoto(head, i)->val;
        lstgoto(head, i)->val = lstgoto(head, k - i)->val;
        lstgoto(head, k - i)->val = temp;
    }
    return (head);
}

// MISS UNDERSTOOD
// struct ListNode* swapNodes(struct ListNode* head, int k)
// {
//     ListNode *node_i;
//     ListNode *node_j;
//     ListNode *node_k;   
//     int i;
//     int j;

//     i = k;
//     j = lstlen(head) - i;
//     if (i == j || lstlen(head) < 2)
//         return (head);
//     if (i > j)
//     {
//         i = j;
//         j = k;
//     }
//     if (i > 1)
//     {
//         node_i = goto(head, i - 2);
//         node_j = goto(head, j -2);
//         node_k = goto(head, j);
//         node_j->next->next = node_i->next->next;
//         node_i->next->next = node_k;
//         node_k = node_j->next;
//         node_j->next = node_i->next;
//         node_i->next = node_k;
//     }
//     else if (lstlen(head) > 2)
//     {
//         node_i = goto(head, lstlen(head) - 2);
//         node_i->next->next = head->next;
//         node_j = node_i->next;
//         node_i->next = head;
//         head->next = NULL;
//         head = node_j;
//     }
//     else
//     {
//         head->next->next = head;
//         head = head->next;
//         head->next->next = NULL;
//     }
//     return (head);
// }