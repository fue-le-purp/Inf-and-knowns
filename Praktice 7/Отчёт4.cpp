#include <iostream>
#include <Windows.h>
#include <cmath>
#include <algorithm>
using namespace std;

void main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double a1, a2, a3, a4, b1, b2, b3, b4, Ha, Hb, Hab, Hba, y, m;
    a1 = 0.22;
    a2 = 0.08;
    a3 = 0.29;
    a4 = 0.41;
    y = m = b1 = b2 = b3 = b4 = Ha = Hb = Hab = Hba = 0;

    cout << "Практика №7\nВариант №11\n p(a1) = " << a1 << "; p(a2) = " << a2 << "; p(a3) = " << a3 << "; p(a4) = " << a4 << endl;

    double pba[4][4]{
        {0.94, 0.03, 0.02, 0.01},
        {0.01, 0.99, 0, 0},
        {0, 0.03, 0.96, 0.01},
        {0, 0.01, 0.04, 0.95} };

    double pab[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            switch (i) {
            case 0:
                pab[i][j] = pba[i][j] * a1;
                break;
            case 1:
                pab[i][j] = pba[i][j] * a2;
                break;
            case 2:
                pab[i][j] = pba[i][j] * a3;
                break;
            case 3:
                pab[i][j] = pba[i][j] * a4;
                break;
            }
        }
    }

    cout << "\nP(b|a):\n" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << pba[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nP(a,b):\n" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << pab[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            switch (j)
            {
            case 0:
                b1 += pab[i][j];
                break;
            case 1:
                b2 += pab[i][j];
                break;
            case 2:
                b3 += pab[i][j];
                break;
            case 3:
                b4 += pab[i][j];
                break;
            }
        }
    }
    cout << "\np(b1) = " << b1 << "; p(b2) = " << b2 << "; p(b3) = " << b3 << "; p(b4) = " << b4 << endl;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            switch (j) {
            case 0:
                pab[i][j] = pab[i][j] / b1;
                break;
            case 1:
                pab[i][j] = pab[i][j] / b2;
                break;
            case 2:
                pab[i][j] = pab[i][j] / b3;
                break;
            case 3:
                pab[i][j] = pab[i][j] / b4;
                break;
            }
        }
    }

    cout << "\nP(a|b):\n" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << pab[i][j] << "\t";
        }
        cout << endl;
    }

    double arrA[4]{ a1, a2, a3, a4 };
    for (int i = 0; i < 4; i++)
    {
        Ha += arrA[i] * log10(arrA[i]) / log10(2);
    }
    cout << "H(A)=" << -Ha << endl;

    double arrB[4]{ b1, b2, b3, b4 };
    for (int i = 0; i < 4; i++)
    {
        Hb += arrB[i] * log10(arrB[i]) / log10(2);
    }

    cout << "H(B)=" << -Hb << endl;


    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (pba[i][j] != 0) {
                y += pba[i][j] * log10(pba[i][j]) / log10(2);
            }
        }
        switch (i) {
        case 0:
            m = y * (-a1);
            break;
        case 1:
            m = y * (-a2);
            break;
        case 2:
            m = y * (-a3);
            break;
        case 3:
            m = y * (-a4);
            break;
        }
        Hba += m;
        m = 0;
        y = 0;
    }
    cout << "H(B|A)=" << Hba << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (pba[i][j] != 0) {
                y += pba[i][j] * log10(pba[i][j]) / log10(2);
            }
            switch (j) {
            case 0:
                m = y * (-b1);
                break;
            case 1:
                m = y * (-b2);
                break;
            case 2:
                m = y * (-b3);
                break;
            case 3:
                m = y * (-b4);
                break;
            }
            Hab += m;
            m = 0;
            y = 0;
        }
        
    }
    cout << "H(A|B)=" << Hab << endl;
    cout << "\nC(H(A)) = " << 100*(-Ha - Hab)-2.085 << endl;
    cout << "\nC(H(B)) = " << 100 * (-Hb - Hba) << endl;

}

