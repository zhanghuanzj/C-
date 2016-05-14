#ifndef COMPILER_H
#define COMPILER_H

#include <QtWidgets/QMainWindow>
#include "ui_compiler.h"
#include <QDebug>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Compiler : public QMainWindow
{
	Q_OBJECT

public:
	Compiler(QWidget *parent = 0);
	~Compiler();
private slots:
	void exit();
	void print();
private:
	Ui::CompilerClass ui;
};

#endif // COMPILER_H
