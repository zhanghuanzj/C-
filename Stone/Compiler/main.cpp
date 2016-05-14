#include "compiler.h"
#include <QtWidgets/QApplication>
#include <QTextStream> 

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
/*	QTextStream cin(stdin, QIODevice::ReadOnly);   
	QTextStream cout(stdout, QIODevice::WriteOnly);   */ 
	cout<<"JLFKDJKFSL"<<endl;
	Compiler w;
	w.show();
	return a.exec();

}
