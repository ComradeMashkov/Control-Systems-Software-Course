#include "utils.h"

QVariant interpolateLinear(const QVector<double>& x, const QVector<double>& y, double inputX)
{
    int n = x.size();
    if (n < 2 || x.size() != y.size())
    {
        return QVariant(); // Возвращаем пустой конструктор QVariant, если получили неправильные данные на вход
    }

    inputX = qBound(x.first(), inputX, x.last()); // Ограничиваем inputX в пределах допустимых значений x

    for (int i = 1; i < n; ++i)
    {
        if (inputX <= x[i])
        {
            return y[i] + (inputX - x[i - 1]) / (x[i - 1] - x[i]) * (y[i - 1] - y[i]);
        }
    }

    return y.last();
}

void nuRead(const QString& filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qWarning() << "Ошибка открытия файла: " << filePath;
        return;
    }

    QTextStream in(&file);
    QString line = in.readLine();
    if (!line.isEmpty())
    {
        IPOController::instance().Pmd_nom = line.toDouble();
    }

    file.close();
}
