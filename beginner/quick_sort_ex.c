#include <stdio.h>

void quick_sort(int[], int, int);
void swap(int[], int, int);

int main(){
	int numbers[] = {1, 5, 2, 3};
	quick_sort(numbers, 0, 3);
	int i;
	for (i = 0; i < 4; i++){
		printf("%d", numbers[i]);
	}
	printf("\n");
}

// quick_sort: sort v[left]...v[right] into increasing order
void quick_sort(int v[], int left, int right){
	int i, last;
	
	if (left >= right) // do nothing if array contains fewer than 2 elements
		return;
	
	swap(v, left, (left + right)/2); // move partition element to v[0]

	last = left;
	for (i = left+1; i <= right; i++) // partition
		if (v[i] < v[left])
			swap(v, ++last, i);
	swap(v, left, last); // restore partition element
	quick_sort(v, left, last - 1);
	quick_sort(v, last + 1, right);
}

// interchange v[i] and v[j]
void swap(int v[], int i, int j){
	int temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
