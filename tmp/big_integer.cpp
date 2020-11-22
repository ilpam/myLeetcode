
#include <cstdio>
#include <vector>

class big_integer
{
private:
    static const int BASE = 100000000;
    static const int WIDTH = 8;
    std::vector<int> s;
    /* data */
public:
    big_integer();
    big_integer(long long num);
    big_integer(const big_integer&);
    ~big_integer();
};

big_integer::big_integer() = default;

big_integer::big_integer(long long num)
{
    s.clear();
    do {
        s.push_back(num % BASE);
        num /= BASE;
    } while (num > 0);
}

big_integer::big_integer(const big_integer &num)
{
    big_integer tmp;
    tmp.s = num.s;
}

big_integer& big_integer::operator= (const big_integer &num)
{
    big_integer tmp(num);

    return *this;
}

big_integer::~big_integer()
{
}

int main()
{
    big_integer a(123456);
    big_integer b(99999998);
    printf("hello world\n");
    while (1);
    return 0;
}
