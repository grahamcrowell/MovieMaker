import QtQuick 2.2
import QtQuick.Controls 1.1
import plumbing 0.1

ApplicationWindow {
    id: applicationWindow1
    visible: true
    width: 200
    height: 100
    title: qsTr("Hello World")

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    Item {
        id: overlord
        anchors.fill: parent
        focus: true

        Button {
            id: button1
            text: qsTr("Create Images")
            checked: false
            anchors.top: parent.top
            anchors.topMargin: 50
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            antialiasing: true
            checkable: false
            onClicked: {
                luigi.handleButton();
            }
        }
        Plumbing {
            id: luigi
            qml_left_var: textFieldLeft.text
            qml_right_var: textFieldRight.text

        }
        TextField {
            id: textFieldLeft
            focus: true
            antialiasing: true
            text: "500"
            placeholderText: "frames"
            font.pointSize: 20
            anchors.top: parent.top
            anchors.topMargin: 0
            anchors.bottom: button1.top
            anchors.bottomMargin: 0
            anchors.right: parent.right
            anchors.rightMargin: 100
            anchors.left: parent.left
            anchors.leftMargin: 0

        }

        TextField {
            id: textFieldRight
            antialiasing: true
            text: "500"
            placeholderText: "width"
            font.pointSize: 20
            anchors.top: parent.top
            anchors.topMargin: 0
            anchors.bottom: button1.top
            anchors.bottomMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 100
            anchors.right: parent.right
            anchors.rightMargin: 0
        }

        Keys.onPressed: {
            if (event.key === Qt.Key_Return)
                luigi.handleButton();
            else if(event.key === Qt.Key_Escape)
                Qt.quit()

        }
    }

}
