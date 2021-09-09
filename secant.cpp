#include <bits/stdc++.h>
using namespace std;
#define error 0.0001
float F(float x)
{
    float que;
    que = ((x)-9 * (sin(x * M_PI / 180)) - 5); //Enter ur preferences here
    return que;
}
int main()
{
    float x0, x1, x2, x2old, f0, f1, f2;
    int iter = 1;
    float Eapp;
    cout << "Enter the initial value of core clock speed in Mhz (x8) and value of TDPin Watt(x1) below: \n";
    cin >> x0 >> x1;
    cout << "iter No.\tx0\t\tx1\t\tf0\t\tf1\t\tx2\t\tf2\t\tEa\n";
    cout << "-----------------------------------------------------------------------------------------------------------------------\n ";
       
        while (1)
    {
        f0 = F(x0);
        f1 = F(x1);
        x2 = x1 - (f1 * (x1 - x0) / (f1 - f0));
        f2 = F(x2);
        Eapp = fabs((x2 - x1) / x2);
        cout << fixed << setprecision(2);
        cout << iter << "\t\t" << x0 << "\t\t" << x1 << "\t\t" << f0 << "\t\t" << f1 << "\t\t" << x2 << "\t\t" << f2 << "\t\t" << Eapp << "\n";
        x0 = x1;
        x1 = x2;
        iter++;
        if (Eapp <= 0.05)
            break;
    }
    cout << "Approximate minimum Frame drop is equal to is: " << x2;
}
