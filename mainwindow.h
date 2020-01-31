#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    virtual void paintEvent(QPaintEvent *event);

private:
    Ui::MainWindow *ui;
    int map[10][20] {0}; //模拟右手系第一象限
    bool tetromino[7][4][4][4]; //七种不同方块，每个方块有四个方向，存在4*4的数组里，每个元素非1即0
    enum TetrominoName {IPolyomino, OPolyomino, TPolyomino, JPolyomino, LPolyomino, SPolyomino, ZPolyomino}; //与teromino数组联用，增强可读性
    struct {
        int x;
        int y;
        int name;
        int direction;
    }tetrominoCurrent;
    void doDownEvent();
    void doLeftEvent();
    void doRightEvent();
    void doRotateEvent();
    void movementIsLegal();
};
#endif // MAINWINDOW_H
