#include "grav_acc.h"

QVector<double> gravitational_acceleration(
    const QVector<double>& r
)
{
    const double b0 = 398600.4418 * pow(10, 9);
    const double b2 = 0.1755650 * pow(10, 26);
    const double b4 = 1.563955 * pow(10, 36);
    const double q = -1082.62575 * pow(10, -6);

    const double R = sqrt(r[0] * r[0] + r[1] * r[1] + r[2] * r[2]);

    const double delta_gr = -1.5 * b2 * ((5 * q * q - 1) / pow(R, 4)) - 1.875 * b4 * ((21 * pow(q, 4) - 14 * pow(q, 2) + 1) / pow(R, 6));
    const double delta_g0 = 3 * b2 * q/pow(R, 4) + 2.5 * b4 * ((7 * pow(q, 3) - 3 * q) / pow(R, 6));

    QVector<double> g_result = {0, 0, 0};

    g_result[0] = -b0 * r[0] / pow(R, 3) + delta_gr * r[0] / R;
    g_result[1] = -b0 * r[1] / pow(R, 3) + delta_gr * r[1] / R;
    g_result[2] = -b0 * r[2] / pow(R, 3) + delta_gr * r[2] / R + delta_g0;

    return g_result;
}
