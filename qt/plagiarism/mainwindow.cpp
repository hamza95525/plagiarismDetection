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
    // auto Open = new QState(stateMachine);
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

    PathSelected->addTransition(ui->pbStart, SIGNAL(clicked()), Compare);

//    Open->assignProperty(ui->pbStart, "enabled", true);
//    Open->assignProperty(ui->pbStart, "text", "START");
//    Open->assignProperty(ui->pbSelect, "enabled", true);
//    Open->addTransition(this, SIGNAL(opened()), Compare);

    connect(Compare, SIGNAL(entered()), this, SLOT(open()));
    Compare->assignProperty(ui->pbStart, "text", "CANCEL");
    Compare->assignProperty(ui->pbSelect, "enabled", false);
    //connect(Compare, SIGNAL(entered()), this, SLOT(compare()));
    Compare->addTransition(ui->pbStart, SIGNAL(clicked()), PathSelected);
    Compare->addTransition(ui->tePath, SIGNAL(textChanged()), PathSelected);
    Compare->addTransition(ui->horizontalSlider, &QSlider::sliderReleased, Compare);
    Compare->addTransition(this, SIGNAL(done()), ViewResult);    
    Compare->addTransition(this, SIGNAL(error()), Error);

    Error->assignProperty(ui->pbStart, "enabled", false);
    Error->assignProperty(ui->pbSelect, "enabled", true);
    Error->addTransition(ui->tePath, SIGNAL(textChanged()), PathSelected);

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
    this->directoryName = QFileDialog::getExistingDirectory(this, tr("Open file"), "..");
    ui->tePath->setPlainText(directoryName);
}

void MainWindow::open()
{
    /*  QDir dir(ui->tePath->toPlainText());
        QStringList filesList = dir.entryList(QDir::Files | QDir::Readable, QDir::Type); // filtry na rozszerzenia: QStringList() << "*.cpp" << "*.txt",
        for(QString fileName : filesList) {
        fileName.prepend((dir.absolutePath()).append("/"));
        QFile file(fileName);
        qDebug() << fileName; // okazało się, że QDir::entryList() zbiera ścieżkę względną, wypisuję wczytane pliki do konsoli}
    */

    // CHECK IF DIRECTORY EXISTS

    QDirIterator dirIter(ui->tePath->toPlainText(), QDir::Files | QDir::Readable, QDirIterator::Subdirectories);
    QDir dir(ui->tePath->toPlainText());
    if (dir.exists()==0)
    {
        QMessageBox::information(this, tr("Error"), "Directory doesn't exist.");
        emit error();
        return;
    }

    // EXTRACT (ALL) NAME FILES

     std::vector <std::string> allPaths; // wszystkie pliki dodanego projektu
    // QStringList allPaths;

    while(dirIter.hasNext())
    {
        QFile file(dirIter.next());
        // qDebug() << dirIter.filePath();
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::information(this, tr("Error"), file.errorString());
            emit error();
            return;
        }
        else {
            // compare();
            // add file to the table
            //allPaths.append(dirIter.filePath, );
            allPaths.push_back(dirIter.filePath().toStdString());
            file.close();
        }
    }

    allProjects.push_back(allPaths); // add to database of projects

    // Teraz co tu ma się . to ja nie wiem
    // Każdy plik z każdego projektu porównaj z każdym plikiem każdego projektu
    // plik -> tablica plików projektu -> tablica wszystkich projektów

    std::vector <std::vector <std::vector <std::vector <double>>>> allResults;  // all results of comparing 2 files

    for(unsigned long a=0;a<allProjects.size(); a++)
    {
        for(unsigned long b=0;b<allProjects.size(); b++)
        {
            if(a!=b) // round-robin for projects
            {
                for(unsigned long i=0;i<allProjects[a][i].size(); i++)
                {
                    for(unsigned long j=0;j<allProjects[b][j].size(); j++)
                    {
                        allResults[a][b][i][j] = compare(allProjects[a][i], allProjects[b][j]); // result of comparing file i with file j, in projects a and project b
                    }
                }
            }
        }
    }

    QMessageBox::information(this, tr("Success"), QString("Directory compared to database."));
    emit done();

}

double MainWindow::compare(std::string, std::string)
{
    qDebug() << "Inside comparing function... please implement.";
    return rand()/100;
}
