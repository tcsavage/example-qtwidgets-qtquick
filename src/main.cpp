#include <QApplication>

#include "Window.h"

int main(int argc, char* argv[]) {
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QApplication app(argc, argv);

    Window window;
    window.show();

	return app.exec();
}
