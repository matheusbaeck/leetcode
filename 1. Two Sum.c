/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1. Two Sum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math42 <math42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 01:45:21 by math42            #+#    #+#             */
/*   Updated: 2023/05/21 03:47:13 by math42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int ft_index(int n)
{
	if (n < 0)
		n = (n * (-1)) + 100000000;
	if (n == 0)
		return (200000001);
	return (n);
}

int	*twoSum(int *nums, int numsSize, int target, int *returnSize)
{
	int static	registry[200000002];
	int			*arr;
	int			i;
	int			c;

	arr = (int *)malloc(2 * sizeof(int));
	if (!arr)
		return (*returnSize = 0, NULL);
	i = 0;
	registry[ft_index(nums[0])] = -1;
	while (++i < numsSize)
	{
		c = ft_index(target - nums[i]);
		if (registry[c] != 0)
		{
			arr[0] = i;
			if (registry[c] == -1)
				arr[1] = 0;
			else
				arr[1] = registry[c];
			return (*returnSize = 2, arr);
		}
		else
			registry[ft_index(nums[i])] = i;
	}
	return (*returnSize = 0, NULL);
}

// FIRST THOUGHT
// int	*twoSum(int *nums, int numsSize, int target, int *returnSize)
// {
// 	int	*arr;
// 	int	j;
// 	int	i;

// 	arr = (int *)malloc(2 * sizeof(int));
// 	if (!arr)
// 		return (*returnSize = 0, NULL);
// 	j = -1;
// 	while (++j < numsSize - 1)
// 	{
// 		i = -1;
// 		while (++i < numsSize)
// 		{
// 			if ((nums[i] + nums[j]) == target && i != j)
// 			{
// 				arr[0] = i;
// 				arr[1] = j;
// 				return (*returnSize = 2, arr);
// 			}
// 		}
// 	}
// 	return (*returnSize = 0, NULL);
// }

int	main(void)
{
	int arr[4] = {2, 7, 11, 15};
	int *n;
	int returnSize;

	n = twoSum(arr, 4, 9, &returnSize);
	if (n != NULL)
	{
		printf("%d, %d\n", n[0], n[1]);
		free(n); // Don't forget to free the allocated memory
	}
	else
	{
		printf("No solution found.\n");
	}

	return (0);
}

/*
Input
nums =
[-10,7,19,15]
target =
9
Output
[1,1]
Expected
[0,2]
*/