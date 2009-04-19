#ifndef CONVERT_H
#define CONVERT_H

#include <QHash>

class Convert
{
public:
    Convert();

    QString romajiToJapanese(QString value);

    QHash<QString, QString> exactConversion;
    QHash<QString, QString> comboConversionPrefix;
    QHash<QString, QString> comboConversionSuffix;
    QHash<QString, QString> genericConversion;
    QHash<QString, QString> vowelConversion;
    QHash<QString, QString> consonantConversion;
};

#endif // CONVERT_H
