/********************************************************************************
** Form generated from reading UI file 'compiler.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPILER_H
#define UI_COMPILER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CompilerClass
{
public:
    QWidget *centralWidget;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QTextEdit *textEdit;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QTextEdit *textEdit_2;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CompilerClass)
    {
        if (CompilerClass->objectName().isEmpty())
            CompilerClass->setObjectName(QStringLiteral("CompilerClass"));
        CompilerClass->resize(600, 400);
        centralWidget = new QWidget(CompilerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(200, 130, 120, 80));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 118, 78));
        textEdit = new QTextEdit(scrollAreaWidgetContents);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(0, 0, 104, 71));
        scrollArea_2 = new QScrollArea(scrollAreaWidgetContents);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(0, 0, 120, 80));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 118, 78));
        textEdit_2 = new QTextEdit(scrollAreaWidgetContents_2);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(0, 0, 104, 71));
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);
        scrollArea->setWidget(scrollAreaWidgetContents);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(210, 30, 75, 23));
        CompilerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CompilerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        CompilerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CompilerClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        CompilerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CompilerClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CompilerClass->setStatusBar(statusBar);

        retranslateUi(CompilerClass);

        QMetaObject::connectSlotsByName(CompilerClass);
    } // setupUi

    void retranslateUi(QMainWindow *CompilerClass)
    {
        CompilerClass->setWindowTitle(QApplication::translate("CompilerClass", "Compiler", 0));
        pushButton->setText(QApplication::translate("CompilerClass", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class CompilerClass: public Ui_CompilerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPILER_H
