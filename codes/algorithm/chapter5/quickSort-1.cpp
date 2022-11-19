#include <iostream>

#define MAX 10
void quick_sort(int* array, int start_index, int end_index){
	if(end_index <= start_index)
		return;
	int pivot = start_index;
	int i = pivot + 1;
	int j = end_index;
	int temp;
	// i, j 가 서로 엇갈리기 전까지 계속해서 반복해야한다.
	// 오름차순 기준 
	// 왼쪽에서 오른쪽으로 가면서 피봇 값보다 큰값
	// 오른쪽에서 왼쪽으로 가면서 피봇 값보다 작은값
	// 만약 i, j 가 서로 엇갈리지 않았으면 i, j 값을 교환
	while(i <= j){
		while(array[pivot] >= array[i] && i <= end_index){
			i++;
		}
		while(array[pivot] <= array[j] && j > start_index){
			j--;
		}
		// i, j가 서로 엇갈린 경우
		if(j < i){
			temp = array[pivot];
			array[pivot] = array[j];
			array[j] = temp;
		} else{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}
	// pivot 값 기준으로 왼쪽 배열, 오른쪽 배열 나누어서 다시 정복
	quick_sort(array, start_index, j-1);
	quick_sort(array, j+1, end_index);
}
void print(int* numbers){
	for(int i = 0; i < MAX; i++){		
		printf("%d ", numbers[i]);
	}
	printf("\n");
}
int main(){
	int numbers[MAX] = {3,1,4,2,6,5,9,7,8,0};
	quick_sort(numbers, 0, MAX-1);
	print(numbers);
}
