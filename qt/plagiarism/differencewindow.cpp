#include "differencewindow.h"
#include "ui_differencewindow.h"
#include <QFileDialog>
#include <QTextStream>

DifferenceWindow::DifferenceWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DifferenceWindow)
{
    ui->setupUi(this);
}

DifferenceWindow::~DifferenceWindow()
{
    delete ui;
}

void DifferenceWindow::on_pushButton_clicked()
{
    this->hide();
}

void DifferenceWindow::setProjectLabels(std::string l1, std::string l2)
{
    this->show();
    ui->project1Name->setText(QString::fromStdString(l1));
    ui->project2Name->setText(QString::fromStdString(l2));
}

void DifferenceWindow::setFileContentAndLabels(std::string p1, std::string p2)
{
    //----------displaying content
    QFile file(QString::fromStdString(p1));
    file.open( QIODevice::ReadWrite );
    QString line;
    QTextStream stream(&file);
    while (!stream.atEnd())
      line.append(stream.readLine()+"\n");
    ui->textEdit->setText(line);

    QFile file1(QString::fromStdString(p2));
    file1.open( QIODevice::ReadWrite );
    QString line1;
    QTextStream stream1(&file1);
    while (!stream1.atEnd())
      line1.append(stream1.readLine()+"\n");
    ui->textEdit_2->setText(line1);


    ui->file1Name->setText(QString::fromStdString(p1));
    ui->file2Name->setText(QString::fromStdString(p2));
}
