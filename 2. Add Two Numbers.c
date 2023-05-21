/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2. Add Two Numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math42 <math42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 23:26:08 by math42            #+#    #+#             */
/*   Updated: 2023/05/21 23:40:09 by math42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct				ListNode
{
	int				val;
	struct ListNode	*next;
};

struct ListNode	*addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
	int				temp;
	struct ListNode	*l3;
	struct ListNode	*lst;

	temp = 0;
	l3 = (struct ListNode *)malloc(sizeof(struct ListNode));
	l3->val = 0;
	l3->next = NULL;
	lst = l3;
	while (l1 != NULL && l2 != NULL)
	{
		temp += l1->val + l2->val;
		l3->val = temp % 10;
		temp = temp / 10;
		l3->next = (struct ListNode *)malloc(sizeof(struct ListNode));
		l3 = l3->next;
		l1 = l1->next;
		l2 = l2->next;
	}
	if (temp > 0)
	{
		l3->val = temp % 10;
		temp = temp / 10;
		l3->next = (struct ListNode *)malloc(sizeof(struct ListNode));
		l3 = l3->next;
	}
	return (lst);
}

void	printList(struct ListNode *head)
{
	while (head != NULL)
	{
		printf("%d ", head->val);
		head = head->next;
	}
	printf("\n");
}

int	main(void)
{
	// Create the first linked list: 2 -> 4 -> 3
	struct ListNode *l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
	l1->val = 2;
	l1->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	l1->next->val = 4;
	l1->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	l1->next->next->val = 3;
	l1->next->next->next = NULL;

	// Create the second linked list: 5 -> 6 -> 4
	struct ListNode *l2 = (struct ListNode *)malloc(sizeof(struct ListNode));
	l2->val = 5;
	l2->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	l2->next->val = 6;
	l2->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	l2->next->next->val = 4;
	l2->next->next->next