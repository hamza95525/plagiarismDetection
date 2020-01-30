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
    std::string getFileExtension(const std::string &s);
    //void averageValuesForProjects();
signals:
    void error();
    void done();
public slots:
    void dialog();
    void open();
    double compare(std::string, std::string,int);
    void clear();
    void viewTable();
    void diff( );
private:
    Ui::MainWindow *ui;
    QString directoryName;
    int algorithmsUsed=0x00;
    int numberOfAlgorithmsUsed=0;
    void averageValuesForProjects();
    std::vector <std::vector <std::string>> allProjects;
    std::vector <std::vector <std::vector <std::vector <double>>>> allResults;
    std::vector <std::vector <double>> allProjectsResults;
    std::vector <std::vector <std::vector<std::string>>> allProcetsMaxFileResults;
    std::vector <std::string> ProjectNames;
    std::vector <std::string> allPaths;
};
#endif // MAINWINDOW_H
