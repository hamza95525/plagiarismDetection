/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QTableWidget *tableWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pbSelect;
    QTextEdit *tePath;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLCDNumber *lcdNumber;
    QSlider *horizontalSlider;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_4;
    QCheckBox *cbAlgo;
    QCheckBox *cbAlgo_2;
    QLabel *label_5;
    QCheckBox *cbAlgo_3;
    QCheckBox *cbAlgo_4;
    QPushButton *pbStart;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 600);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(9, 9, 731, 581));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tableWidget = new QTableWidget(gridLayoutWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        gridLayout->addWidget(tableWidget, 0, 0, 1, 1);

        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(750, 9, 269, 421));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pbSelect = new QPushButton(verticalLayoutWidget);
        pbSelect->setObjectName(QString::fromUtf8("pbSelect"));

        verticalLayout->addWidget(pbSelect);

        tePath = new QTextEdit(verticalLayoutWidget);
        tePath->setObjectName(QString::fromUtf8("tePath"));

        verticalLayout->addWidget(tePath);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, -1, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        lcdNumber = new QLCDNumber(verticalLayoutWidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setProperty("intValue", QVariant(20));

        horizontalLayout_2->addWidget(lcdNumber);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalSlider = new QSlider(verticalLayoutWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setMaximum(100);
        horizontalSlider->setValue(20);
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2, 0, Qt::AlignRight);


        verticalLayout->addLayout(horizontalLayout);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        cbAlgo = new QCheckBox(verticalLayoutWidget);
        cbAlgo->setObjectName(QString::fromUtf8("cbAlgo"));
        cbAlgo->setCheckable(true);
        cbAlgo->setChecked(true);
        cbAlgo->setAutoRepeat(false);
        cbAlgo->setTristate(false);

        verticalLayout->addWidget(cbAlgo);

        cbAlgo_2 = new QCheckBox(verticalLayoutWidget);
        cbAlgo_2->setObjectName(QString::fromUtf8("cbAlgo_2"));

        verticalLayout->addWidget(cbAlgo_2);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        cbAlgo_3 = new QCheckBox(verticalLayoutWidget);
        cbAlgo_3->setObjectName(QString::fromUtf8("cbAlgo_3"));

        verticalLayout->addWidget(cbAlgo_3);

        cbAlgo_4 = new QCheckBox(verticalLayoutWidget);
        cbAlgo_4->setObjectName(QString::fromUtf8("cbAlgo_4"));

        verticalLayout->addWidget(cbAlgo_4);

        pbStart = new QPushButton(verticalLayoutWidget);
        pbStart->setObjectName(QString::fromUtf8("pbStart"));

        verticalLayout->addWidget(pbStart);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), lcdNumber, SLOT(display(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Is it stolen?", nullptr));
        pbSelect->setText(QApplication::translate("MainWindow", "Select file", nullptr));
        label->setText(QApplication::translate("MainWindow", "Set up percentage:", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "0%", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "100%", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Algorithms to use:", nullptr));
        cbAlgo->setText(QApplication::translate("MainWindow", "Line by line comparison", nullptr));
        cbAlgo_2->setText(QApplication::translate("MainWindow", "Compare unique lines", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Algorithms above works only with c/cpp", nullptr));
        cbAlgo_3->setText(QApplication::translate("MainWindow", "Ratio between number of keywords", nullptr));
        cbAlgo_4->setText(QApplication::translate("MainWindow", "Lexycal analyzer", nullptr));
        pbStart->setText(QApplication::translate("MainWindow", "START", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
