#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <QObject>

class FileHandler: public QObject{
	Q_OBJECT
	Q_PROPERTY(QString fileName READ getFileName WRITE setFileName NOTIFY fileNameChanged)

public:
	explicit FileHandler(QObject *parent = nullptr);

	QString getFileName() const; 
	void setFileName(const QString &fileName); 

signals:
	void fileNameChanged(const QString &fileName); // Сигнал об изменении fileName

public slots: 
	void openFile();
	void openFolder();

private: 
	QString m_fileName; // Приватное поле для хранения имени файла
	
};


#endif
