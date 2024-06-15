#include "include/mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_fileOpened(false)
    , m_folderSelected(false) // Инициализация флага
{
    ui->setupUi(this);

    // Подключаем сигнал от действия "Выбрать папку" к слоту
    connect(ui->actionSelectFolder, &QAction::triggered, this, &MainWindow::on_actionSelectFolder_triggered);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open XML File"), QString(),
                                                    tr("XML Files (*.xml)"));

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QFile::ReadOnly | QFile::Text)) {
            QMessageBox::warning(this, tr("Error"), tr("Cannot read file %1:\n%2.")
                                 .arg(QDir::toNativeSeparators(fileName),
                                      file.errorString()));
            return;
        }

        // Check if the file has an XML extension
        if (!fileName.endsWith(".xml", Qt::CaseInsensitive)) {
            QMessageBox::warning(this, tr("Error"), tr("The selected file is not in XML format."));
            return;
        }

        QTextStream in(&file);
        QString xmlText = in.readAll();
        file.close();

        // Clear logTextEdit before appending new text
        ui->logTextEdit->clear();

        // Append to logTextEdit
        appendToLog(tr("Opened file: ") + fileName);

        // Update current file
        m_currentFile = fileName;
        m_fileOpened = true;

        // Установка флага на false после выбора файла
        m_folderSelected = false;
    }
}

void MainWindow::on_actionSelectFolder_triggered()
{
    if (m_folderSelected) {
        // Если папка уже выбрана, не открываем диалоговое окно повторно
        return;
    }

    QString folderPath = QFileDialog::getExistingDirectory(this, tr("Select Directory"),
                                                          QString(),
                                                          QFileDialog::ShowDirsOnly
                                                          | QFileDialog::DontResolveSymlinks);
    if (!folderPath.isEmpty()) {
        ui->lineEdit->setText(folderPath);
        appendToLog(tr("Selected folder: ") + folderPath);

        // Установка флага на true после выбора папки
        m_folderSelected = true;

        // Сброс флага открытого файла, если нужно
        m_fileOpened = false;
    }
}

void MainWindow::appendToLog(const QString &text)
{
    ui->logTextEdit->moveCursor(QTextCursor::End);
    ui->logTextEdit->insertPlainText(text + "\n");
}

