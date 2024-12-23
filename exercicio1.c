#include <stdio.h>
#include <stdlib.h>

void read_(int* array, int n);
int menor(int* array, int n);

int main(){

	int n = 0;
	scanf("%d", &n);

	int* vetor = calloc(n, sizeof(int));
	if(vetor == NULL) return 1;

	read_(vetor, n);
	int resultado = menor(vetor, n);

	printf("%d\n", resultado);

	free(vetor);
	return 0;
}

void read_(int* array, int n){

	for(int i = 0; i < n; i++){
		scanf("%d", &array[i]);
	}
}

int menor(int* array, int n){

	if(n == 1) return array[0];

	int A_men = menor(array + 1, n-1);

	if(array[0] < A_men){
		return array[0];
	}else{
		return A_men;
	}
}
