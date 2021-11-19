#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>

using namespace std;

double y_der(double x, double y){
    double ans = y / (x * x) + exp((x * x - 1) / x);
    return ans;
}

double func(double x) {
    auto ans = exp(-1 / x) * (exp(x) + 1);
    return ans; 
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
    cout << "Error is " << fabs(func(end) - y) << endl;
}

void RungeKutt(double(deriv)(double, double), double h, double begin, double end, double y){
    double K1, K2, K3, K4;
<<<<<<< HEAD
    for (auto x = begin; x < end + h; x+=h){
        cout << x << " ** " << y << " ** " << func(x) << endl;
=======
    for (auto x = begin; x < end; x+=h){
        cout << x << " " << y << endl;
>>>>>>> 906f0623794eb2e73b686775dbad3f4624a3c553
        K1 = deriv(x, y), K2 = deriv(x + h/2, y + h/2 * K1), 
        K3 = deriv(x + h/2, y + h/2 * K2), K4 = deriv(x + h, y + h * K3);
        y = y + h/6 * (K1 + 2*K2 + 2*K3 + K4);
    }
    cout << "Error is " << fabs(func(end) - y) << endl;
}

void EulerKoshi(double(deriv)(double, double), double h, double begin, double end, double y){
        cout << begin << " ** " << y << " ** " << func(begin) << endl;
    for (auto x = begin; x < end; x+=h){
        y = y + h * (deriv(x, y) + deriv(x + h, y + h * deriv(x, y))) / 2;
        cout << x+h << " ** " << y << " ** " << func(x+h) << endl;
    }
<<<<<<< HEAD
    cout << "Error is " << fabs(func(end) - y )<< endl;
=======
    auto check = func(end);
    cout << "Error is " << fabs(func(end) - y) << endl;
}

void Adams(double(deriv)(double, double), double h, double begin, double end, double y){
    double K1, K2, K3, K4, error = 0;
    vector<double> y_, q, q1, q2, q3;
    y_.push_back(y);
    cout << begin << " " << *y_.rbegin() << endl;
    q.push_back(deriv(begin, *y_.rbegin()) * h);
    for (auto x = begin; x < begin + 3*h; x+=h){
        K1 = deriv(x, *y_.rbegin()), K2 = deriv(x + h/2, *y_.rbegin() + h/2 * K1), 
        K3 = deriv(x + h/2, *y_.rbegin() + h/2 * K2), K4 = deriv(x + h, *y_.rbegin() + h * K3);
        y_.push_back(*y_.rbegin() + h/6 * (K1 + 2*K2 + 2*K3 + K4));
        cout << x + h << " " << *y_.rbegin() << endl;
        q.push_back(deriv(x + h, *y_.rbegin()) * h);
    }
    for (auto i = 1; i < 4; ++i) q1.push_back(q[i] - q[i - 1]);
    for (auto i = 1; i < 3; ++i) q2.push_back(q1[i] - q1[i - 1]);
    q3.push_back(q2[1] - q2[0]);
    for (auto x = begin + 4*h; x < end + h; x += h)
    {
        double dy = *q.rbegin() + *q1.rbegin() * 1.0 / 2 + *q2.rbegin() * 5.0 / 12 + *q3.rbegin() * 3.0 / 8;        y_.push_back(*y_.rbegin() + dy);
        cout << x << " " << *y_.rbegin() << endl;
        q.push_back(deriv(x, *y_.rbegin()) * h);
        q1.push_back(*(q.rbegin()) - *(q.rbegin() + 1));
        q2.push_back(*(q1.rbegin()) - *(q1.rbegin() + 1));
        q3.push_back(*(q2.rbegin()) - *(q2.rbegin() + 1));
    }
    cout << "Error is " << fabs(func(end) - *y_.rbegin()) << endl;
>>>>>>> 906f0623794eb2e73b686775dbad3f4624a3c553
}

void Adams(double(deriv)(double, double), double h, double begin, double end, double y){
    double K1, K2, K3, K4, error = 0;
    vector<double> y_, q, q1, q2, q3;
    y_.push_back(y);
    cout << begin << " " << *y_.rbegin() << endl;
    q.push_back(deriv(begin, *y_.rbegin()) * h);
    for (auto x = begin; x < begin + 3*h; x+=h){
        K1 = deriv(x, *y_.rbegin()), K2 = deriv(x + h/2, *y_.rbegin() + h/2 * K1), 
        K3 = deriv(x + h/2, *y_.rbegin() + h/2 * K2), K4 = deriv(x + h, *y_.rbegin() + h * K3);
        y_.push_back(*y_.rbegin() + h/6 * (K1 + 2*K2 + 2*K3 + K4));
        cout << x + h << " " << *y_.rbegin() << endl;
        q.push_back(deriv(x + h, *y_.rbegin()) * h);
    }
    for (auto i = 1; i < 4; ++i) q1.push_back(q[i] - q[i - 1]);
    for (auto i = 1; i < 3; ++i) q2.push_back(q1[i] - q1[i - 1]);
    q3.push_back(q2[1] - q2[0]);
    for (auto x = begin + 4*h; x < end + h; x += h)
    {
        double dy = *q.rbegin() + *q1.rbegin() * 1.0 / 2 + *q2.rbegin() * 5.0 / 12 + *q3.rbegin() * 3.0 / 8;        y_.push_back(*y_.rbegin() + dy);
        cout << x << " ** " << *y_.rbegin() << " ** " << func(x) << endl;
        q.push_back(deriv(x, *y_.rbegin()) * h);
        q1.push_back(*(q.rbegin()) - *(q.rbegin() + 1));
        q2.push_back(*(q1.rbegin()) - *(q1.rbegin() + 1));
        q3.push_back(*(q2.rbegin()) - *(q2.rbegin() + 1));
    }
    cout << "Error is " << fabs(func(end) - *y_.rbegin()) << endl;
}


int main(){
    double h = 0.1, begin = 1, end = 2, y = 1.367879;
    cout << "x ** Euler ** function" << endl;
    Euler(y_der, h, begin, end, y);
<<<<<<< HEAD
    cout << "x ** RungeKutt ** function" << endl;
    RungeKutt(y_der, h, begin, end, y);
    cout << "x ** EulerKoshi ** function" << endl;
    EulerKoshi(y_der, h, begin, end, y);
    cout << "x ** Adams ** function" << endl;
    Adams(y_der, h, begin, end, y);

=======
    cout << "EulerKoshi:" << endl;
    EulerKoshi(y_der, h, begin, end, y);
    cout << "RungeKutt:" << endl;
    RungeKutt(y_der, h, begin, end, y);
    cout << "Adams:" << endl;
    Adams(y_der, h, begin, end, y);
>>>>>>> 906f0623794eb2e73b686775dbad3f4624a3c553
}