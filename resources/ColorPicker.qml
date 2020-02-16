import QtQuick 2.12
import QtQuick.Controls 2.5

Item {
    id: root
    implicitWidth: 250
    implicitHeight: 250

    property real hue: 0
    property real saturation: 0
    property real lightness: 0.5

    signal colorChanged

    onHueChanged: colorChanged()
    onSaturationChanged: colorChanged()
    onLightnessChanged: colorChanged()

    function selectPreset(colorName) {
        if (colorName === 'green') {
            root.hue = 0.4;
            root.saturation = 1.0
            root.lightness = 0.5
        } else if (colorName === 'purple') {
            root.hue = 0.8
            root.saturation = 1.0
            root.lightness = 0.5
        }
    }

    Rectangle {
        id: hueRect
        anchors.fill: parent
        gradient: Gradient {
            orientation: Gradient.Horizontal
            GradientStop { position: 0.0; color: Qt.hsla(0.0, 1.0, root.lightness) }
            GradientStop { position: 0.2; color: Qt.hsla(0.2, 1.0, root.lightness) }
            GradientStop { position: 0.4; color: Qt.hsla(0.4, 1.0, root.lightness) }
            GradientStop { position: 0.6; color: Qt.hsla(0.6, 1.0, root.lightness) }
            GradientStop { position: 0.8; color: Qt.hsla(0.8, 1.0, root.lightness) }
            GradientStop { position: 1.0; color: Qt.hsla(1.0, 1.0, root.lightness) }
        }
    }

    Rectangle {
        id: satRect
        anchors.fill: parent
        gradient: Gradient {
            orientation: Gradient.Vertical
            GradientStop { position: 0.0; color: Qt.hsla(0.0, 0.0, root.lightness, 1.0) }
            GradientStop { position: 1.0; color: Qt.hsla(0.0, 0.0, root.lightness, 0.0) }
        }
    }

    Rectangle {
        id: handle
        width: 10; height: 10
        color: 'transparent'
        radius: 5
        border.color: 'black'
        border.width: 2
        x: root.hue * root.width - width / 2
        y: root.saturation * root.height - height / 2
    }

    MouseArea {
        anchors.fill: parent
        onPressed: {
            root.hue = mouse.x / root.width
            root.saturation = mouse.y / root.height
        }
        onPositionChanged: {
            root.hue = Math.max(0, Math.min(1, mouse.x / root.width))
            root.saturation = Math.max(0, Math.min(1, mouse.y / root.height))
        }
    }

}
