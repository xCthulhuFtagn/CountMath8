<<<<<<< HEAD
#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>

using namespace std;

double y_der(double x, double y){
    return y / (x * x) + exp((x * x - 1) / x);
}

double func(double x){
    return exp(-1.0/x)*(exp(x)+1); 
}

void Euler(double(deriv)(double, double), double h, double begin, double end, double y){
    cout << begin << " " << y << endl;
    for (auto x = begin + h; x < end + h; x+=h){
        y += h * deriv(x, y);
        cout << x << " ** " << y << " ** " << func(x) << endl;
    }
}

void RungeKutt(double(deriv)(double, double), double h, double begin, double end, double y){
    double K1, K2, K3, K4;
    for (auto x = begin; x < end + h; x+=h){
        cout << x << " ** " << y << " ** " << func(x) << endl;
        K1 = deriv(x, y), K2 = deriv(x + h/2, y + h/2 * K1), 
        K3 = deriv(x + h/2, y + h/2 * K2), K4 = deriv(x + h, y + h * K3);
        y = y + h/6 * (K1 + 2*K2 + 2*K3 + K4);
    }
}

void EulerKoshi(double(deriv)(double, double), double h, double begin, double end, double y){
        cout << begin << " ** " << y << " ** " << func(begin) << endl;
    for (auto x = begin; x < end; x+=h){
        y = y + h * (deriv(x, y) + deriv(x + h, y + h * deriv(x, y))) / 2;
        cout << x+h << " ** " << y << " ** " << func(x+h) << endl;
    }
}

int main(){
    double h = 0.1, begin = 1, end = 2, y = 1.367879;
    cout << "x ** Euler ** function" << endl;
    Euler(y_der, h, begin, end, y);
    cout << "x ** RungeKutt ** function" << endl;
    RungeKutt(y_der, h, begin, end, y);
    cout << "x ** EulerKoshi ** function" << endl;
    EulerKoshi(y_der, h, begin, end, y);
}
=======
q.push_back(deriv(x, *y_.rbegin()) * h);
        
>>>>>>> 906f0623794eb2e73b686775dbad3f4624a3c553
