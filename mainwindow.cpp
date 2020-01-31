#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QTimer>
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , dropTimer(new QTimer)
    , renderTimer(new QTimer)
{
    ui->setupUi(this);
    connect(renderTimer, &QTimer::timeout, this, QOverload<>::of(&MainWindow::update));
    renderTimer->start(1000 / 120); // 120fps
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
    painter.drawText(rect(), Qt::AlignCenter, QString::number((int)generateTetris()));
}


Tetromino MainWindow::generateTetris(){
    return (Tetromino)(QRandomGenerator::global()->bounded(7));
}
