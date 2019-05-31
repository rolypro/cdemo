#include "stdio.h"
#include "math.h"
#include "stdlib.h"

typedef struct complex_struct {
    double x, y;
} Complex;

double real_part(Complex z)
{
    return z.x;
}

double img_part(Complex z)
{
    return z.y;
}

double magnitude(Complex z)
{
    return sqrt(z.x * z.x + z.y * z.y);
}

double angle(Complex z)
{
    return atan2(z.y, z.x);
}

Complex make_from_real_img(double x, double y)
{
    Complex z;
    z.x = x;
    z.y = y;
    return z;
}

Complex make_from_mag_ang(double r, double A)
{
    Complex z;
    z.x = r * cos(A);
    z.y = r * sin(A);
    return z;
}

Complex add_complex(Complex z1, Complex z2)
{
    return make_from_real_img(real_part(z1) + real_part(z2),
                                img_part(z1) + img_part(z2));
}

Complex sub_complex(Complex z1, Complex z2)
{
    return make_from_real_img(real_part(z1) - real_part(z2),
                                img_part(z1) - img_part(z2)); 
}

struct complex_struct mul_complex(Complex z1, Complex z2)
{
    return make_from_mag_ang(magnitude(z1) * magnitude(z2),
                                angle(z1) + angle(z2));
}
struct complex_struct div_complex(Complex z1, Complex z2)
{
    return make_from_mag_ang(magnitude(z1) / magnitude(z2),
                                angle(z1) - angle(z2));
}

void print_complex(Complex z)
{
    char *str = "%.1f+%.1fi\n";
    if (z.y < 0)
    {
        str = "%.1f%.1fi\n";
    }
    printf(str,z.x,z.y);
}

int main()
{   
    Complex z1 = {2.0,3.0};
    Complex z2 = {4.0,-5.0};
    print_complex(add_complex(z1,z2));
    system("pause");
}
