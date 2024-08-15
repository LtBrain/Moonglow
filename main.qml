import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: "Telemetry Dashboard"

    Rectangle {
        width: 200
        height: 200
        color: "lightblue"
        
        Text {
            anchors.centerIn: parent
            text: "Telemetry Data"
            font.pixelSize: 24
        }
    }

    // Add UI components to display telemetry data here
}
