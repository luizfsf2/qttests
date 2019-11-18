/* main.qml */
import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    visible: true
    id: root

    MouseArea {
        id: mouse
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }
    }

    Text {
        id: text
        text: qsTr("Hello World")
        anchors.centerIn: parent
    }
}
