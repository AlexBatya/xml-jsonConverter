#include "include/mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QFile>
#include <QTextStream>
#include <QPropertyAnimation>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	MainWindow w;

	QTranslator translator;
	const QStringList uiLanguages = QLocale::system().uiLanguages();
	for (const QString &locale : uiLanguages) {
			const QString baseName = "xml-json_" + QLocale(locale).name();
			if (translator.load(":/i18n/" + baseName)) {
					a.installTranslator(&translator);
					break;
			}
	}

	QString stylesheet; // Объявление переменной для хранения стилей

	QFile file(":/style.qss");
	if (file.open(QFile::ReadOnly | QFile::Text)) {
			QTextStream stream(&file);
			stylesheet = stream.readAll(); // Запись стилей в переменную stylesheet
			a.setStyleSheet(stylesheet);
			file.close();
	}

	// Создание анимации для плавного изменения цвета
	QPropertyAnimation animation(&w, "styleSheet");
	animation.setDuration(500); // длительность анимации в миллисекундах (0.5 секунды)

	// Пример изменения цвета на немного ярче
	QString newStyleSheet = stylesheet;
	newStyleSheet.replace("rgba(0, 0, 0, 0.1)", "rgba(0, 0, 0, 0.3)");

	animation.setStartValue(stylesheet);
	animation.setEndValue(newStyleSheet);

	// Запуск анимации
	animation.start();

	w.show();
	return a.exec();
}

