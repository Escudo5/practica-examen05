#include "vect27.hpp"


vect2::vect2()
{
    this->x = 0;
    this->y = 0;
}

vect2::vect2(int x, int y)
{
    this->x = x;
    this->y = y;
}

vect2::vect2(const vect2 &copy)
{
    this->x = copy.x;
    this->y = copy.y;
}

vect2 &vect2::operator=(const vect2 &copy)
{
    if (this != &copy)
    {
        this->x = copy.x;
        this->y = copy.y;
    }
    return *this;
}


int vect2::operator[](int index) const
{
    if (index == 0)
        return this->x;
    return this->y;
}

int &vect2::operator[](int index)
{
    if (index == 0)
        return this->x;
    return this->y;
}

vect2 &vect2::operator++()
{
    this->x++;
    this->y++;
    return *this;
}

vect2 vect2::operator++(int)
{
    vect2 temp = *this;
    this->x++;
    this->y++;
    return temp;
}

vect2 &vect2::operator--()
{
    this->x--;
    this->y--;
    return *this;
}


vect2 vect2::operator--(int)
{
    vect2 temp = *this;
    this->x--;
    this->y--;
    return temp;
}

vect2 &vect2::operator+=(const vect2 &to_sum)
{
    this->x += to_sum.x;
    this->y += to_sum.y;
    return *this;
}

vect2 &vect2::operator-=(const vect2 &to_rest)
{
    this->x -= to_rest.x;
    this->y -= to_rest.y;
    return *this;
}

vect2 &vect2::operator*=(int to_mult)
{
    this->x *= to_mult;
    this->y *= to_mult;
    return *this;
}

vect2 vect2::operator+(const vect2 &to_sum)const
{
    vect2 temp = *this;
    temp.x += to_sum.x;
    temp.y += to_sum.y;
    return temp;
}

vect2 vect2::operator-(const vect2 &to_rest)const
{
    vect2 temp = *this;
    temp.x -= to_rest.x;
    temp.y -= to_rest.y;
    return temp;
}

vect2 vect2::operator*(int to_mult)const
{
    vect2 temp = *this;
    temp.x = this->x * to_mult;
    temp.y = this->y * to_mult
}

