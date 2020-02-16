#include "Window.h"

#include <QPushButton>
#include <QSlider>
#include <QVBoxLayout>

#include "ColorPicker.h"

Window::Window(QWidget* parent)
    : QWidget(parent)
    , _palette(palette()) {
    setLayout(new QVBoxLayout());
    
    auto colorPicker = new ColorPicker();
    layout()->addWidget(colorPicker);

    auto slider = new QSlider(Qt::Orientation::Horizontal);
    layout()->addWidget(slider);
    slider->setMinimum(0);
    slider->setMaximum(255);

    auto greenButton = new QPushButton("Make it green!");
    layout()->addWidget(greenButton);
    auto purpleButton = new QPushButton("Make it purple!");
    layout()->addWidget(purpleButton);

    connect(slider, &QSlider::valueChanged, this, [=](auto value) {
        colorPicker->setLightness((qreal)value / 255.0f);
    });

    connect(colorPicker, &ColorPicker::colorChanged, this, [=](auto color){
        _palette.setColor(backgroundRole(), color);
        setPalette(_palette);
    });

    connect(greenButton, &QPushButton::clicked, this, [=]{
        colorPicker->selectPreset("green");
    });

    connect(purpleButton, &QPushButton::clicked, this, [=]{
        colorPicker->selectPreset("purple");
    });
}
