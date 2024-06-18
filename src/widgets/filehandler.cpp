#include "include/widgets/filehandler.h"
#include <QFileDialog>
#include <QDebug>

FileHandler::FileHandler(QObject *parent): QObject(parent){

} 

QString FileHandler::getFileName() const
{
	return m_fileName;
}

void FileHandler::setFileName(const QString &fileName)
{
	if (fileName != m_fileName) {
		m_fileName = fileName;
		emit fileNameChanged(m_fileName); 
	}
}

void FileHandler::openFile(){
	QString fileName = QFileDialog::getOpenFileName(nullptr,
		tr("Открыть файл"), "",
		tr("Все файлы (*)"));

	if (!fileName.isEmpty()) {
		qDebug() << "Выбран файл:" << fileName;
		setFileName(fileName);
		// Здесь можно добавить дальнейшую логику работы с выбранным файлом
	}
}

void FileHandler::openFolder(){
	QString directory = QFileDialog::getExistingDirectory(nullptr,
		tr("Выбрать папку"), "",
		QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

	if (!directory.isEmpty()) {
		qDebug() << "Выбрана папка:" << directory;
		setFileName(directory);
		// Дополнительная логика работы с выбранной папкой
	}
}
