#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "include/widgets/filehandler.h"

#include <QMainWindow>


namespace Ui {
	class MainWindow;
}

class MainWindow: public QMainWindow {
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private:
	Ui::MainWindow *ui;
	FileHandler *fileHandler;

public:
	void openWinFolder(FileHandler *handler);
	void openWinFile(FileHandler *handler);
	void openFileHandler();
	void openFolderHandler();
};



#endif // MAINWINDOW_H
