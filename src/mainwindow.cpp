#include "include/mainwindow.h"
#include "ui_mainwindow.h"
#include "include/widgets/filehandler.h"

#include <QMessageBox>
#include <QLineEdit>
#include <QDebug>
#include <QFileInfo>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	// Создаем экземпляр класса FileHandler
	fileHandler = new FileHandler(this);

	// Подключаем действие "Открыть" к методу openFile у FileHandler
	connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::openFileHandler);
	
	// Подключаем действие "Выбрать папку" к методу openFolder у FileHandler
	connect(ui->actionSelectFolder, &QAction::triggered, this, &MainWindow::openFolderHandler);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::openWinFile(FileHandler *handler)
{

	QString fileName = handler->getFileName(); // Получаем имя файла через метод getFileName()
	if (!fileName.isEmpty()) {

		QFileInfo fileInfo(fileName);
		QString extension = fileInfo.suffix().toLower();
		
		if (extension == "xml" || extension == "json") {
				QTextEdit *logTextEdit = findChild<QTextEdit*>("logTextEdit");
				
				if (logTextEdit) {
					logTextEdit->setText(fileName);
				} 
				else {
					qDebug() << "QTextEdit с именем 'logTextEdit' не найден!";
				}
		} else {
				qDebug() << "Выбранный файл не является XML или JSON файлом.";
		}
	}
}

void MainWindow::openWinFolder(FileHandler *handler)
{

	QString fileName = handler->getFileName(); // Получаем имя файла через метод getFileName()
	QLineEdit *lineEdit = findChild<QLineEdit*>("lineEdit");

	if (lineEdit) {
		lineEdit->setText(fileName);
	} else {
		qDebug() << "QLineEdit с именем 'lineEdit' не найден!";
	}
}

void MainWindow::openFileHandler()
{
	fileHandler->openFile();
	openWinFile(fileHandler);
}

void MainWindow::openFolderHandler()
{
	fileHandler->openFolder();
	openWinFolder(fileHandler);
}
