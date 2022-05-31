
#ifndef LABOGKG_PRIME_PRIME_POLYGON_H
#define LABOGKG_PRIME_PRIME_POLYGON_H

#endif //LABOGKG_PRIME_POLYGON_H

#pragma once

#include<iostream>
#include<vector>

using namespace std;

struct point
{
    double x = 0;
    double y = 0;
};
// багатокутник наш
class prime_polygon
{
public:
    vector<pair<pair<point, point>, int>> sides;
    // вектор відрізків з 2-ох точок та число яке вказуватиме на те чи відрізок:
    // 0 = входить в ламану
    // 1 = крайній в ламаній з крайньою лівою точкою
    // 2 = крайній в ламаній з крайньою правою точкою
    // 3 = не входить в ламану
    prime_polygon();
    prime_polygon(vector<pair<pair<point, point>, int>> s);
    void add_s(pair<point, point> s);
    int preparation_of_side(pair<point, point> s);
    int check_side(pair<point, point> s, int num);
    void final_check();
    int Is_prime = 0;
    //  0 = багатокутник не простий
    //  1 = багатокутник став простим
    //  2 = багатокутник перестає бути простим
    int compare_sides(pair<point, point> a, pair<point, point> b);
    // порівняння пар точок:
    // 1 = 1 це 1
    // 2 = 2 це 2
    // 2 = 1 це 3
    // 2 = 2 це 4
    // решта = 5
    bool intersection(point V11, point V12, point V21, point V22);
};