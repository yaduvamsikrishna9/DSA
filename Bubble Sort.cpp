#include <stdio.h>
void swap(int *xp, int *yp){
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void bubble_Sort(int array[], int n){
int i, j;
for (i=0;i<n-1;i++)	
	for (j=0;j<n-i-1;j++)
		if(array[j]>array[j+1])
			swap(&array[j],&array[j+1]);
}
void print_Array(int array[],int size){
	int i;
	for (i=0;i<size;i++)
		printf("%d ",array[i]);
	printf("\n");
}
int main(){
	int array[] ={25,10,5,30,15,3,21};
	int n = sizeof(array)/sizeof(array[0]);
	bubble_Sort(array, n);
	printf("Bubble Sort : ");
	print_Array(array, n);
	return 0;
}

