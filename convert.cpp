#include <iostream>
#include <QRegExp>
#include "convert.h"

Convert::Convert()
{
  exactConversion.insert("sha", QString::fromUtf8("しゃ"));
  exactConversion.insert("shu", QString::fromUtf8("しゅ"));
  exactConversion.insert("sho", QString::fromUtf8("しょ"));
  exactConversion.insert("cha", QString::fromUtf8("ちゃ"));
  exactConversion.insert("chu", QString::fromUtf8("ちゅ"));
  exactConversion.insert("cho", QString::fromUtf8("ちょ"));
  exactConversion.insert("tsu", QString::fromUtf8("つ"));
  exactConversion.insert("dsu", QString::fromUtf8("づ"));
  exactConversion.insert("dzu", QString::fromUtf8("づ"));
  exactConversion.insert("shi", QString::fromUtf8("し"));
  exactConversion.insert("chi", QString::fromUtf8("ち"));
  exactConversion.insert("ja", QString::fromUtf8("じゃ"));
  exactConversion.insert("ju", QString::fromUtf8("じゅ"));
  exactConversion.insert("jo", QString::fromUtf8("じょ"));
  exactConversion.insert("ji", QString::fromUtf8("じ"));

  comboConversionPrefix.insert("k", QString::fromUtf8("き"));
  comboConversionPrefix.insert("n", QString::fromUtf8("に"));
  comboConversionPrefix.insert("h", QString::fromUtf8("ひ"));
  comboConversionPrefix.insert("m", QString::fromUtf8("み"));
  comboConversionPrefix.insert("r", QString::fromUtf8("り"));
  comboConversionPrefix.insert("g", QString::fromUtf8("ぎ"));
  comboConversionPrefix.insert("b", QString::fromUtf8("び"));
  comboConversionPrefix.insert("p", QString::fromUtf8("ぴ"));
  comboConversionPrefix.insert("d", QString::fromUtf8("ぢ"));
  comboConversionPrefix.insert("j", QString::fromUtf8("じ"));

  comboConversionSuffix.insert("ya", QString::fromUtf8("ゃ"));
  comboConversionSuffix.insert("yu", QString::fromUtf8("ゅ"));
  comboConversionSuffix.insert("yo", QString::fromUtf8("ょ"));

  genericConversion.insert("ka", QString::fromUtf8("か"));
  genericConversion.insert("ki", QString::fromUtf8("き"));
  genericConversion.insert("ku", QString::fromUtf8("く"));
  genericConversion.insert("ke", QString::fromUtf8("け"));
  genericConversion.insert("ko", QString::fromUtf8("こ"));

  genericConversion.insert("ga", QString::fromUtf8("が"));
  genericConversion.insert("gi", QString::fromUtf8("ぎ"));
  genericConversion.insert("gu", QString::fromUtf8("ぐ"));
  genericConversion.insert("ge", QString::fromUtf8("げ"));
  genericConversion.insert("go", QString::fromUtf8("ご"));

  genericConversion.insert("sa", QString::fromUtf8("さ"));
  genericConversion.insert("si", QString::fromUtf8("し"));
  genericConversion.insert("su", QString::fromUtf8("す"));
  genericConversion.insert("se", QString::fromUtf8("せ"));
  genericConversion.insert("so", QString::fromUtf8("そ"));

  genericConversion.insert("za", QString::fromUtf8("ざ"));
  genericConversion.insert("zi", QString::fromUtf8("じ"));
  genericConversion.insert("zu", QString::fromUtf8("ず"));
  genericConversion.insert("ze", QString::fromUtf8("ぜ"));
  genericConversion.insert("zo", QString::fromUtf8("ぞ"));

  genericConversion.insert("ta", QString::fromUtf8("た"));
  genericConversion.insert("ti", QString::fromUtf8("ち"));
  genericConversion.insert("te", QString::fromUtf8("て"));
  genericConversion.insert("to", QString::fromUtf8("と"));

  genericConversion.insert("da", QString::fromUtf8("だ"));
  genericConversion.insert("di", QString::fromUtf8("ぢ"));
  genericConversion.insert("de", QString::fromUtf8("で"));
  genericConversion.insert("do", QString::fromUtf8("ど"));

  genericConversion.insert("na", QString::fromUtf8("な"));
  genericConversion.insert("ni", QString::fromUtf8("に"));
  genericConversion.insert("nu", QString::fromUtf8("ぬ"));
  genericConversion.insert("ne", QString::fromUtf8("ね"));
  genericConversion.insert("no", QString::fromUtf8("の"));

  genericConversion.insert("ha", QString::fromUtf8("は"));
  genericConversion.insert("hi", QString::fromUtf8("ひ"));
  genericConversion.insert("fu", QString::fromUtf8("ふ"));
  genericConversion.insert("he", QString::fromUtf8("へ"));
  genericConversion.insert("ho", QString::fromUtf8("ほ"));

  genericConversion.insert("ba", QString::fromUtf8("ば"));
  genericConversion.insert("bi", QString::fromUtf8("び"));
  genericConversion.insert("bu", QString::fromUtf8("ぶ"));
  genericConversion.insert("be", QString::fromUtf8("べ"));
  genericConversion.insert("bo", QString::fromUtf8("ぼ"));

  genericConversion.insert("pa", QString::fromUtf8("ぱ"));
  genericConversion.insert("pi", QString::fromUtf8("ぴ"));
  genericConversion.insert("pu", QString::fromUtf8("ぷ"));
  genericConversion.insert("pe", QString::fromUtf8("ぺ"));
  genericConversion.insert("po", QString::fromUtf8("ぽ"));

  genericConversion.insert("ma", QString::fromUtf8("ま"));
  genericConversion.insert("mi", QString::fromUtf8("み"));
  genericConversion.insert("mu", QString::fromUtf8("む"));
  genericConversion.insert("me", QString::fromUtf8("め"));
  genericConversion.insert("mo", QString::fromUtf8("も"));

  genericConversion.insert("ya", QString::fromUtf8("や"));
  genericConversion.insert("yu", QString::fromUtf8("ゆ"));
  genericConversion.insert("yo", QString::fromUtf8("よ"));

  genericConversion.insert("ra", QString::fromUtf8("ら"));
  genericConversion.insert("ri", QString::fromUtf8("り"));
  genericConversion.insert("ru", QString::fromUtf8("る"));
  genericConversion.insert("re", QString::fromUtf8("れ"));
  genericConversion.insert("ro", QString::fromUtf8("ろ"));

  genericConversion.insert("wa", QString::fromUtf8("わ"));

  vowelConversion.insert("a", QString::fromUtf8("あ"));
  vowelConversion.insert("e", QString::fromUtf8("え"));
  vowelConversion.insert("i", QString::fromUtf8("い"));
  vowelConversion.insert("o", QString::fromUtf8("お"));
  vowelConversion.insert("u", QString::fromUtf8("う"));

  consonantConversion.insert("n'", QString::fromUtf8("ん")); //allows for kanyuu -> かんゆう etc
  consonantConversion.insert("n", QString::fromUtf8("ん"));
  consonantConversion.insert("t", QString::fromUtf8("っ"));
  consonantConversion.insert("k", QString::fromUtf8("っ"));
  consonantConversion.insert("s", QString::fromUtf8("っ"));
}

