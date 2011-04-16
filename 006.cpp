// diferencia entre el cuadrado de la suma y la suma de los cuadrados de
// los 100 primeros números naturales.

#include <iostream>

using namespace std;

int sum, sqsum = 0;

int main()
{
    for(int i = 1; i <= 100; i++)
    {
        sum += i;
        sqsum += i*i;
    }
    cout << sum*sum - sqsum << endl;
    return 0;
}