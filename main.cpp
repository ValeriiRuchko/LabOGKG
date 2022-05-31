#include <iostream>
#include <vector>
#include "Prime_polygon.h"

using namespace std;

int main()
{
    const int N1 = 11;
    const int N2 = 4;

    /*int xarr1[4] = { 17, 23, 19,  9 };
	int yarr1[4] = { 2,  8, 15,  5 };*/
    /*
    double xarr1[4] = { 6,  9,  6,  3 };
    double yarr1[4] = { 5,  8, 11,  8 };
    double xarr[11] = { 6, 10, 14, 15, 13, 10,  7,  4, 3, 3, 4 };
    double yarr[11] = { 3,  3,  6, 10, 13, 15, 15, 12, 9, 7, 5 };

    prime_polygon Table1;
    for (int i = 0; i < 4; i++)
    {
        point fake1 = { xarr[i], yarr[i] };
        point fake2 = { xarr[(i + 1) % N1], yarr[(i + 1) % N1] };
        Table1.add_s({ fake1, fake2 });
        cout << Table1.Is_prime << endl;
    }
    for (int i = 0; i < N2; i++)
    {
        point fake1 = { xarr1[i], yarr1[i] };
        point fake2 = { xarr1[(i + 1) % N2], yarr1[(i + 1) % N2] };
        Table1.add_s({ fake1, fake2 });
        cout << Table1.Is_prime << endl;
    }
    for (int i = 4; i < N1; i++)
    {
        point fake1 = { xarr[i], yarr[i] };
        point fake2 = { xarr[(i + 1) % N1], yarr[(i + 1) % N1] };
        Table1.add_s({ fake1, fake2 });
        cout << Table1.Is_prime << endl;
    }
    */
    pair<point, point> p1 = { {17, 2}, {23, 8} },
        p2 = { {23, 8}, {19, 5} },
        p3 = { {19, 5}, {9, 5} },
        p4 = { {9, 5}, {17, 2} };
    prime_polygon Table1;
    Table1.add_s(p1);
    cout << Table1.Is_prime << endl;
     Table1.add_s(p2);
    cout << Table1.Is_prime << endl;
    Table1.add_s(p3);
    cout << Table1.Is_prime << endl;
    Table1.add_s(p4);
    cout << Table1.Is_prime << endl;


    /*
    pair<point, point> p1 = { {3, 8}, {6, 5} },
        p2 = { {6, 11}, {9, 8} },
        p3 = { {3, 8}, {6, 11} },
        p4 = { {9, 8}, {6, 5} },
        p5 = { {9, 8}, {6, 5} },
        intersect = { {6, 8}, {3, 11} };
    prime_polygon Table1;
    Table1.add_s(p1);
    cout << Table1.Is_prime << endl;
    Table1.add_s(p2);
    cout << Table1.Is_prime << endl;
    Table1.add_s(p3);
    cout << Table1.Is_prime << endl;
    Table1.add_s(p4);
    cout << Table1.Is_prime << endl;
    Table1.add_s(p5);
    cout << Table1.Is_prime << endl;
    Table1.add_s(intersect);
    cout << Table1.Is_prime << endl; */
    return 0;
}