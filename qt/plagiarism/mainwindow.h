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
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void error();
    void opened();
    void done();

public slots:
    void dialog();
    void open();
    void compare();

private:
    Ui::MainWindow *ui;
    QString directoryName;
};

#endif // MAINWINDOW_H
