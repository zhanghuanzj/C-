#include "compiler.h"

Compiler::Compiler(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	/*QObject::connect(ui.pushButton,SIGNAL(clicked()),this,SLOT(print()));
	QObject::connect(ui,SIGNAL(clicked()),this,SLOT(print()));*/
	QObject::connect(ui.actionExit,SIGNAL(triggered()),this,SLOT(exit()));
}

Compiler::~Compiler()
{

}

void Compiler::print()
{
	cout<<"JLKFDJ"<<endl;
}

void Compiler::exit()
{
	setWindowTitle("JFKDLJ");
	::exit(0);
}
