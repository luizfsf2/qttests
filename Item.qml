/* MyItem.qml */
import QtQuick 2.5

Rectangle {
    id: top
    property string str: "#FF0000"
    color: str
    width: 10
    height: 20
    Component.onCompleted: console.log("myitem ctor", width, height, x, y, visible, color);
}
