#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    // 设置画笔颜色
    painter.setPen(QColor(0, 160, 230));

    // 设置字体：微软雅黑、点大小50、斜体
    QFont font;
    font.setPointSize(50);
    font.setItalic(true);
    painter.setFont(font);

    // 绘制文本
    painter.drawText(rect(), Qt::AlignCenter, "Qt");
}
