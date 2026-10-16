#include "sort.h"

/**
 * swap - swap two members of array
 * @dest : member a
 * @src : member b
 * return : nothing
 */
void swap(int *dest, int *src)
{
	int tmp;

	tmp = *dest;
	*dest = *src;
	*src = tmp;
}

/**
 * sift_down - restore max heap property
 * @array : input array
 * @start : start index
 * @end : end index
 * @size : size of array
 */
void sift_down(int *array, int start, int end, size_t size)
{
	int root = start;

	while (root * 2 + 1 < end)
	{
		int child = root * 2 + 1;
		int swap_i = root;

		if (array[swap_i] < array[child])
			swap_i = child;
		if (child + 1 < end && array[swap_i] < array[child + 1])
			swap_i = child + 1;
		if (swap_i == root)
			return;

		swap(&array[root], &array[swap_i]);
		print_array(array, size);
		root = swap_i;
	}
}

/**
 * heap_sort - sorts an array using heap sort
 * @array : input to sort
 * @size : size of array
 * return : nothing
 */
void heap_sort(int *array, size_t size)
{
	int start = (int)(size / 2);
	int end = (int)size;

	while (end > 1)
	{
		if (start > 0)
		{
			start--;
			sift_down(array, start, end, size);
		}
		else
		{
			end--;
			swap(&array[end], &array[0]);
			print_array(array, size);
			sift_down(array, 0, end, size);
		}
	}
}
