#include <bits/stdc++.h>
using namespace std;
int main()
{
     float x[100], y[100], xpoint, ypoint=0, p;
     int i,j,n;

     cout<<"Enter number of data: ";
     cin>>n;
     cout<<"Enter data respectively : x[i] & y[i]"<< endl;
     for(i=1;i<=n;i++)
     {
        cout<<"x["<< i<<"] = ";
        cin>>x[i];
        cout<<"y["<< i<<"] = ";
        cin>>y[i];
     }
     cout<<"Enter interpolation point: ";
     cin>>xpoint;

     for(i=1;i<=n;i++)
     {
          p=1;
          for(j=1;j<=n;j++)
          {
               if(i!=j)
               {
                    p = p* (xpoint - x[j])/(x[i] - x[j]);
               }
          }
          ypoint = ypoint + p * y[i];
     }
     cout<<"\n"<<"Interpolated value at "<< xpoint<< " is "<< ypoint;

     return 0;
}
