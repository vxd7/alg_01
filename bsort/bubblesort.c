#include <stdio.h>
#include <malloc.h>

void bsort_int(int *arr, int n);
void out_arr_int(int *arr, int n);

int main(){
	int *arr;
	int n = 0;
	int i;

	printf("Enter the # of elements\n");
	scanf("%d", &n);

	arr = (int*)calloc(n, sizeof(int));


	for(i = n; i > 0; i--){
		arr[n - i] = i;
	}
	
	printf("Array before sort\n");
	out_arr_int(arr, n);
	bsort_int(arr, n);
	printf("\nArray after sort\n");
	out_arr_int(arr, n);
	printf("\n");
	return 0;
}

void bsort_int(int *arr, int n){
	int i,j;
	for(i = 0; i < n-1; i++){
		for(j = 0; j < n-i-1; j++){
			/* then swap */
			if(arr[j] > arr[j+1]){
				int tmp;
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}

		}
	}
	
}

void out_arr_int(int *arr, int n){
	int i;
	for(i = 0; i < n; i++){
		printf("%d ", *(arr + i));
	}
}
