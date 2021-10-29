#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>

using namespace std;

double y_der(double x, double y){
    return y / (x * x) + exp((x * x - 1) / x);
}

void Euler(double(deriv)(double, double), double h, double begin, double end, double y){
    cout << begin << " " << y << endl;
    for (auto x = begin + h; x < end + h; x+=h){
        y += h * deriv(x, y);
        cout << x << " " << y << endl;
    }
}

void RungeKutt(double(deriv)(double, double), double h, double begin, double end, double y){
    double K1, K2, K3, K4;
    for (auto x = begin; x < end + h; x+=h){
        cout << x << " " << y << endl;
        K1 = deriv(x, y), K2 = deriv(x + h/2, y + h/2 * K1), 
        K3 = deriv(x + h/2, y + h/2 * K2), K4 = deriv(x + h, y + h * K3);
        y = y + h/6 * (K1 + 2*K2 + 2*K3 + K4);
    }
}

void EulerKoshi(double(deriv)(double, double), double h, double begin, double end, double y){
    cout << begin << " " << y << endl;
    for (auto x = begin; x < end; x+=h){
        y = y + h * (deriv(x, y) + deriv(x + h, y + h * deriv(x, y))) / 2;
        cout << x + h << " " << y << endl;
    }
}

int main(){
    double h = 0.1, begin = 1, end = 2, y = 1.367879;
    cout << "Euler:" << endl;
    Euler(y_der, h, begin, end, y);
    cout << "RungeKutt:" << endl;
    RungeKutt(y_der, h, begin, end, y);
    cout << "EulerKoshi:" << endl;
    EulerKoshi(y_der, h, begin, end, y);
}