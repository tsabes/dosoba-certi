#include <iostream>

using namespace std;

#define MINIMUM(x, y) ((x>y)?(y):x)

int change(int n)
{
    int coin;
    
    if(n == 0)
    {
        coin = 0;
        return coin;
    }
    else if (n > 0 && n < 5)
    {
        coin = change(n-1) + 1;
        return coin;
    }
    else if ( 5 <= n && n < 10)
    {
        coin = MINIMUM((change(n-1)+1),(change(n-5)+1));
        return coin;
    }
    else if ( 10 <= n && n < 16)
    {
        coin = MINIMUM((change(n-1)+1),(change(n-5)+1));
        coin = MINIMUM(coin, change(n-10)+1);
        return coin;
    }
    else //if ( 16 <= n )
    {
        coin = MINIMUM((change(n-1)+1),(change(n-5)+1));
        coin = MINIMUM(coin, change(n-10)+1);
        coin = MINIMUM(coin, change(n-16)+1);
        return coin;
    }
}

int main()
{
    cout << change(20) << endl;

    return 0;
}