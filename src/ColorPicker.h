#pragma once

#include <QColor>
#include <QQuickWidget>
#include <QWidget>

class ColorPicker : public QWidget {
    Q_OBJECT

public:
    ColorPicker(QWidget* parent = nullptr);

    void setLightness(qreal lightness);

    void selectPreset(QString colorName);

signals:
    void colorChanged(QColor color);

protected slots:
    void updateColor();

private:
    QQuickWidget* qquickWidget;
};
