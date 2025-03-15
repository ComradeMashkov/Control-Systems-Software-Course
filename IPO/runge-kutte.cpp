#include "ipo.h"
#include "grav_acc.h"

QVector<double> f(const QVector<double>& y)
{
    QVector<double> result(y.size(), 0.0);

    QVector<double> Vk = {0, 0, 0}; QVector<double> Vg = {0, 0, 0};
    // Computing Vk & Vg

    for (int i = 1; i < y.size(); ++i)
    {
        result[i] = Vk[i - 1] + Vg[i - 1];
    }

    return result;
}

void rk4(double t)
{
    IPOController& ipo = IPOController::instance();

    // y = t, V, R, ??? m, dm ???
    // f(y) = Vk + Vg

    QVector<double> y; y.emplaceBack(t);
    for (int i = 0; i < ipo.Vi.size(); ++i) y.emplaceBack(ipo.Vi[i]);
    for (int i = 0; i < ipo.Ri.size(); ++i) y.emplaceBack(ipo.Ri[i]);

    const int n = y.size();
    QVector<double> k1(n), k2(n), k3(n), k4(n), temp(n);

    k1 = f(y);
    for (int i = 1; i < n; ++i) temp[i] = y[i] + 0.5 * h * k1[i];

    k2 = f(temp);
    for (int i = 1; i < n; ++i) temp[i] = y[i] + 0.5 * h * k2[i];

    k3 = f(temp);
    for (int i = 1; i < n; ++i) temp[i] = y[i] + h * k3[i];

    k4 = f(temp);

    for (int i = 1; i < n; ++i)
    {
        y[i] += (h / 6.0) * (k1[i] + 2.0 * k2[i] + 2.0 * k3[i] + k4[i]);
    }
}
