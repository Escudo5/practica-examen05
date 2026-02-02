#include "vect26.hpp"


vect2::vect2()
{
    this->x = 0;
    this ->y = 0;
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

vect2::~vect2()
{}


int vect2::operator[](int index)const
{
    if (index == 0)
        return this->x;
    else
        return this->y;
}

int &vect2::operator[](int index)
{
    if (index == 0)
        return this->x;
    else
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
    temp.y = to_rest.y;
    return temp;
}

vect2 vect2::operator*(int to_mult)const
{
    vect2 temp = *this;
    temp.x = this->x * to_mult;
    temp.y = this->y * to_mult;
    return temp;
}

vect2 vect2::operator-()const
{
    vect2 temp = *this;
    temp.x = -this->x;
    temp.y = -this->y;
    return temp;
}

bool vect2::operator!=(const vect2 &no)const
{
    if (this->x != no.x || this->y != no.y)
        return true;
    return false;
}

bool vect2::operator==(const vect2 &yes)const
{
    if (this->x == yes.x && this->y == yes.y)
        return true;
    return false;
}

vect2 operator*(int num, const vect2 &to_mult)
{
    vect2 temp(to_mult);
    temp *= num; 
    return temp;
}

std::ostream& operator<<(std::ostream& out, const vect2& to_print)
{
    out << "{" << to_print[0] << ", " << to_print[1] << "}";
    return out;
}