/* Ввести последовательность натуральных чисел {Aj}j=1...n (n<=1000). 
Упорядочить последовательность по неубыванию первой цифры числа, 
числа с одинаковыми первыми цифрами дополнительно упорядочить по 
неубыванию наибольшей цифры числа, числа с одинаковыми первыми 
цифрами и одинаковыми наибольшими цифрами дополнительно упорядочить 
по неубыванию самого числа.

Сеин Максим
*/
#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;
using std::endl;

int main() {

    int n, b, a, c, d, maxd, maxa;
    ifstream in("input.txt");
    ofstream out("output.txt");

    in >> n;
    int* mas = new int[n];

    for(int i = 0; i < n; i++){
        in >> mas[i];
    }

    for (int i = 0; i < n-1; i++) {
        c = mas[i];
        while (c > 0) {
            d = c % 10;
            c = c / 10;
            if(d > maxd) maxd=d;
        }
        b = mas[i];
        while (b > 0) {
            a = b % 10;
            b = b / 10;
            if(a > maxa)
                maxa=a;
        }

        if (d<=a && d!=a) {
            std::swap(mas[i], mas[i+1]);
        }
        else if (d==a && maxa >= maxd) {
            std::swap(mas[i], mas[i+1]);
        }
        else if (d==a && maxd==maxa && mas[i] <= mas[i+1]) {
            std::swap(mas[i], mas[i+1]);
        }
    }
    maxa=0;
    maxd=0;
    for (int i = 0; i < n; i++) {
        out << mas[i] << " ";
    }

}
