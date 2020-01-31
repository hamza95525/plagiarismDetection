#include "differencewindow.h"
#include "ui_differencewindow.h"

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

void DifferenceWindow::setFileLabels(std::string p1, std::string p2)
{
    ui->file1Name->setText(QString::fromStdString(p1));
    ui->file2Name->setText(QString::fromStdString(p2));
}
