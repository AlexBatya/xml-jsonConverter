#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();
    void on_actionSelectFolder_triggered(); // Новый слот для выбора папки

private:
    Ui::MainWindow *ui;
    bool m_fileOpened; // Флаг открытого файла
    bool m_folderSelected; // Флаг выбранной папки
    QString m_currentFile; // Путь к текущему файлу

    void appendToLog(const QString &text);
};

#endif // MAINWINDOW_H

