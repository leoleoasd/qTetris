#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QTimer>
#include <QRandomGenerator>
#include <QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , dropTimer(new QTimer)
    , renderTimer(new QTimer){
    ui->setupUi(this);
    connect(renderTimer, &QTimer::timeout, this, QOverload<>::of(&MainWindow::update));
    connect(dropTimer, &QTimer::timeout, this, QOverload<>::of(&MainWindow::drop));
    renderTimer->start(1000 / 120); // 120fps
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event){
    static int last_frame_time = QTime::currentTime().msecsSinceStartOfDay() - 1000/120;
    Q_UNUSED(event);

    QPainter painter(this);
    // 设置画笔颜色
    painter.setPen(QColor(0, 160, 230));

    // 设置字体：点大小12、斜体
    QFont font;
    font.setPointSize(12);
    font.setItalic(true);
    painter.setFont(font);

    // 绘制文本
    painter.drawText(0,12, QString::number((int)generateTetris()));
    painter.drawText(0,24,QString::number(1000.0/(QTime::currentTime().msecsSinceStartOfDay() - last_frame_time)) + QString::fromLocal8Bit("fps."));
    last_frame_time = QTime::currentTime().msecsSinceStartOfDay();
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    // TODO: 处理键盘事件
}


Tetromino MainWindow::generateTetris(){
    return (Tetromino)(QRandomGenerator::global()->bounded(7));
}
