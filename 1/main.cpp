/*
Дана последовательность натуральных чисел {aj}j=1...n (n<=10000). 
Если в последовательности есть хотя бы одно число, сумма цифр 
которого равна 14, упорядочить последовательность по неубыванию.

Сеин Максим

*/
#include <iostream>
#include <fstream>
using std::cout;
using std::ifstream;
using std::ofstream;
using std::cin;
using std::endl;

int main() {


    int n, sum, a, b;
    bool check;
    ifstream in("input.txt");
    ofstream out("output.txt");

    in >> n;
    int* mas = new int[n];

    sum=0;
    for (int i=0; i<n; i++) {
            in >> mas[i];
    }
    for (int i=0; i<n; i++){
            b = mas[i];
            while (b > 0){
                a = b%10;
                sum+=a;
                b=b/10;
            }
            if(sum==14) {
                check = true;
                break;
            }
            sum=0;
            if(check) break;
    }
    if(check){
        for (int i = 0; i < n-1; i++)
            if (mas[i] >= mas[i+1])
                std::swap (mas[i],mas[i+1]);
        for (int i = 0; i < n; i++) {
            out << mas[i] << " ";
        }
            out << endl;
        }
        else {
            out << "Необходимое условие не выявлено";
        }
        delete[] mas;

    return 0;
}