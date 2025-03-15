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

QVector<double> operator*(const QVector<double>& v1, const QVector<double>& v2)
{
    if (v1.size() != v2.size())
    {
        qWarning() << "Размеры векторов не совпадают";
        return QVector<double>();
    }

    if (v1.size() != 3)
    {
        qWarning() << "функция не реализована для size != 3";
        return QVector<double>();
    }

    QVector<double> result(v1.size());

    result[0] = v1[1] * v2[2] - v1[2] * v2[1];
    result[1] = v1[2] * v2[0] - v1[0] * v2[2];
    result[2] = v1[0] * v2[2] - v1[1] * v2[0];

    return result;
}

QVector<double> operator*(double c, const QVector<double>& v)
{
    QVector<double> result(v.size());

    for (int i = 0; i < result.size(); ++i)
    {
        result[i] = c * v[i];
    }

    return result;
}

QVector<double> operator-(const QVector<double>& v1, const QVector<double>& v2)
{
    if (v1.size() != v2.size())
    {
        qWarning() << "Размеры векторов не совпадают";
        return QVector<double>();
    }

    QVector<double> result(v1.size());

    for (int i = 0; i < result.size(); ++i)
    {
        result[i] = v1[i] - v2[i];
    }

    return result;
}

QVector<double> operator/(const QVector<double>& v, double c)
{
    QVector<double> result(v.size());

    for (int i = 0; i < result.size(); ++i)
    {
        result[i] = v[i] / c;
    }

    return result;
}
