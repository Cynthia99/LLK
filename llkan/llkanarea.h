#ifndef LLKANAREA_H
#define LLKANAREA_H

// 地图行列数
#define MAP_ROW         10
#define MAP_COL         14

// 地图每个格子宽高
#define CELL_WIDTH      46
#define CELL_HEIGHT     56

// 图像宽高
#define IMG_WIDTH       38
#define IMG_HEIGHT      38

// 3D 边框宽高
#define FRAME_WIDTH     41
#define FRAME_HEIGHT    51

#define MAX_TIME        100

// 空白状态
#define BLANK_STATE     -1

#include <QtGui>
#include <vector>

using namespace std;

class LLKanArea : public QWidget
{
    typedef struct LinkLine{
        int start_row;
        int start_col;
        int end_row;
        int end_col;
    } LinkLine;

    Q_OBJECT
public:
    LLKanArea(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);

    void initGame();

    void refreshGame();

    void lbuttonDownAt(int x, int y);

    int isLink(int row, int col, int select_row, int select_col);

    bool isRowLink(int row, int col, int select_row, int select_col);
    bool isColLink(int row, int col, int select_row, int select_col);
    bool isOneCornerLink(int row, int col, int select_row, int select_col);
    bool isTwoCornerLink(int row, int col, int select_row, int select_col);

    bool isRow(int v_row, int v_col, int r_row, int r_col);
    bool isCol(int v_row, int v_col, int r_row, int r_col);

    bool isSelectTime(int SelectTime);

    bool isWin();

    int getTimeLeft();

private:
    QImage *img;            // 图案
    QImage *frame;          // 3D 边框
    QImage *blue;           // 蓝色边
    QImage *gray;           // 灰色边

    bool is_selected;
    bool is_link;

    int select_row;
    int select_col;

    int SelectTime;

    bool gameover;

    vector<LinkLine> link_lines;
    LinkLine line,line1,line2;

    int map[MAP_ROW][MAP_COL];

    int time_left;
};

#endif // LLKANAREA_H
