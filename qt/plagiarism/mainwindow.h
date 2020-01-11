#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void viewResults();

signals:
    void error();
    void done();

public slots:
    void dialog();
    void open();
    double compare(std::string, std::string);

private:
    Ui::MainWindow *ui;
    QString directoryName;
    std::vector <std::vector <std::string>> allProjects;
};

#endif // MAINWINDOW_H