QString Convert::romajiToJapanese(QString value)
{
  value = value.toUtf8();

  QHashIterator<QString, QString> i1(exactConversion);
  while(i1.hasNext()) {
    i1.next();
    QRegExp rx(i1.key());
    value.replace(rx, i1.value());
  }
  QHashIterator<QString, QString> i4(genericConversion);
  while(i4.hasNext()) {
    i4.next();
    QRegExp rx(i4.key());
    value.replace(rx, i4.value());
  }
  QHashIterator<QString, QString> i2(comboConversionSuffix);
  while(i2.hasNext()) {
    i2.next();
    QHashIterator<QString, QString> i3(comboConversionPrefix);
    while(i3.hasNext()) {
      i3.next();
      QRegExp rx(i2.key() + i3.key());
      value.replace(rx, i2.value() + i3.value());
    }
    QRegExp rx(i2.key());
    value.replace(rx, i2.value());
  }
  QHashIterator<QString, QString> i5(vowelConversion);
  while(i5.hasNext()) {
    i5.next();
    QRegExp rx(i5.key());
    value.replace(rx, i5.value());
  }
  QHashIterator<QString, QString> i6(consonantConversion);
  while(i6.hasNext()) {
    i6.next();
    QRegExp rx(i6.key());
    value.replace(rx, i6.value());
  }
  return value;
}
