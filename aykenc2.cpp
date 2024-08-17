#include<iostream>

#define MAX 100

double ayken(double x[], double y[], int n, double point) {
    double p[MAX][MAX] = {0};

    for (int i = 0; i < n; i++)
        p[i][0] = y[i];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            p[j][i] = ((point - x[j]) * p[j + 1][i - 1] - 
                       (point - x[i + j]) * p[j][i - 1]) / (x[j + i] - x[j]);
        }
    }

    return p[0][n - 1];
}

int main() {
    double x[MAX];
    double y[MAX];
    double point ;
    int n ;
    
    std::cout << "hay nhap n: " ;
    std::cin >> n;
    
    for (int i = 0; i < n; i++)
    {
    	std::cout <<"nhap x["<< i << "] : " ; std::cin >> x[i];
    	std::cout <<"nhap gia tri cua diem, y["<< i << "] : " ; std::cin >> y[i];
	}
	
	std::cout << "nhap gia tri can tim : " ; std::cin >> point; 
	
    std::cout << "Giá tri tai diêm " << point << " là: " << ayken(x, y, n, point) << std::endl;

    return 0;
}

