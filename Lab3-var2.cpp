#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    double Eps, x, res, r, q, t;
    int i, pos;

    cout<<"Proiect nr3, elaborat de Smoleac Mihai" << endl;
    cout << "Tema: descompunerea in serie Taylor \n" ;

    cout << "Input argument x in degree: ";
    cin >> x;
    
    cout << "Input pressicion: ";
    cin >> Eps;
    cout << endl;
    //to radians
    r = x * M_PI /180;
    i = 0;
    res = t = 1;

    //cout << "Eps = " << Eps << " t = " << t << endl;
    while (abs(t) > Eps) 
    {
        i++;
        q = -r*r/(2*i* (2*i - 1) );
        t *= q;
        res = res + t;
        cout << "res" << i << " = " << t << endl; 
    }

    printf ("Value of sum: (x = %5.2lf, n = %d)= %16.12lf", x, i, res);
    printf("\nVerify cos(%5.2lf) = %16.12lf", x, cos(r));

    return 0;
}