/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineIpAdress;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *getImg;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QMenu *menuSend_Photo;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(500, 180);
        MainWindow->setMinimumSize(QSize(500, 180));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(80, 20));
        label->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineIpAdress = new QLineEdit(centralWidget);
        lineIpAdress->setObjectName(QStringLiteral("lineIpAdress"));
        lineIpAdress->setMinimumSize(QSize(100, 20));
        lineIpAdress->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(lineIpAdress, 0, 1, 1, 1);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(100, 20));
        pushButton_2->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(pushButton_2, 0, 3, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(80, 20));
        label_2->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(100, 20));
        lineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(lineEdit, 1, 1, 1, 1);

        getImg = new QPushButton(centralWidget);
        getImg->setObjectName(QStringLiteral("getImg"));
        getImg->setMinimumSize(QSize(20, 20));
        getImg->setMaximumSize(QSize(20, 16777215));

        gridLayout->addWidget(getImg, 1, 2, 1, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(100, 20));
        pushButton->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(pushButton, 1, 3, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 500, 17));
        menuSend_Photo = new QMenu(menuBar);
        menuSend_Photo->setObjectName(QStringLiteral("menuSend_Photo"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuSend_Photo->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\236\321\202\320\277\321\200\320\260\320\262\320\273\321\217\320\265\320\274 \320\272\320\260\321\200\321\202\320\270\320\275\320\272\320\270", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "IP-\320\260\320\264\321\200\320\265\321\201 \321\201\320\265\321\200\320\262\320\265\321\200\320\260:", Q_NULLPTR));
        lineIpAdress->setText(QApplication::translate("MainWindow", "127.0.0.1", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214\321\201\321\217", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\320\237\321\203\321\202\321\214 \320\272 \320\272\320\260\321\200\321\202\320\270\320\275\320\272\320\265:", Q_NULLPTR));
        getImg->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214", Q_NULLPTR));
        menuSend_Photo->setTitle(QApplication::translate("MainWindow", "\320\232\320\273\320\270\320\265\320\275\321\202", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
