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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CompilerClass
{
public:
    QAction *actionRun;
    QAction *actionExit;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_3;
    QPlainTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *textEdit_2;
    QMenuBar *menuBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *CompilerClass)
    {
        if (CompilerClass->objectName().isEmpty())
            CompilerClass->setObjectName(QStringLiteral("CompilerClass"));
        CompilerClass->resize(977, 781);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Compiler/Icons/Rocket.png"), QSize(), QIcon::Normal, QIcon::Off);
        CompilerClass->setWindowIcon(icon);
        actionRun = new QAction(CompilerClass);
        actionRun->setObjectName(QStringLiteral("actionRun"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Compiler/Icons/Run.gif"), QSize(), QIcon::Normal, QIcon::Off);
        actionRun->setIcon(icon1);
        actionExit = new QAction(CompilerClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionExit->setCheckable(true);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Compiler/Icons/Close.gif"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon2);
        centralWidget = new QWidget(CompilerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        scrollArea = new QScrollArea(groupBox);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 937, 328));
        horizontalLayout_3 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        textEdit = new QPlainTextEdit(scrollAreaWidgetContents);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        horizontalLayout_3->addWidget(textEdit);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));

        verticalLayout_2->addLayout(horizontalLayout);

        scrollArea_2 = new QScrollArea(groupBox);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 937, 328));
        horizontalLayout_2 = new QHBoxLayout(scrollAreaWidgetContents_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        textEdit_2 = new QTextEdit(scrollAreaWidgetContents_2);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));

        horizontalLayout_2->addWidget(textEdit_2);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_2->addWidget(scrollArea_2);


        verticalLayout->addWidget(groupBox);

        CompilerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CompilerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 977, 23));
        CompilerClass->setMenuBar(menuBar);
        toolBar = new QToolBar(CompilerClass);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        CompilerClass->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actionRun);
        toolBar->addSeparator();
        toolBar->addAction(actionExit);

        retranslateUi(CompilerClass);

        QMetaObject::connectSlotsByName(CompilerClass);
    } // setupUi

    void retranslateUi(QMainWindow *CompilerClass)
    {
        CompilerClass->setWindowTitle(QApplication::translate("CompilerClass", "Compiler", 0));
        actionRun->setText(QApplication::translate("CompilerClass", "run", 0));
#ifndef QT_NO_TOOLTIP
        actionRun->setToolTip(QApplication::translate("CompilerClass", "run", 0));
#endif // QT_NO_TOOLTIP
        actionRun->setShortcut(QApplication::translate("CompilerClass", "Ctrl+R", 0));
        actionExit->setText(QApplication::translate("CompilerClass", "Exit", 0));
#ifndef QT_NO_TOOLTIP
        actionExit->setToolTip(QApplication::translate("CompilerClass", "Exit", 0));
#endif // QT_NO_TOOLTIP
        actionExit->setShortcut(QApplication::translate("CompilerClass", "Esc", 0));
        groupBox->setTitle(QApplication::translate("CompilerClass", "CODE", 0));
        toolBar->setWindowTitle(QApplication::translate("CompilerClass", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class CompilerClass: public Ui_CompilerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPILER_H
