import QtQuick 2.15
import QtQuick.Window 2.15 
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3
import "./UIElements"


Window {
    id: window
    width: 840
    height: 480
    minimumWidth: 640
    minimumHeight: 480
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
        id: tabBar
        anchors.top: row.bottom
        anchors.left: window.left
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

            property int btnHeight: 30
            property int btnWidth: 100

            CustomTabBtn {
                height: bar.btnHeight
                text: qsTr("Local users")
                implicitWidth: bar.btnWidth
                width: bar.btnWidth
            }
            CustomTabBtn {
                height: bar.btnHeight
                implicitWidth: bar.btnWidth
                text: qsTr("Groups")
                width: bar.btnWidth
            }
        }
    }

    StackLayout {
        width: parent.width
        currentIndex: bar.currentIndex
        Item {
            id: usersTab
            Rectangle {
                id: userListRect
                anchors.left: parent.left
                anchors.top: parent.bottom
                anchors.margins: 10
                anchors.topMargin: 120
                width: window.width-anchors.margins*2
                height: window.height - anchors.topMargin-anchors.margins

                border.color: "lightblue"
                border.width: 0.5
                radius: 5
                color: "white"
                ListView {
                    id: userList
                    header: Rectangle {
                        id: headerItem
                        width: userList.width
                        height: 20
                        color: Qt.darker("lightgray", 0.95)
                        z: 2
                        Row{
                            spacing: 20
                            Text {
                                width: 50
                                text: "UID"
                                color: "black"
                            }
                            Text {
                                width: 50
                                text: "GID"
                                color: "black"
                            }
                            Text {
                                width: 100
                                text: "RegistratorName"
                                color: "black"
                            }
                            Text {
                                width: 200
                                text: "FullName"
                                color: "black"
                            }
                            Text {
                                width: 150
                                text: "HomeDir"
                                color: "black"
                            }
                            Text {
                                width: 100
                                text: "LoginEngine"
                                color: "black"
                            }
                        }
                    }
                    headerPositioning: ListView.OverlayHeader
                    clip: true
                    width: parent.width-2
                    height: parent.height-2
                    anchors.centerIn: parent
                    model: userModel.data
                    focus: true
                    spacing: -1
                    keyNavigationEnabled: true
                    ScrollBar.vertical: ScrollBar {}
                    delegate:
                        Rectangle {
                        width: userList.width
                        height: 20
                        color: ListView.isCurrentItem ? "lightblue" : "white"
                        Row{
                            spacing: 20
                            Text {
                                clip: true
                                width: 50
                                text: model.UID
                                color: "black"
                            }
                            Text {
                                clip: true
                                width: 50
                                text: model.GID
                                color: "black"
                            }
                            Text {
                                width: 100
                                text: model.RegistratorName
                                color: "black"
                            }
                            Text {
                                width: 200
                                clip: true
                                text: model.FullName
                                color: "black"
                            }
                            Text {
                                clip: true
                                width: 150
                                text: model.HomeDir
                                color: "black"
                            }
                            Text {
                                clip: true
                                width: 100
                                text: model.LoginEngine
                                color: "black"
                            }
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


        Item {
            id: groupsTab

            Rectangle {
                id: groupListRect
                anchors.left: parent.left
                anchors.top: parent.bottom
                anchors.margins: 10
                anchors.topMargin: 120

                width: window.width-anchors.margins*2
                height: window.height - anchors.topMargin-anchors.margins

                border.color: "lightblue"
                border.width: 0.5
                radius: 5
                color: "white"
                ListView {
                    id: groupList
                    header: Rectangle {
                        id: groupHeaderItem
                        width: groupList.width
                        height: 20
                        color: Qt.darker("lightgray", 0.95)
                        z: 2
                        Row{
                            spacing: 20
                            Text {
                                width: 50
                                text: "UID"
                                color: "black"
                            }
                            Text {
                                width: 50
                                text: "GID"
                                color: "black"
                            }
                            Text {
                                width: 100
                                text: "RegistratorName"
                                color: "black"
                            }
                            Text {
                                width: 200
                                text: "FullName"
                                color: "black"
                            }
                            Text {
                                width: 150
                                text: "HomeDir"
                                color: "black"
                            }
                            Text {
                                width: 100
                                text: "LoginEngine"
                                color: "black"
                            }
                        }
                    }
                    headerPositioning: ListView.OverlayHeader
                    clip: true
                    width: parent.width-2
                    height: parent.height-2
                    anchors.centerIn: parent
                    model: userModel.data
                    focus: true
                    spacing: -1
                    keyNavigationEnabled: true
                    ScrollBar.vertical: ScrollBar {}
                    delegate:
                        Rectangle {
                        width: parent.width
                        height: 20
                        color: ListView.isCurrentItem ? "lightblue" : "white"
                        Row{
                            spacing: 20
                            Text {
                                clip: true
                                width: 50
                                text: model.UID
                                color: "black"
                            }
                            Text {
                                clip: true
                                width: 50
                                text: model.GID
                                color: "black"
                            }
                            Text {
                                width: 100
                                text: model.RegistratorName
                                color: "black"
                            }
                            Text {
                                width: 200
                                clip: true
                                text: model.FullName
                                color: "black"
                            }
                            Text {
                                clip: true
                                width: 150
                                text: model.HomeDir
                                color: "black"
                            }
                            Text {
                                clip: true
                                width: 100
                                text: model.LoginEngine
                                color: "black"
                            }
                        }
                        MouseArea
                        {
                            anchors.fill: parent
                            onClicked:
                            {
                                groupList.currentIndex = index
                                //itemClicked();
                            }
                        }
                    }
                }
            }
        }
    }

}


