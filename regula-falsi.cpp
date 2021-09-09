#include <bits/stdc++.h>
using namespace std;

float f(float x)
{
    return (x)-3*sin(x)-1; //Enter ur preferences here
}
void regula (float *x, float x0,float x1, float fx0,float fx1, int *iter)
{
    *x=x0-((x1-x0)/(fx1-fx0))*fx0;
    ++(*iter);
cout<<" Iteration No."<<setw(3)<<*iter<<"\t X= "<<setw(7)<<setprecision(5)<<*x<<endl;

}
int main()
{
    int iter=0, maxiter;
    float x0,x1,x2,x3,aerr;
    cout<<"\nEnter the value of Core clock speed in Mhz: ";
    cin>>x0;
    cout<<"\nEnter the value of TDP in Watt: ";
    cin>>x1;
    aerr= 0.05;
    cout<<"\n maximum Time cycle: ";
    cin>>maxiter;
    cout<<endl;
    regula(&x2,x0,x1,f(x0),f(x1),&iter);
    do
    {
        if(f(x0)*f(x2)<0)
        x1=x2;
        else
        x0=x2;
        regula(&x3,x0,x1,f(x0),f(x1),&iter);
        if(fabs(x3-x2)<aerr)
        {
        cout<<"After "<<iter<<" Time cycle, Drop in FPS = "<<x3<<endl;
        return 0;
        }
        x2=x3;
    }
  while(iter<maxiter);

    cout<<"Solution does not converge, no distortion due to CPU"<<endl;
    cout<<"No distortion in this time cycle might be in next!"<<endl;
    return 1;

}
