#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>

using namespace std;

double y_der(double x, double y){
    return y / (x * x) + exp((x * x - 1) / x);
}

double func(double x) { return exp(-1 / x) * (exp(x) + 1); }

void Euler(double(deriv)(double, double), double h, double begin, double end, double y){
    cout << begin << " " << y << endl;
    double error = 0;
    for (auto x = begin + h; x < end + h; x+=h){
        y += h * deriv(x, y);
        cout << x << " " << y << endl;
        error = max(error, fabs(func(x) - y));
    }
    cout << "Max error is " << error << endl;
}

void RungeKutt(double(deriv)(double, double), double h, double begin, double end, double y){
    double K1, K2, K3, K4;
    double error = 0;
    for (auto x = begin; x < end + h; x+=h){
        cout << x << " " << y << endl;
        K1 = deriv(x, y), K2 = deriv(x + h/2, y + h/2 * K1), 
        K3 = deriv(x + h/2, y + h/2 * K2), K4 = deriv(x + h, y + h * K3);
        y = y + h/6 * (K1 + 2*K2 + 2*K3 + K4);
        error = max(error, fabs(func(x) - y));
    }
    cout << "Max error is " << error << endl;
}

void EulerKoshi(double(deriv)(double, double), double h, double begin, double end, double y){
    cout << begin << " " << y << endl;
    for (auto x = begin; x < end; x+=h){
        y = y + h * (deriv(x, y) + deriv(x + h, y + h * deriv(x, y))) / 2;
        cout << x + h << " " << y << endl;
    }
    cout << "Max error is " << error << endl;
}

void Adams(double(deriv)(double, double), double h, double begin, double end, double y){
    double K1, K2, K3, K4, error = 0;
    auto x = begin;
    vector<double> y_, q, q1, q2, q3;
    y_.push_back(y);
    for (; x < begin + 4*h; x+=h){
        cout << x << " " << *y_.rbegin() << endl;
        q.push_back(deriv(x, *y_.rbegin()) * h);
        K1 = deriv(x, *y_.rbegin()), K2 = deriv(x + h/2, *y_.rbegin() + h/2 * K1), 
        K3 = deriv(x + h/2, *y_.rbegin() + h/2 * K2), K4 = deriv(x + h, *y_.rbegin() + h * K3);
        y_.push_back(*y_.rbegin() + h/6 * (K1 + 2*K2 + 2*K3 + K4));
    }
    for (auto i = 1; i < 4; ++i) q1.push_back(q[i] - q[i - 1]);
    for (auto i = 1; i < 3; ++i) q2.push_back(q1[i] - q1[i - 1]);
    q3.push_back(q2[1] - q2[0]);
    for (; x < end + h; x += h)
    {
        y_.push_back(*y_.rbegin() + *q.rbegin() + *q1.rbegin() * 1.0 / 2 + *q2.rbegin() * 5.0 / 12 + *q3.rbegin() * 3.0 / 8);
        cout << x << " " << *y_.rbegin() << endl;
        error = max(error, fabs(func(x) - *y_.rbegin()));
        q.push_back(deriv(x, *y_.rbegin()) * h);
        q1.push_back(*(q.rbegin()) - *(q.rbegin() + 1));
        q2.push_back(*(q1.rbegin()) - *(q1.rbegin() + 1));
        q3.push_back(*(q2.rbegin()) - *(q2.rbegin() + 1));
    }
    cout << "Max error is " << error << endl;
    cout << "Q" << endl;
    for(auto el : q) cout << el << " ";
    cout << endl;
    cout << "Q1" << endl;
    for(auto el : q1) cout << el << " ";
    cout << endl;
    cout << "Q2" << endl;
    for(auto el : q3) cout << el << " ";
    cout << endl;
    cout << "Q3" << endl;
    for(auto el : q3) cout << el << " ";
    cout << endl;
}

int main(){
    double h = 0.1, begin = 1, end = 2, y = 1.367879;
    cout << "Euler:" << endl;
    Euler(y_der, h, begin, end, y);
    cout << "EulerKoshi:" << endl;
    EulerKoshi(y_der, h, begin, end, y);
    cout << "RungeKutt:" << endl;
    RungeKutt(y_der, h, begin, end, y);
    cout << "Adams:" << endl;
    Adams(y_der, h, begin, end, y);
}