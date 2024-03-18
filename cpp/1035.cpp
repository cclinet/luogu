#include <iostream>
int main()
{
    double Sn = 0;
    long long n = 0;
    int k;
    std::cin >> k;
    while (Sn <= k)
    {
        Sn += 1.0 / ++n;
    }
    std::cout << n << std::endl;
    return 0;
}