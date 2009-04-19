#include <iostream>
#include <QRegExp>
#include "convert.h"

Convert::Convert()
{
  exactConversion.insert("sha", "しゃ");
  exactConversion.insert("shu", "しゅ");
  exactConversion.insert("sho", "しょ");
  exactConversion.insert("cha", "ちゃ");
  exactConversion.insert("chu", "ちゅ");
  exactConversion.insert("cho", "ちょ");
  exactConversion.insert("tsu", "つ");
  exactConversion.insert("dsu", "づ");
  exactConversion.insert("dzu", "づ");
  exactConversion.insert("shi", "し");
  exactConversion.insert("chi", "ち");
  exactConversion.insert("ja", "じゃ");
  exactConversion.insert("ju", "じゅ");
  exactConversion.insert("jo", "じょ");
  exactConversion.insert("ji", "じ");

  comboConversionPrefix.insert("k", "き");
  comboConversionPrefix.insert("n", "に");
  comboConversionPrefix.insert("h", "ひ");
  comboConversionPrefix.insert("m", "み");
  comboConversionPrefix.insert("r", "り");
  comboConversionPrefix.insert("g", "ぎ");
  comboConversionPrefix.insert("b", "び");
  comboConversionPrefix.insert("p", "ぴ");
  comboConversionPrefix.insert("d", "ぢ");
  comboConversionPrefix.insert("j", "じ");

  comboConversionSuffix.insert("ya", "ゃ");
  comboConversionSuffix.insert("yu","ゅ");
  comboConversionSuffix.insert("yo", "ょ");  

  genericConversion.insert("ka", "か");
  genericConversion.insert("ki", "き");
  genericConversion.insert("ku", "く");
  genericConversion.insert("ke", "け");
  genericConversion.insert("ko", "こ");

  genericConversion.insert("ga", "が");
  genericConversion.insert("gi", "ぎ");
  genericConversion.insert("gu", "ぐ");
  genericConversion.insert("ge", "げ");
  genericConversion.insert("go", "ご");

  genericConversion.insert("sa", "さ");
  genericConversion.insert("si", "し");
  genericConversion.insert("su", "す");
  genericConversion.insert("se", "せ");
  genericConversion.insert("so", "そ");

  genericConversion.insert("za", "ざ");
  genericConversion.insert("zi", "じ");
  genericConversion.insert("zu", "ず");
  genericConversion.insert("ze", "ぜ");
  genericConversion.insert("zo", "ぞ");

  genericConversion.insert("ta", "た");
  genericConversion.insert("ti", "ち");
  genericConversion.insert("te", "て");
  genericConversion.insert("to", "と");

  genericConversion.insert("da", "だ");
  genericConversion.insert("di", "ぢ");
  genericConversion.insert("de", "で");
  genericConversion.insert("do", "ど");

  genericConversion.insert("na", "な");
  genericConversion.insert("ni", "に");
  genericConversion.insert("nu", "ぬ");
  genericConversion.insert("ne", "ね");
  genericConversion.insert("no", "の");

  genericConversion.insert("ha", "は");
  genericConversion.insert("hi", "ひ");
  genericConversion.insert("fu", "ふ");
  genericConversion.insert("he", "へ");
  genericConversion.insert("ho", "ほ");

  genericConversion.insert("ba", "ば");
  genericConversion.insert("bi", "び");
  genericConversion.insert("bu", "ぶ");
  genericConversion.insert("be", "べ");
  genericConversion.insert("bo", "ぼ");

  genericConversion.insert("pa", "ぱ");
  genericConversion.insert("pi", "ぴ");
  genericConversion.insert("pu", "ぷ");
  genericConversion.insert("pe", "ぺ");
  genericConversion.insert("po", "ぽ");

  genericConversion.insert("ma", "ま");
  genericConversion.insert("mi", "み");
  genericConversion.insert("mu", "む");
  genericConversion.insert("me", "め");
  genericConversion.insert("mo", "も");

  genericConversion.insert("ya", "や");
  genericConversion.insert("yu", "ゆ");
  genericConversion.insert("yo", "よ");

  genericConversion.insert("ra", "ら");
  genericConversion.insert("ri", "り");
  genericConversion.insert("ru", "る");
  genericConversion.insert("re", "れ");
  genericConversion.insert("ro", "ろ");

  genericConversion.insert("wa", "わ");

  vowelConversion.insert("a", "あ");
  vowelConversion.insert("e", "え");
  vowelConversion.insert("i", "い");
  vowelConversion.insert("o", "お");
  vowelConversion.insert("u", "う");

  consonantConversion.insert("n", "ん");			
  consonantConversion.insert("n'", "ん"); //allows for kanyuu -> かんゆう etc
  consonantConversion.insert("t", "っ");
  consonantConversion.insert("k", "っ");
  consonantConversion.insert("s", "っ");   
}

QString Convert::romajiToJapanese(QString value) {
  std::cout << "romajiToJapanese: " << value.toStdString() << std::endl;

  QHashIterator<QString, QString> i1(exactConversion);
  while(i1.hasNext()) {
    i1.next();
    QRegExp rx(i1.key());
    value.replace(rx, i1.value());
  }
  QHashIterator<QString, QString> i2(comboConversionSuffix);
  while(i2.hasNext()) {
    i2.next();
    QRegExp rx(i2.key());
    value.replace(rx, i2.value());
  }
  QHashIterator<QString, QString> i3(comboConversionPrefix);
  while(i3.hasNext()) {
    i3.next();
    QRegExp rx(i3.key());
    value.replace(rx, i3.value());
  }
  QHashIterator<QString, QString> i4(genericConversion);
  while(i4.hasNext()) {
    i4.next();
    QRegExp rx(i4.key());
    value.replace(rx, i4.value());
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
  std::cout << "romajiToJapanese: " << value.toStdString() << std::endl;

  return value;
}
