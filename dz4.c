#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>
#pragma warning(disable : 4996)

typedef struct vertex { 
    int number; 
    int degree; 
} Vertex;

int main(void) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    FILE* file = fopen("table.dot", "w");
    FILE* file1 = fopen("table1.dot", "w");

    if (file == NULL || file1 == NULL) {
        printf("Файлы для записи не смогли открыться");
        return 0;
    }

    int n, m; // Количество вершин и ребер
    int nn, mm; // Номер входной вершины и выходной
    printf("Введите число вершин графа > ");
    scanf("%d", &n);
    fprintf(file, "graph G {");
    fprintf(file, "\n");
    fprintf(file1, "graph G {");
    fprintf(file1, "\n");
    int** table = (int**)malloc(sizeof(int*)*n); 
    if (table == NULL) {
        printf("Память не смогла выделиться");
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        table[i] = (int*)malloc(sizeof(int)*n);
        if (table[i] == NULL) {
            printf("Память не смогла выделиться");
            return 0;
        }
        for (int j = 0; j < n; ++j) {
            table[i][j] = 0; 
        }
    }
    for (int i = 1; i < (n + 1); i++) { 
        fprintf(file, "%d;", i);
        fprintf(file, "\n");
        fprintf(file1, "%d;", i);
        fprintf(file1, "\n");
    }
    printf("Введите количество ребер > ");
    scanf("%d", &m);
    printf("Введите ребра в формате (Вершина 1 - Вершина 2) > ");
    for (int i = 0; i < m; ++i) { 
        scanf("%d - %d", &nn, &mm);
        if (nn != mm) { // Если не петля
            table[nn - 1][mm - 1]++;
            table[mm - 1][nn - 1]++;
        }
        else { 
            table[nn - 1][mm - 1]++;
        }
        fprintf(file, "%d -- %d;", nn, mm);
        fprintf(file, "\n");
    }
    fprintf(file, "}\n");
    fclose(file);
    for (int i = 0; i < n; ++i) { 
        for (int j = 0; j < n; ++j) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
    int vertex; int sum = 0; 
    printf("Введите номер вершины, у которой хотите удалить смежные ребра > ");
    scanf("%d", &vertex);
    for (int i = 0; i < n; ++i) { 
        sum += table[vertex-1][i];
    }
    if (sum > 1) { 
        for (int i = 0; i < n; ++i) {
            table[vertex-1][i] = 0;
            table[i][vertex-1] = 0;
        }
    }
    for (int i = 0; i < n; ++i) { 
        for (int j = i; j < n; ++j) {
            for (int k = 0; k < table[i][j]; k++) {
                fprintf(file1, "%d -- %d;", i+1, j+1);
                fprintf(file1, "\n");
            }
        }
    }
    fprintf(file1, "}\n");
    fclose(file1);
    for (int i = 0; i < n; ++i) { 
        for (int j = 0; j < n; ++j) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
    Vertex* vertexes = (Vertex*)malloc(sizeof(Vertex) * n); 
    if (vertexes == NULL) {
        printf("Память не смогла выделиться");
        return 0;
    }
    for (int i = 0; i < n; ++i) { 
        sum = 0;
        for (int j = 0; j < n; ++j) { 
            sum += table[i][j];
        }
        vertexes[i].number = i+1;
        vertexes[i].degree = sum;
    }

    for (int i = 0; i < n; ++i) { 
        printf("Degree of %d vertex = %d\n", vertexes[i].number, vertexes[i].degree);
    }

    printf("\n");
    // Пузырьковая сортировка
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (vertexes[j].degree > vertexes[j+1].degree) {
                Vertex temp = vertexes[j];
                vertexes[j] = vertexes[j + 1];
                vertexes[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; ++i) { 
        printf("Degree of %d vertex = %d\n", vertexes[i].number, vertexes[i].degree);
    }
    

    for (int i = 0; i < n; ++i) { 
        free(table[i]);
    }
    free(table); 
    free(vertexes); 
    return 0;
}
