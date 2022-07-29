import QtQuick 2.0

Component {
    id: userListElem

    Rectangle {
        id: userListElem
        width: userListElem.width
        height: userListElem.height
        color: userListElem.color
        Row{
            spacing: rowSpacing
            Text {
                text: model.UID
                color: "black"
            }
            Text {
                text: model.GID
                color: "black"
            }
            Text {
                text: model.RegistratorName
                color: "black"
            }
            Text {
                text: model.FullName
                color: "black"
            }
            Text {
                text: model.HomeDir
                color: "black"
            }
            Text {
                text: model.LoginEngine
                color: "black"
            }
        }
        MouseArea
        {
            anchors.fill: parent
            onClicked:
            {
                //userList.currentIndex = index
                itemClicked();
            }
        }
    }
}
