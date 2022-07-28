import QtQuick 2.15
import QtQuick.Window 2.15 
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3

//import LocalUser 1.0
//import LocalUserListModel 1.0
//import modelu 1.0
import "./UIElements"


Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("User manager")
    color:  "#eeeeee"
    //    onClosing: {
    //        close.accepted = false
    //        closed(window)
    //    }

    MenuBar {
        id: menu
        //height: 25
        //contentHeight: 25
        //implicitContentHeight: 25
        anchors.top: parent.top
        anchors.left: parent.left
        //anchors.fill: parent
        background: Rectangle {
            color: "lightgray"
            width: window.width
            }
        //color: "black"
        //contentHeight: 20
        //anchors.margins: 10
        Menu {

            title: qsTr("&File")
            Action { text: qsTr("&New...") }
            Action { text: qsTr("&Open...") }
            Action { text: qsTr("&Save") }
            Action { text: qsTr("Save &As...") }
            MenuSeparator { }
            Action { text: qsTr("&Quit") }
        }
        Menu {
            title: qsTr("&User")
            Action { text: qsTr("Cu&t") }
            Action { text: qsTr("&Copy") }
            Action { text: qsTr("&Paste") }
        }
        Menu {
            title: qsTr("&Group")
            Action { text: qsTr("&About") }
        }
        Menu {
            title: qsTr("&Help")
            Action { text: qsTr("&About") }
        }
    }

    Row {
        id: row
        anchors.top: menu.bottom
        anchors.left: menu.left
        anchors.margins: 10
        //anchors.topMargin: 10
        //anchors.leftMargin: 10
        width: parent.width-row.anchors.margins*2/7
        spacing: 5
        property int btnHeight: 25
        property int btnWidthParam: 640
        CustomBtn {
            height: row.btnHeight
            width: (row.btnWidthParam-row.anchors.margins*2-row.spacing*6)/7
            text: qsTr("Add")
        }

        CustomBtn {
            height: row.btnHeight
            width: (row.btnWidthParam-row.anchors.margins*2-row.spacing*6)/7
            text: qsTr("Change")
        }

        CustomBtn {
            width: (row.btnWidthParam-row.anchors.margins*2-row.spacing*6)/7
            height: row.btnHeight
            text: qsTr("Delete")
        }
//        Button {
//            width: (row.btnWidthParam-row.anchors.margins*2-row.spacing*6)/7
//            height: row.btnHeight
//            text: qsTr("AM")
//        }
//        Button {
//            width: (row.btnWidthParam-row.anchors.margins*2-row.spacing*6)/7
//            height: row.btnHeight
//            text: qsTr("AM")
//        }
//        Button {
//            width: (row.btnWidthParam-row.anchors.margins*2-row.spacing*6)/7
//            height: row.btnHeight
//            text: qsTr("AM")
//        }
//        Button {
//            width: (row.btnWidthParam-row.anchors.margins*2-row.spacing*6)/7
//            height: row.btnHeight
//            text: qsTr("AM")
//        }
    }
Rectangle{
    anchors.top: row.bottom
    anchors.left: window.left
    //anchors.topMargin: 10
    anchors.leftMargin: 10
    width: parent.width
    TabBar {
        id: bar
        width: parent.width
        anchors.top: parent.bottom
        anchors.left: parent.left
        anchors.topMargin: 10
        anchors.leftMargin: 10

        background: Rectangle {
                color: "#eeeeee"
            }

        CustomTabBtn {
            height: 30
            text: qsTr("Local users")
            implicitWidth: 100
            width: 100
        }
        CustomTabBtn {
            height: 30
            implicitWidth: 100
            text: qsTr("Groups")
            width: 100
        }
    }
}

    StackLayout {
        width: parent.width
        currentIndex: bar.currentIndex
        Item {
            id: usersTab
            Label {
                id: columns
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.topMargin: 130
                anchors.margins: 20
                text: "UID      GID       RegistratorName       FullName     HomeDir       LoginEngine"
            }
            Rectangle {
                id: userListRect
                anchors.left: parent.left
                anchors.top: columns.top
                anchors.margins: 20
                anchors.topMargin: 20

                width: window.width-anchors.margins*2
                height: window.height - anchors.topMargin-anchors.margins
                //width: 300
                //height: 300

                border.color: "lightblue"
                border.width: 0.5
                radius: 5
                color: "white"
                //property string textt: logic.getLocalUsers()
                Text {
                    id: sas
                    //text: qsTr(logic.getLocalUsers())
                    color: "black"
                }
                ListView {
                    id: userList
                    clip: true
                    //anchors.fill: parent
                    width: parent.width-2
                    height: parent.height-2
                    anchors.centerIn: parent
                    model: modelu.data
                    //highlight: Rectangle { color: "lightblue"; radius: 5 }
                    focus: true
                    spacing: -1
                    keyNavigationEnabled: true
                    ScrollBar.vertical: ScrollBar {}
                    delegate: Component {
                        Rectangle {
                            id: wrapper
                            width: userList.width
                            height: 20
                            color: ListView.isCurrentItem ? "lightblue" : "white"
                            Text {
                                //id: contactInfo
                                text: model.UID + "          " + model.GID + "            " + model.RegistratorName + "                 " +  model.FullName + "     " + model.HomeDir + "       " +   model.LoginEngine
                                color: "black"
                                //anchors.centerIn: parent
                            }
                            MouseArea
                            {
                                anchors.fill: parent
                                onClicked:
                                {
                                    userList.currentIndex = index
                                    //itemClicked();
                                }
                            }
                        }
                    }
                }
            }
        }


    Item {
        id: groupsTab
        Label {
            id: columns1
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.topMargin: 130
            anchors.margins: 20
            text: "UID      GID       RegistratorName       FullName     HomeDir       LoginEngine"
        }
        Rectangle {
            id: userListRect1
            anchors.left: parent.left
            anchors.top: columns1.top
            anchors.margins: 20
            anchors.topMargin: 20

            width: window.width-anchors.margins*2
            height: window.height - anchors.topMargin-anchors.margins
            //width: 300
            //height: 300

            border.color: "lightblue"
            border.width: 0.5
            radius: 5
            color: "white"
            //property string textt: logic.getLocalUsers()
            Text {
                id: sas1
                //text: qsTr(logic.getLocalUsers())
                color: "black"
            }
            ListView {
                id: userList1
                clip: true
                //cellHeight: 20
                //cellWidth: 70
                //anchors.fill: parent
                width: parent.width-2
                height: parent.height-2
                anchors.centerIn: parent
                model: modelu.data
                //highlight: Rectangle { color: "lightblue"; radius: 5 }
                focus: true
                spacing: -1
                keyNavigationEnabled: true
                ScrollBar.vertical: ScrollBar {}
                delegate: /*Column {
                Text { text: model.UID; anchors.horizontalCenter: parent.horizontalCenter }*/

                    Rectangle {
                        id: wrapper
                        width: userList1.width
                        height: 20
                        color: ListView.isCurrentItem ? "lightblue" : "white"
                        Text {
                            //id: contactInfo
                            //text: model.UID +  model.GID  + model.RegistratorName                +  model.FullName + "     " + model.HomeDir + "       " +   model.LoginEngine
                            color: "black"
                            //anchors.centerIn: parent
                        }
                        MouseArea
                        {
                            anchors.fill: parent
                            onClicked:
                            {
                                userList1.currentIndex = index
                                //itemClicked();
                            }
                        }
                    }
                }
            }
        }
    }
    }



