#include<iostream>
#include<string.h>

#define MAX 100

int main() {
    int n;
    double x[MAX], y[MAX], c, w = 1, s = 0, d;

    std::cout << "Nhap so luong diem: ";
    std::cin >> n;

    std::cout << "Nhap c�c gi� tri x[i] v� y[i]:\n";
    for(int i = 0; i < n; i++) {
        std::cout << "x[" << i << "] = ";
        std::cin >> x[i];
        std::cout << "y[" << i << "] = ";
        std::cin >> y[i];
    }

    std::cout << "Nhap gi� tri c: ";
    std::cin >> c;

    for(int i = 0; i < n; i++) {
        w *= (c - x[i]);
        d = c - x[i];
        for(int j = 0; j < n; j++) {
            if(j != i) {
                d *= (x[i] - x[j]);
            }
        }
        s += y[i] / d;
    }

    std::cout << "Ket qua: " << w * s << std::endl;

    return 0;
}

