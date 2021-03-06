#ifndef SCREENSHOT_H
#define SCREENSHOT_H

#include <QWidget>
#include <QRubberBand>
#include <QImage>
#include <QLabel>
#include <QMouseEvent>
#include <QDesktopWidget>
#include <QDesktopServices>
#include <QScreen>
#include <QSystemTrayIcon>
#include <QKeyEvent>
#include <QMenu>
#include <QDir>
#include <QDateTime>
#include <QPushButton>
#include <QClipboard>
#include <QColorDialog>
#include <QPalette>


namespace Ui {
class ScreenShot;
}

class ScreenShot : public QWidget
{
    Q_OBJECT

public:
    ~ScreenShot();
    ScreenShot();
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void keyPressEvent(QKeyEvent *e);
    void setBackground(int w,int h,float n);
    void setLabel(int w,int h,int x,int y);
    void setButton(int w,int h,int x,int y);


private:
    Ui::ScreenShot *ui;
    QRubberBand *rubber;
    QIcon icon;
    QPoint origin;//鼠标起始位置
    QPoint end;//鼠标结束位置
    QImage bg;//存贮当前桌面截图
    QLabel *label,*colorLabel;//用来框选图片
    QPushButton *done;//用来确认并生成图片
    QColor color;
    int width;//屏幕宽度
    int height;//屏幕高度
    int pw,ph,px,py;
    static ScreenShot* instance;
    bool shot; //用来判断是否重构rubber
    bool quit; //用来选择右键响应事件

    QSystemTrayIcon* tray;
    QAction *quitAction;               //退出事件
    QAction *pickAction;               //取色
    QAction *shotAction;               //
//    QAction *gifAction;               //录gif
    QMenu *trayIconMenu;               //托盘图标点击菜单

    void creatActions();
    void creatMenu();
    void setRubber();
    void pSize();


    int choice;
    QFont *font;


public slots:
    void Shot(float n);
    void grabScreen();
    void pickColor();
//    void makeGif();
    void shotSlot();
    void setColorLabel(int x,int y);
    void iconActivied(QSystemTrayIcon::ActivationReason reason);

};

#endif // SCREENSHOT_H
