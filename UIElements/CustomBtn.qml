import QtQuick 2.0
import QtQuick.Controls 2.15

Button {
    id: btn
    //property int btnWidth: 100
    //property int btnHeight: 100
    //property string text: "btn"
    background: Rectangle {
                implicitWidth: 100
                implicitHeight: 40
                opacity: enabled ? 1 : 0.3
                color: btn.down ? Qt.darker("lightgray", 0.95) : "lightgray"
                //color: btn.down ? "lightblue" : "lightgray"
                //border.color: control.down ? "#17a81a" : "#21be2b"
                //border.width: 1
                radius: 2
            }
    //width: btn.btnWidth
    //height: btn.btnHeight
    //text: text
}
