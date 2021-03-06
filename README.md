# 17. Удалить ребра, которые смежны с заданной вершиной, и в модифицированном графе отсортировать вершины по возрастанию степени вершины
 Алгоритм:
 1. Удаление ребер, смежных с заданной вершиной
```c
for (int i = 0; i < n; ++i) { // Считаем количество ребер у введенной вершины
        sum += table[vertex-1][i];
    }
    if (sum > 1) { // Если ребер больше одного, то они смежны и их удаляем
        for (int i = 0; i < n; ++i) {
            table[vertex-1][i] = 0;
            table[i][vertex-1] = 0;
        }
    }
```    
 2. Создаем массив структур, где первое поле - номер вершины, а второе - ее степень, после чего в цикле считаем для каждой вершины соответствующие значения степени
```c
    Vertex* vertexes = (Vertex*)malloc(sizeof(Vertex) * n); // Массив структур, состоящих из номера вершины и ее степени
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
 ```   
  3. Пузырьковой сортировкой сортируем вершины по возрастанию степени вершины
 ```c
 for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (vertexes[j].degree > vertexes[j+1].degree) {
                Vertex temp = vertexes[j];
                vertexes[j] = vertexes[j + 1];
                vertexes[j + 1] = temp;
            }
        }
    }
 ```  
# Структурная схема алгоритма:
![](https://github.com/Anastasiia29-11/Flita_4dz/blob/main/lp6.png)

# Результаты работы:
![](https://github.com/Anastasiia29-11/Flita_4dz/blob/main/rez%20(2).png)

# Отображение изначального графа
![](https://github.com/Anastasiia29-11/Flita_4dz/blob/main/gr1%20(2).png)

# Отображение модифицированного графа
![](https://github.com/Anastasiia29-11/Flita_4dz/blob/main/gr2%20(2).png)
