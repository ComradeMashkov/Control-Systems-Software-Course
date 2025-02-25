#pragma once

#include <QVector>
#include <QVariant>
#include <QObject>

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
    QVector<double> Ri {0.0, 0.0, 0.0};
    QVector<double> Vi {0.0, 0.0, 0.0};
    double Pmd = 0.0;
    double Pmd_nom = 1.0;

    // Флаги управления
    EngineState upr_md = EngineState::Off;
    EngineState Priz_vkl_md = EngineState::Off;
    uint8_t N_vkl_md = 0;

private:
    IPOController() = default;
    IPOController(const IPOController&) = delete;
    IPOController& operator=(const IPOController&) = delete;
};

