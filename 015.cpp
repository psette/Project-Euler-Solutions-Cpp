#include <iostream>
int main() { 
    unsigned long int graph[21][21];
    for (int i = 0; i < 21; ++i) {
        graph[i][0] = 1;
        graph[0][i] = 1;
    }
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j)
            graph[i + 1][j + 1] = graph[i][j + 1] + graph[i + 1][j];
    }
    std::cout<< graph[20][20] <<std::endl;
    return 0;
}