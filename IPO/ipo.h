#pragma once

#include <QVector>
#include <QVariant>
#include <QObject>

#define PI 3.14159265358979
#define MU 398600.4418 * pow(10, 9)

enum class EngineState : uint8_t
{
    Off = 0,
    On = 1
};

class IPOController
{
public:
    static IPOController& instance()
    {
        static IPOController instance;
        return instance;
    }

    // Данные ИПО
    double htc = 0.0;
    QVector<double> Ri  {0.0, 0.0, 0.0};
    QVector<double> Vi  {0.0, 0.0, 0.0};
    QVector<double> g   {0.0, 0.0, 0.0};
    double Pmd = 0.0;
    double Pmd_nom = 1.0;

    double T_kep        = 0.0; // период
    double nakl_kep     = 0.0; // наклонение (x)
    double e_kep        = 0.0; // эксцентриситет (x)
    double H_a_kep      = 0.0; // высота перицентра
    double H_p_kep      = 0.0; // высота апоцентра
    double w_kep        = 0.0; // аргумент перицентра (x)
    double teta_kep     = 0.0; // истинная аномалия (x)
    double Omega_kep    = 0.0; // долгота восходящего узла (x)

    // Флаги управления
    EngineState upr_md = EngineState::Off;
    EngineState Priz_vkl_md = EngineState::Off;
    uint8_t N_vkl_md = 0;

private:
    IPOController() = default;
    IPOController(const IPOController&) = delete;
    IPOController& operator=(const IPOController&) = delete;
};

