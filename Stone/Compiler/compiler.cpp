#include "compiler.h"

Compiler::Compiler(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	/*QObject::connect(ui.pushButton,SIGNAL(clicked()),this,SLOT(print()));
	QObject::connect(ui,SIGNAL(clicked()),this,SLOT(print()));*/
	QObject::connect(ui.pb_Cancel,SIGNAL(clicked()),this,SLOT(exit()));
}

Compiler::~Compiler()
{

}

void Compiler::print()
{
}

void Compiler::exit()
{
	::exit(0);
}
