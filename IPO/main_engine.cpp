#include "main_engine.h"

void mainEngine()
{
    IPOController& ipo = IPOController::instance(); // Синглтон для удобства

    static double t_md;
    double Tsl = 10.0;

    const QVector<double> tFrontMdOn = {0.0, 1.8, 1.9, 2.0, 2.1, 2.2, 2.3, 2.4, 2.5, 4.0};
    const QVector<double> tFrontMdOff = {0.0, 1.8, 1.9, 2.0, 2.1, 2.2, 2.3, 2.4, 2.5, 4.0};
    const QVector<double> pFrontMdOn = {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 1.0};
    const QVector<double> pFrontMdOff = {1.0, 0.8, 0.7, 0.6, 0.5, 0.4, 0.3, 0.2, 0.1, 0.0};

    // Проверка изменения состояния двигателя
    if ((ipo.Priz_vkl_md == EngineState::Off && ipo.upr_md == EngineState::On) ||
        (ipo.Priz_vkl_md == EngineState::On && ipo.upr_md == EngineState::Off))
    {
        t_md = Tsl;
    }
    ipo.Priz_vkl_md = ipo.upr_md;

    if (ipo.Priz_vkl_md == EngineState::On)
    {  // Двигатель включен
        QVariant interpolated = interpolateLinear(tFrontMdOn, pFrontMdOn, Tsl - t_md);
        ipo.Pmd = interpolated.isValid() ? interpolated.toDouble() : 1.0;
    }
    else
    {  // Двигатель выключен
        if (t_md >= 0.01)
        { // Исключаем ошибку при малом t_md
            QVariant interpolated = interpolateLinear(tFrontMdOff, pFrontMdOff, Tsl - t_md);
            ipo.Pmd = interpolated.isValid() ? interpolated.toDouble() : 0.0;
        }
    }

    ipo.Pmd *= ipo.Pmd_nom;
}
