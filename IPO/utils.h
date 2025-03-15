#pragma once

#include <QVariant>
#include <QVector>
#include <QtMath>

#include <QFile>
#include <QString>
#include <QTextStream>
#include <QDebug>

#include "ipo.h"

QVariant interpolateLinear(const QVector<double>& x, const QVector<double>& y, double inputX);
void nuRead(const QString& filepath);

QVector<double> operator*(const QVector<double>& v1, const QVector<double>& v2);
QVector<double> operator*(double c, const QVector<double>& v);
QVector<double> operator/(const QVector<double>& v, double c);
