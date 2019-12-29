#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStateMachine>
#include <QHistoryState>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <QString>
#include <QDirIterator>

//#include "../../src/mainCompare2Files.cpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto stateMachine = new QStateMachine(this);

    auto SelectFile = new QState(stateMachine);
    auto PathSelected = new QState(stateMachine);
    auto Open = new QState(stateMachine);
    auto Error = new QState(stateMachine);
    auto Compare = new QState(stateMachine);
    auto ViewResult = new QState(stateMachine);

    SelectFile->assignProperty(ui->pbStart, "enabled", false);
    SelectFile->assignProperty(ui->pbSelect, "enabled", true);
    SelectFile->assignProperty(ui->tePath, "enabled", true);
    SelectFile->assignProperty(ui->tePath, "placeholderText", "No file selected...");

    connect(ui->pbSelect, SIGNAL(clicked()), this, SLOT(dialog()));
    SelectFile->addTransition(ui->tePath, SIGNAL(textChanged()), PathSelected);

    PathSelected->assignProperty(ui->pbStart, "enabled", true);
    PathSelected->assignProperty(ui->pbStart, "text", "START");
    PathSelected->assignProperty(ui->pbSelect, "enabled", true);

    PathSelected->addTransition(ui->pbStart, SIGNAL(clicked()), Open);

    connect(Open, SIGNAL(entered()), this, SLOT(open()));
    Open->assignProperty(ui->pbStart, "enabled", true);
    Open->assignProperty(ui->pbStart, "text", "START");
    Open->assignProperty(ui->pbSelect, "enabled", true);
    Open->addTransition(this, SIGNAL(opened()), Compare);
    Open->addTransition(this, SIGNAL(error()), Error);

    Error->assignProperty(ui->pbStart, "enabled", false);
    Error->assignProperty(ui->pbSelect, "enabled", true);
    //Error->assignProperty(ui->tePath, "placeholderText", "Wrong path or permissions!");
    Error->addTransition(ui->tePath, SIGNAL(textChanged()), PathSelected);

    Compare->assignProperty(ui->pbStart, "text", "CANCEL");
    Compare->assignProperty(ui->pbSelect, "enabled", false);
    connect(Compare, SIGNAL(entered()), this, SLOT(compare()));
    Compare->addTransition(ui->pbStart, SIGNAL(clicked()), PathSelected);
    Compare->addTransition(ui->tePath, SIGNAL(textChanged()), PathSelected);
    Compare->addTransition(ui->horizontalSlider, &QSlider::sliderReleased, Compare);
    Compare->addTransition(this, SIGNAL(done()), ViewResult);

    ViewResult->assignProperty(ui->pbStart, "enabled", false);
    ViewResult->assignProperty(ui->pbSelect, "enabled", true);
    ViewResult->assignProperty(ui->pbStart, "text", "DONE");
    ViewResult->addTransition(ui->tePath, SIGNAL(textChanged()), PathSelected);
    ViewResult->addTransition(ui->horizontalSlider, &QSlider::sliderReleased, Compare);




    stateMachine->setInitialState(SelectFile);

    stateMachine->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dialog()
{
    this->directoryName = QFileDialog::getExistingDirectory(this,
                                                  tr("Open file"), "..");
    ui->tePath->setPlainText(directoryName);
}

void MainWindow::open()
{
//    QDir dir(ui->tePath->toPlainText());
//    QStringList filesList = dir.entryList(QDir::Files | QDir::Readable, QDir::Type); // filtry na rozszerzenia: QStringList() << "*.cpp" << "*.txt",
//    for(QString fileName : filesList) {
//        fileName.prepend((dir.absolutePath()).append("/"));
//        QFile file(fileName);
//         qDebug() << fileName; // okazało się, że QDir::entryList() zbiera ścieżkę względną, wypisuję wczytane pliki do konsoli
//    }
    QDirIterator dirIter(ui->tePath->toPlainText(), QDir::Files | QDir::Readable, QDirIterator::Subdirectories);
    while(dirIter.hasNext())
    {
        QFile file(dirIter.next());
        qDebug() << dirIter.fileName();
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::information(this, tr("Error"), file.errorString());
            emit error();
            return;
        }

    }
    QMessageBox::information(this, tr("Success"), QString("File selected."));
    emit opened();
}

void MainWindow::compare()
{
    qDebug() << "Inside comparing function... please implement.";
    emit done();
}
