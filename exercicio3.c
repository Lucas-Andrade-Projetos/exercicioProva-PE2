#include <stdio.h>
#include <stdlib.h>

//funções de operações
void insertMatrix(char** matrix, int rows, int cols);
void printMatrix(char** matrix, int rows, int cols);
char** createMatrixChar(int rows, int cols);
int** createMatrixInt(int rows, int cols);
void freeMatrixChar(char** matrix, int rows);
void freeMatrixInt(int** matrix, int rows);

//funções de ação
int calculateArea(char** matrix, int x, int y, int rows, int cols, int** visited);

int main(){
	int row = 0, col = 0;
	scanf("%d %d", &row, &col);
	getchar();  
	
    char** matrix = createMatrixChar(row, col);
	int** visited = createMatrixInt(row, col);
	
	//usei para colocar a visited como 0 em todos 
	for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            visited[i][j] = 0;
		}
    }

    insertMatrix(matrix, row, col);
    printMatrix(matrix, row, col);

	int x = 0, y = 0;
	scanf("%d %d", &x, &y);
	getchar();

    int area = calculateArea(matrix, x, y, row, col, visited);
    printf("Área: %d\n", area);

	freeMatrixChar(matrix, row);
	freeMatrixInt(visited, row);

	return 0;
}

//função para adicionar valores em uma matriz de chars
void insertMatrix(char** matrix, int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            scanf(" %c", &matrix[i][j]);
        }
    }
    printf("\n");
}

//função para imprimir valores de uma matriz de chars
void printMatrix(char** matrix, int rows, int cols){
    printf("Essa é a sua matriz: \n");
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//função para criar a matriz com alocação de memória para chars
char** createMatrixChar(int rows, int cols) {
    char** matrix = (char**)malloc(rows * sizeof(char*));
    if (matrix == NULL) {
        return NULL;
    }

    for (int i = 0; i < rows; i++) {
        matrix[i] = (char*)malloc(cols * sizeof(char)); 
        if (matrix[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return NULL;
        }
    }

    return matrix;
}

//função para criar a matriz com alocação de memória para ints
int** createMatrixInt(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    if (matrix == NULL) {
        return NULL;
    }

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int)); 
        if (matrix[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return NULL;
        }
    }

    return matrix;
}

//liberar memória da matriz
void freeMatrixChar(char** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]); 
    }
    free(matrix); 
}

void freeMatrixInt(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]); 
    }
    free(matrix); 
}

//calculamos a área recusirvamente
//base = . pois será mar ou matriz visitada = 1, pois já foi visitada antes e x e y fora da fronteira
//caso não cair no caso base, marca o xy visitado como 1 para saber que já passou ali
//então chamamos a função para todas os pontos ao redor da chamada e vamos somando na variavel area até toda a vizinhança serem feitas e então retorna area 
int calculateArea(char** matrix, int x, int y, int rows, int cols, int** visited) {

    if (x < 0 || x >= rows || y < 0 || y >= cols || matrix[x][y] == '.' || visited[x][y] == 1)
        return 0;
        
    visited[x][y] = 1;

    int area = 1;

    
    area += calculateArea(matrix, x - 1, y, rows, cols, visited);  //cima
    area += calculateArea(matrix, x + 1, y, rows, cols, visited);  //caixo
    area += calculateArea(matrix, x, y - 1, rows, cols, visited);  //esquerda
    area += calculateArea(matrix, x, y + 1, rows, cols, visited);  //direita

    area += calculateArea(matrix, x - 1, y - 1, rows, cols, visited);  //diagonal superior esquerda
    area += calculateArea(matrix, x - 1, y + 1, rows, cols, visited);  //diagonal superior direita
    area += calculateArea(matrix, x + 1, y - 1, rows, cols, visited);  //diagonal inferior esquerda
    area += calculateArea(matrix, x + 1, y + 1, rows, cols, visited);  //diagonal inferior direita

    return area;
}
