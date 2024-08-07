/*

1. MERGE SORT

3. Time Complexity:
	5. O(NlogN) where N is the number of elements in the array.

3. Space Complexity:
	5. O(N) where N is the number of elements in the array.

3 Time complexity using master theorem:
	5. T(n) = 2T(n/2) + O(n) = O(nlogn)

3. DESCRIPTION:
	5. Merge sort is a divide and conquer algorithm that divides the array into two halves, recursively sorts the two halves, and then merges the two sorted halves.

3. APPROACH:
	5. Divide the array into two halves.
	5. Recursively sort the two halves.
	5. Merge the two sorted halves.



*/

#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &v, int l, int mid, int r)
{

	int left_size = mid - l + 1;
	int right_size = r - mid;

	int *left = new int[left_size];
	int *right = new int[right_size];

	for (int i = 0; i < left_size; i++)
	{
		left[i] = v[l + i];
	}

	for (int i = 0; i < right_size; i++)
	{
		right[i] = v[mid + i + 1];
	}

	int i = 0, j = 0, k = l;

	while (i < left_size && j < right_size)
	{
		if (left[i] < right[j])
		{
			v[k++] = left[i++];
		}
		else
		{
			v[k++] = right[j++];
		}
	}

	while (i < left_size)
	{
		v[k++] = left[i++];
	}

	while (j < right_size)
	{
		v[k++] = right[j++];
	}

	delete[] left;
	delete[] right;
}

void mergeSort(vector<int> &v, int l, int r)
{

	if (l >= r)
	{
		return;
	}

	int mid = l + (r - l) / 2;

	mergeSort(v, l, mid);
	mergeSort(v, mid + 1, r);
	merge(v, l, mid, r);
}

int main()
{
	vector<int> v = {12, 11, 13, 5, 6, 7};
	int n = v.size();

	mergeSort(v, 0, n - 1);

	std::cout << "Sorted array: ";
	for (int i = 0; i < n; i++)
	{
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}