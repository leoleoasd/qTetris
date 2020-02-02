#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum class Tetromino {IPolyomino, OPolyomino, TPolyomino, JPolyomino, LPolyomino, SPolyomino, ZPolyomino};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
    void drop();

private:
    Ui::MainWindow *ui;
    QTimer *dropTimer, *renderTimer;
    const static int MAXX = 10;
    const static int MAXY = 20;

    /*
     * 模拟左手系第一象限
     * 0,0 0,1 0,2 0,3, ...
     * 1,0 1,1 1,2 1,3, ...
     * .
     * .
     * .
     */
    int map[MainWindow::MAXX][MainWindow::MAXY];
    //七种不同方块，每个方块有四个方向，存在4*4的数组里，每个元素非1即0
    bool tetromino[7][4][4][4];
    int x,y,direction;
    Tetromino current, next;
    Tetromino generateTetris();

    void doLeftEvent();
    void doRightEvent();
    void doRotateEvent();
    bool overlapping();
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
};
#endif // MAINWINDOW_H
