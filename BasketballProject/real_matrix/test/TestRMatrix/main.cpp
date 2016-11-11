#include <iostream>
using namespace std;


#include "D:\Basketball\Algorithm Roberts\Roberts\real_matrix\real_matrix.h"

int main()
{
    try
    {
        rmatrix a;
        cout << "a " << a << endl;
        rmatrix b(3, 4);
        cout << "b " << b << endl;
        rmatrix c(3, 4, 1.1);
        cout << "c " << c << endl;
        rmatrix d(c);
        cout << "d " << d << endl;
        rmatrix e(rmatrix(3, 2, 0));
        cout << "e " << e << endl;
        rmatrix f(3, 4);
        for (uint i = 0; i < f.rowCount(); i++)
            for (uint j = 0; j < f.columnCount(); j++)
            {
                f[i][j] = i*f.columnCount() + j;
            }
        cout << "f " << f << endl;
        rmatrix g;
        g = f.transposition();
        cout << "g " << g << endl;

        rmatrix h = f;
        h.multiplaction(2);
        cout << "h " << h << endl;
        rmatrix k = f * 0.5;
        cout << "k " << k << endl;
        rmatrix i = 1.5 * f;
        cout << "i " << i << endl;
        rmatrix j = f;
        j *= 3;
        cout << "j " << j << endl;

        rmatrix m = k;
        m.addition(i);
        cout << "m " << m << endl;
        rmatrix n = k + i;
        cout << "n " << n << endl;
        rmatrix o = k;
        o += i;
        cout << "o " << o << endl;

        rmatrix p = i;
        p.subtraction(k);
        cout << "p " << p << endl;
        rmatrix r = i - k;
        cout << "r " << r << endl;
        rmatrix q = i;
        q -= k;
        cout << "q " << q << endl;

        rmatrix s1 = f.multiplaction(g);
        cout << "s1 " << s1 << endl;
        rmatrix s2 = f * g;
        cout << "s2 " << s2 << endl;
        rmatrix s3 = f;
        s3 *= g;
        cout << "s3 " << s3 << endl;

        rmatrix t1 = s3;
        t1.division(2);
        cout << "t1 " << t1 << endl;
        rmatrix t2 = s3 / 0.5;
        cout << "t2 " << t2 << endl;
        rmatrix t3 = s3;
        t3 /= 4;
        cout << "t3 " << t3 << endl;

        array<real> arr1(4, 2);
        rmatrix u1(3, 1, 1);
        rmatrix u2(u1);
        u1 = u1 * arr1;
        u2 *= arr1;
        cout << "u1 " << u1 << endl;
        cout << "u2 " << u2 << endl;

        array<real> arr2(4, 2);
        rmatrix u3(4, 6, 3);
        arr2 = arr2 * u3;
        cout << arr2 << endl;

        rmatrix x1(2, 3, 1.5);
        rmatrix x2(x1);
        x1.negation();
        x2 = -x2;
        cout << x1 << endl;
        cout << x2 << endl;
    }
    catch(errorBase& error)
    {
        cout << error.what();
    }
    getchar();
    return 0;
}
