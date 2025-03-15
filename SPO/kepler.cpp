#include "kepler.h"
#include "../IPO/ipo.h"
#include "../IPO/utils.h"
#include "math.h"

void kepler()
{
    // IPOController& ipo = IPOController::instance();

    // const double X = ipo.Ri[0];
    // const double Y = ipo.Ri[1];
    // const double Z = ipo.Ri[2];
    // const double R = sqrt(X*X + Y*Y + Z*Z);

    // const double Vx = ipo.Vi[0];
    // const double Vy = ipo.Vi[1];
    // const double Vz = ipo.Vi[2];
    // const double V = sqrt(Vx*Vx + Vy*Vy + Vz*Vz);

    // const double Vr = (X*Vx + Y*Vy + Z*Vz) / R;

    // const QVector<double> h = ipo.Ri * ipo.Vi;
    // const double H = sqrt(h[0] * h[0] + h[1] * h[1] + h[2] * h[2]);

    // ipo.nakl_kep = acos(h[2] / H);

    // const QVector<double> K = {0.0, 0.0, 1.0};
    // const QVector<double> N = K * h;
    // const double N_abs = sqrt(N[0] * N[0] + N[1] * N[1] + N[2] * N[2]);

    // if (N[1] > 0)
    // {
    //     ipo.Omega_kep = acos(N[0] / N_abs);
    // }
    // else
    // {
    //     ipo.Omega_kep = 2*PI - acos(N[0] / N_abs);
    // }

    // const QVector<double> e = 1/MU * ((ipo.Vi * h) - ((MU * ipo.Ri) / R));

    // ipo.e_kep = sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);

    // const double Ne = N[0] * e[0] + N[1] * e[1] + N[2] * e[2];
    // if (e[2] >= 0)
    // {
    //     ipo.w_kep = acos(Ne / (N_abs * ipo.e_kep));
    // }
    // else
    // {
    //     ipo.w_kep = 2*PI - acos(Ne / (N_abs * ipo.e_kep));
    // }

    // const double er = e[0] * ipo.Ri[0] + e[1] * ipo.Ri[1] + e[2] * ipo.Ri[2];
    // if (Vr >= 0)
    // {
    //     ipo.teta_kep = acos(er / (ipo.e_kep * R));
    // }
    // else
    // {
    //     ipo.teta_kep = 2*PI - acos(er / (ipo.e_kep * R));
    // }
}
