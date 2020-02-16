#pragma once

#include <QPalette>
#include <QWidget>

class Window : public QWidget {
    Q_OBJECT
public:
    Window(QWidget* parent = nullptr);

private:
    QPalette _palette;
};
