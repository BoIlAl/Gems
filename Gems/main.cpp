#include "Gems.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
		Gems w;
		w.show();
    return a.exec();
}
