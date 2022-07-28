import QtQuick 2.0
import QtQuick.Controls 2.15
TabButton {
    id: tabBtn
    //width: customTabBtn.width
    //implicitWidth: customTabBtn.width
    //text: customTabBtn.text
    //height: customTabBtn.height

    background: Rectangle {
            implicitWidth: tabBtn.width
            implicitHeight: tabBtn.height
            color: tabBtn.checked ? "lightblue" : "lightgray"
            //opacity: enabled ? 1 : 0.3
            //border.color: control.down ? "#17a81a" : "#21be2b"
            //border.width: 1
            radius: 2
        }
    contentItem: Text {
            text: tabBtn.text
            font: tabBtn.font
            //opacity: enabled ? 1.0 : 0.3
            color: tabBtn.down ? "black" : "black"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            elide: Text.ElideRight
        }
}
