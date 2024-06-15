// #include "include/xmljsonconverter.h"
// #include <QXmlStreamReader>
// #include <QXmlStreamWriter>
//
// XmlJsonConverter::XmlJsonConverter(QObject *parent) : QObject(parent)
// {
//
// }
//
// bool XmlJsonConverter::xmlToJson(const QString &xmlString, QJsonObject &jsonObject)
// {
//     return parseXmlToJsonObject(xmlString, jsonObject);
// }
//
// bool XmlJsonConverter::jsonToXml(const QJsonObject &jsonObject, QString &xmlString)
// {
//     return buildXmlFromJsonObject(jsonObject, xmlString);
// }
//
// bool XmlJsonConverter::parseXmlToJsonObject(const QString &xmlString, QJsonObject &jsonObject)
// {
//     QXmlStreamReader xml(xmlString);
//
//     while (!xml.atEnd() && !xml.hasError()) {
//         QXmlStreamReader::TokenType token = xml.readNext();
//
//         if (token == QXmlStreamReader::StartElement) {
//             QJsonObject obj;
//             obj["name"] = xml.name().toString();
//
//             QXmlStreamAttributes attributes = xml.attributes();
//             for (int i = 0; i < attributes.size(); ++i) {
//                 obj[attributes.at(i).name().toString()] = attributes.at(i).value().toString();
//             }
//
//             if (!xml.isEndElement()) {
//                 xml.readNext();
//                 if (xml.tokenType() == QXmlStreamReader::Characters) {
//                     obj["value"] = xml.text().toString();
//                 }
//             }
//
//             QString key = xml.name().toString();
//             jsonObject[key] = obj;
//         }
//     }
//
//     if (xml.hasError()) {
//         qDebug() << "XML Error:" << xml.errorString();
//         return false;
//     }
//
//     return true;
// }
//
// bool XmlJsonConverter::buildXmlFromJsonObject(const QJsonObject &jsonObject, QString &xmlString)
// {
//     QXmlStreamWriter xml;
//     xml.setAutoFormatting(true);
//     xml.writeStartDocument();
//     xml.writeStartElement("root");
//
//     QStringList keys = jsonObject.keys();
//     foreach (const QString &key, keys) {
//         QJsonValue value = jsonObject.value(key);
//         if (value.isObject()) {
//             xml.writeStartElement(value.toObject()["name"].toString());
//             QJsonObject obj = value.toObject();
//             obj.remove("name");
//             QStringList objKeys = obj.keys();
//             foreach (const QString &objKey, objKeys) {
//                 xml.writeAttribute(objKey, obj.value(objKey).toString());
//             }
//             xml.writeEndElement();
//         } else {
//             xml.writeTextElement(key, value.toString());
//         }
//     }
//
//     xml.writeEndDocument();
//     xmlString = xml.device()->readAll();
//     return true;
// }
//
