/*
Дана целочисленная матрица {Aij}i=1..n,j=1..m (n,m<=100). 
Найти столбец содержащий наименьший элемент матрицы и 
заменить все отрицательные элементы этого столбца числом 0.

 Сеин Максим
*/

#include <iostream>
#include <fstream>

using std::cout;
using std::ifstream;
using std::ofstream;
using std::cin;
using std::endl;

#define N 100
#define M 100

int main() {
    int n,m,min,str,stolb;

    ifstream in ("/Users/maksimsein/Documents/gitKtaken/lab-8/3/input.txt");
    ofstream out ("/Users/maksimsein/Documents/gitKtaken/lab-8/3/output.txt");

    in >> n >> m;

    int** matrix = new int* [n];
    for (int i = 0; i < n; i++)
        matrix[i] = new int[m];


    for(int i=0; i < n; i++){
        for(int j=0; j<m; j++){
            in >> matrix[i][j];
        }
    }
    min = matrix[0][0];
    for(int i=0; i < n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j] < min){
                stolb = j;
            }
        }
    }
    for(int i = 0; i<n; i++){
        if(matrix[i][stolb] < 0){
            matrix[i][stolb] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            out << matrix[i][j] << " ";
        }
        out << endl;
    }

    for (int i = 0; i < n; i++)
        delete[] matrix[i];
    delete[] matrix;

}