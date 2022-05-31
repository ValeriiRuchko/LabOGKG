
#include "Prime_polygon.h"
#include <iostream>

using namespace std;

prime_polygon::prime_polygon()
{

}

prime_polygon::prime_polygon(vector<pair<pair<point, point>, int>> s)
{
    this->sides = s;
}

void prime_polygon::add_s(pair<point, point> s)
{
    for (int i = 1; i < this->sides.size(); i++)
    {
        if (intersection(this->sides[i].first.first, this->sides[i].first.second, s.first, s.second))
        {
            Is_prime = 2;
        }
    }
    if (Is_prime == 1)
    {
        Is_prime = 2;
    }
    if (Is_prime == 2)
    {
        pair<pair<point, point>, int> res = { s, 3 };
        this->sides.push_back(res);
        return;
    }
    pair<pair<point, point>, int> res = {s, preparation_of_side(s) };
    this->sides.push_back(res);
    for (int i = 1; i < this->sides.size(); i++)
    {
        if (this->sides[i].second == 3)
        {
            this->sides[i].second = check_side(this->sides[i].first, i);
        }
    }
    final_check();
}

int prime_polygon::preparation_of_side(pair<point, point> s)
{
    pair<pair<point, point>, int> res = { s, 3 };
    if (this->sides.size() != 0)
    {
        if (this->sides[0].second == 3)
        {
            int r = compare_sides(this->sides[0].first, res.first);
            switch (r)
            {
                case 1:
                    this->sides[0].second = 2;
                    res.second = 2;
                    break;
                case 2:
                    this->sides[0].second = 1;
                    res.second = 2;
                    break;
                case 3:
                    this->sides[0].second = 2;
                    res.second = 1;
                    break;
                case 4:
                    this->sides[0].second = 1;
                    res.second = 1;
                    break;
                default:
                    break;
            }
        }
        else
        {
            for (int i = 0; i < this->sides.size(); i++)
            {
                if ((this->sides[i].second == 1) || (this->sides[i].second == 2))
                {
                    point p;
                    if (this->sides[i].second == 1)
                        p = this->sides[i].first.first;
                    else
                        p = this->sides[i].first.second;
                    if ((p.x == res.first.first.x) && (p.y == res.first.first.y))
                    {
                        this->sides[i].second = 0;
                        res.second = 2;
                        break;
                    }
                    else if ((p.x == res.first.second.x) && (p.y == res.first.second.y))
                    {
                        this->sides[i].second = 0;
                        res.second = 1;
                        break;
                    }
                }
            }
        }
    }
    return res.second;
}

int prime_polygon::check_side(pair<point, point> s, int num)
{
    pair<pair<point, point>, int> res = { s, 3 };
    if (this->sides.size() != 0)
    {
        if (this->sides[0].second == 3)
        {
            int r = compare_sides(this->sides[0].first, res.first);
            switch (r)
            {
                case 1:
                    this->sides[0].second = 2;
                    res.second = 2;
                    break;
                case 2:
                    this->sides[0].second = 1;
                    res.second = 2;
                    break;
                case 3:
                    this->sides[0].second = 2;
                    res.second = 1;
                    break;
                case 4:
                    this->sides[0].second = 1;
                    res.second = 1;
                    break;
                default:
                    break;
            }
        }
        else
        {
            for (int i = 0; i < this->sides.size(); i++)
            {
                if (i == num)
                    continue;
                if ((this->sides[i].second == 1) || (this->sides[i].second == 2))
                {
                    point p;
                    if (this->sides[i].second == 1)
                        p = this->sides[i].first.first;
                    else
                        p = this->sides[i].first.second;
                    if ((p.x == res.first.first.x) && (p.y == res.first.first.y))
                    {
                        this->sides[i].second = 0;
                        res.second = 2;
                        break;
                    }
                    else if ((p.x == res.first.second.x) && (p.y == res.first.second.y))
                    {
                        this->sides[i].second = 0;
                        res.second = 1;
                        break;
                    }
                }
            }
        }
    }
    return res.second;
}

void prime_polygon::final_check()
{
    vector<pair<int, point>> res;
    for (int i = 0; i < this->sides.size(); i++)
    {
        if (this->sides[i].second == 1)
        {
            res.push_back({ i, this->sides[i].first.first });
        }
        else if (this->sides[i].second == 2)
        {
            res.push_back({ i, this->sides[i].first.second });
        }
    }
    if (res.size() > 0)
        if ((res[0].second.x == res[1].second.x) && (res[0].second.y == res[1].second.y))
        {
            this->sides[res[0].first].second = 0;
            this->sides[res[1].first].second = 0;
        }
    // чи все входить в ламану
    bool is_bag = true;
    for (int i = 0; i < this->sides.size(); i++)
    {
        if (this->sides[i].second != 0)
        {
            is_bag = false;
        }
    }
    if (is_bag == true) // якщо все входить в ламану - простий
    {
        Is_prime = 1;
    }
    if (res.size() > 0) // якщо ламана замкнулась але не все входить в багатокутник - не простий
        if ((res[0].second.x == res[1].second.x) && (res[0].second.y == res[1].second.y) && (is_bag == false))
        {
            Is_prime = 2;
        }
}

int prime_polygon::compare_sides(pair<point, point> a, pair<point, point> b)
{
    if ((a.first.x == b.first.x) && (a.first.y == b.first.y))
    {
        return 1;
    }
    if ((a.second.x == b.first.x) && (a.second.y == b.first.y))
    {
        return 2;
    }
    if ((a.first.x == b.second.x) && (a.first.y == b.second.y))
    {
        return 3;
    }
    if ((a.second.x == b.second.x) && (a.second.y == b.second.y))
    {
        return 4;
    }
    return 5;
}

bool prime_polygon::intersection(point V11, point V12, point V21, point V22)
{
    double A = V11.y - V12.y,
            B = V12.x - V11.x,
            C = V11.x * V12.y - V12.x * V11.y;
    if (((V21.x * A + V21.y * B + C) * (V22.x * A + V22.y * B + C)) >= 0)
    {
        return false;
    }
    A = V21.y - V22.y,
    B = V22.x - V21.x,
    C = V21.x * V22.y - V22.x * V21.y;
    if (((V11.x * A + V11.y * B + C) * (V12.x * A + V12.y * B + C)) >= 0)
    {
        return false;
    }
    return true;
}