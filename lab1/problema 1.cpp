#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("in.txt");

int prod(const char* s)
{
    int res = 0;
    int i = 0;

    while (s[i] != '\0')
    {
        res = res * 10 + (s[i] - '0');
        i++;
    }

    return res;
}
int main()
{
    int sum = 0, y;
    char x[100];
    while (fin >> x)
    {
        y = prod(x);
        sum = sum + y;
    }
    printf("%d", sum);
    return 0;
}