#ifndef DIFFERENCEWINDOW_H
#define DIFFERENCEWINDOW_H

#include <QDialog>

namespace Ui {
class DifferenceWindow;
}

class DifferenceWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DifferenceWindow(QWidget *parent = nullptr);
    ~DifferenceWindow();

private slots:
    void on_pushButton_clicked();
    void setProjectLabels(std::string l1, std::string l2);
    void setFileLabels(std::string p1, std::string p2);

private:
    Ui::DifferenceWindow *ui;
};

#endif // DIFFERENCEWINDOW_H
