import QtQuick 2.12
import QtQuick.Window 2.12
import QtWebView 1.1

Window {
    visible: true
    width: 640
    height: 480
    title: "小恶鱼"
    Rectangle {
        id: splashScreen
        color: "white"
        width: parent.width
        height: parent.height

        // 添加开屏动画效果
        opacity: 0
        Behavior on opacity {
            NumberAnimation { duration: 1000 }
        }

        WebView {
            id: webView
            anchors.fill: parent
            url: "https://luyaocode.github.io" // 替换为你要加载的网页的URL

            // 在WebView的加载完成后隐藏开屏动画
            onLoadingChanged: {
                if (!loading && !webView.loading) {
                    splashScreen.opacity = 0;
                }
            }
        }

        // 在开屏动画完成后开始加载网页
        Component.onCompleted: {
            splashScreen.opacity = 1;
            webView.load();
        }
    }
}
