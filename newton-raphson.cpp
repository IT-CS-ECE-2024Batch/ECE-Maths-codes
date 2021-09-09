#include <bits/stdc++.h>
using namespace std;

float first(float x)
{
    return (x) - 3*(sin(x)) -1; //enter ur prefernces here
}

float diff(float x)
{
    return 1 -3*(cos(x));
}

int main()
{
    int itr, maxiter;
    float h, x0, x1, aerr;
    cout << "Enter the value of core clock speed in MHz: \n";
    cin >> x0;
    cout << "Enter allowed minimum drop in FPS: \n";
    cin >> aerr;
    cout << "maximum time cycle in seconds: \n";
    cin >> maxiter;
    for (itr = 1; itr <= maxiter; itr++)
    {
        h = first(x0) / diff(x0);
        x1 = x0 - h;
        if (fabs(h) < aerr)
        {
            cout << "after " << itr << " root = " << x1 << endl;
            return 0;
        }
        x0 = x1;
    }
    cout << "Time iteration not sufficient, No drop founded ,might be in next cycle!" << endl;
    return 1;
}
