#include "widget.h"
#include "ui_widget.h"
#include <QApplication>
#include <QVBoxLayout>
#include <QDesktopWidget>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QScreen>
#include <QIcon>
#include <QPushButton>
#include <QSystemTrayIcon>
#include <QMenu>
#include <qwidget.h>
#include <qwidget.h>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    Widget w;

    w.setWindowTitle("XiaoeYu");

    w.setStyleSheet(
        "QWidget {"
        "    background-color: #f5f5f5;"
        "    border: 1px solid #dcdcdc;"
        "    border-top-left-radius: 5px;"
        "    border-top-right-radius: 5px;"
        "}"
    );
    QIcon icon("fav.png");
    w.setWindowIcon(icon);


    w.setFixedSize(600, 500);


    QVBoxLayout* layout = new QVBoxLayout(&w);
    layout->setContentsMargins(0, 0, 0, 0);


    QWebEngineView* webView = new QWebEngineView(&w);
    webView->load(QUrl("https://luyaocode.github.io"));


    layout->addWidget(webView);


    QRect availableGeometry = QGuiApplication::primaryScreen()->availableVirtualGeometry();
    int screenWidthAvailable = availableGeometry.width();
    int screenHeightAvailable = availableGeometry.height();



    int windowWidth = w.width();
    int windowHeight = w.height();
    int windowX = screenWidthAvailable - windowWidth;
    int windowY = screenHeightAvailable - windowHeight;
    w.setGeometry(windowX, windowY, windowWidth, windowHeight);


    QSystemTrayIcon* trayIcon = new QSystemTrayIcon(&w);
    trayIcon->setIcon(icon);
    trayIcon->setToolTip("xiaoeYu");


    QMenu* trayMenu = new QMenu(&w);
    QAction* restoreAction = new QAction("Restore", &w);
    QAction* quitAction = new QAction("Quit", &w);
    trayMenu->addAction(restoreAction);
    trayMenu->addAction(quitAction);


    trayIcon->setContextMenu(trayMenu);


    w.show();


    QObject::connect(restoreAction, &QAction::triggered, &w, &QWidget::showNormal);


    QObject::connect(quitAction, &QAction::triggered, &a, &QApplication::quit);


    trayIcon->show();

    return a.exec();
}
