#include "ColorPicker.h"

#include <QQmlProperty>
#include <QQuickItem>
#include <QStackedLayout>

ColorPicker::ColorPicker(QWidget* parent) : QWidget(parent) {
    setLayout(new QStackedLayout());
    qquickWidget = new QQuickWidget();
    layout()->addWidget(qquickWidget);
    qquickWidget->setSource(QUrl(QStringLiteral("qrc:/ColorPicker.qml")));
    qquickWidget->show();

    connect(qquickWidget->rootObject(), SIGNAL(colorChanged()), this, SLOT(updateColor()));
}

void ColorPicker::setLightness(qreal lightness) {
    QQmlProperty p(qquickWidget->rootObject(), QStringLiteral("lightness"));
    p.write(QVariant(lightness));
}

void ColorPicker::selectPreset(QString colorName) {
    QVariant returnedValue;
    QMetaObject::invokeMethod(
        qquickWidget->rootObject(),
        "selectPreset",
        Q_RETURN_ARG(QVariant, returnedValue),
        Q_ARG(QVariant, QVariant(colorName))
    );
}

void ColorPicker::updateColor() {
    QQmlProperty h(qquickWidget->rootObject(), QStringLiteral("hue"));
    QQmlProperty s(qquickWidget->rootObject(), QStringLiteral("saturation"));
    QQmlProperty l(qquickWidget->rootObject(), QStringLiteral("lightness"));

    auto color = QColor::fromHslF(
        h.read().toReal(),
        s.read().toReal(),
        l.read().toReal()
    );

    colorChanged(color);
}
