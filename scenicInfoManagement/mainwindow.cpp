#include "mainwindow.h"
#include "graph.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QMessageBox>
#define WIN_WIGHT 1500
#define WIN_HEIGHT 800
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(WIN_WIGHT,WIN_HEIGHT);
    pix=QPixmap(WIN_WIGHT,WIN_HEIGHT);
    pix.fill(Qt::white);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawline(int x1,int y1,int x2,int y2, QColor const c)
{
    QPainter painter(&pix);
    painter.setPen(QPen(c));
    QLineF line(x1,y1,x2,y2);
    painter.drawLine(line);
    update();
}

void MainWindow::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,WIN_WIGHT,WIN_HEIGHT,pix);
}

void MainWindow::on_recommendpath_clicked()

{   Graph graph;
    graph.Init();
    Graph::Vex vexs[SIZE];
    Graph::Edge edges[SIZE*SIZE];
    memset(vexs,0,sizeof (vexs));
    memset(edges,0,sizeof (edges));
    graph.createScenicSpot(vexs,edges);

    for(int i = 0;i < 7;i++)
        graph.InsertVex(vexs[i]);

    for(int i = 0;i < 11;i++)
        graph.InsertEdge(edges[i]);

    Graph::Edge temp[11];
    graph.MST(temp);//最小生成树，推荐游览路径

    pix.fill(Qt::white);
    int B1X,B1Y,B2X,B2Y;
    QPoint p1,p2;
    for(int i = 0;i < 11;i++){
        switch (temp[i].vex1) {
        case 0:
            p1=ui->spot1_3->mapToGlobal(QPoint(0,0));
            B1X=p1.x(),B1Y=p1.y();
            switch(temp[i].vex2){
            case 0:
                p2=ui->spot1_3->mapToGlobal(QPoint(0,0));
                break;
            case 1:
                p2=ui->spot2_3->mapToGlobal(QPoint(0,0));
                break;
            case 2:
                p2=ui->spot3_3->mapToGlobal(QPoint(0,0));
                break;
            case 3:
                p2=ui->spot4_3->mapToGlobal(QPoint(0,0));
                break;
            case 4:
                p2=ui->spot5_3->mapToGlobal(QPoint(0,0));
                break;
            case 5:
                p2=ui->spot6_3->mapToGlobal(QPoint(0,0));
                break;
            case 6:
                p2=ui->spot7_3->mapToGlobal(QPoint(0,0));
                break;
            }
            B2X=p2.x(),B2Y=p2.y();
            drawline(B1X,B1Y,B2X,B2Y,QColor(255,0,0));
            break;
        case 1:
            p1=ui->spot2_3->mapToGlobal(QPoint(0,0));
            B1X=p1.x(),B1Y=p1.y();
            switch(temp[i].vex2){
            case 0:
                p2=ui->spot1_3->mapToGlobal(QPoint(0,0));
                break;
            case 1:
                p2=ui->spot2_3->mapToGlobal(QPoint(0,0));
                break;
            case 2:
                p2=ui->spot3_3->mapToGlobal(QPoint(0,0));
                            //printf("x1:%d y1:%d x2:%d y2:%d \n",B1X,B1Y,B2X,B2Y);
                break;
            case 3:
                p2=ui->spot4_3->mapToGlobal(QPoint(0,0));
                break;
            case 4:
                p2=ui->spot5_3->mapToGlobal(QPoint(0,0));
                break;
            case 5:
                p2=ui->spot6_3->mapToGlobal(QPoint(0,0));
                break;
            case 6:
                p2=ui->spot7_3->mapToGlobal(QPoint(0,0));
                break;
            }
            B2X=p2.x(),B2Y=p2.y();
            drawline(B1X,B1Y,B2X,B2Y,QColor(255,0,0));
            break;
        case 2:
            p1=ui->spot3_3->mapToGlobal(QPoint(0,0));
            B1X=p1.x(),B1Y=p1.y();
            switch(temp[i].vex2){
            case 0:
                p2=ui->spot1_3->mapToGlobal(QPoint(0,0));
                break;
            case 1:
                p2=ui->spot2_3->mapToGlobal(QPoint(0,0));
                break;
            case 2:
                p2=ui->spot3_3->mapToGlobal(QPoint(0,0));
                break;
            case 3:
                p2=ui->spot4_3->mapToGlobal(QPoint(0,0));
                break;
            case 4:
                p2=ui->spot5_3->mapToGlobal(QPoint(0,0));
                break;
            case 5:
                p2=ui->spot6_3->mapToGlobal(QPoint(0,0));
                break;
            case 6:
                p2=ui->spot7_3->mapToGlobal(QPoint(0,0));
                break;
            }
            B2X=p2.x(),B2Y=p2.y();
            drawline(B1X,B1Y,B2X,B2Y,QColor(255,0,0));
            break;
        case 3:
            p1=ui->spot4_3->mapToGlobal(QPoint(0,0));
            B1X=p1.x(),B1Y=p1.y();
            switch(temp[i].vex2){
            case 0:
                p2=ui->spot1_3->mapToGlobal(QPoint(0,0));
                break;
            case 1:
                p2=ui->spot2_3->mapToGlobal(QPoint(0,0));
                break;
            case 2:
                p2=ui->spot3_3->mapToGlobal(QPoint(0,0));
                break;
            case 3:
                p2=ui->spot4_3->mapToGlobal(QPoint(0,0));
                break;
            case 4:
                p2=ui->spot5_3->mapToGlobal(QPoint(0,0));
                break;
            case 5:
                p2=ui->spot6_3->mapToGlobal(QPoint(0,0));
                break;
            case 6:
                p2=ui->spot7_3->mapToGlobal(QPoint(0,0));
                break;
            }
            B2X=p2.x(),B2Y=p2.y();
            drawline(B1X,B1Y,B2X,B2Y,QColor(255,0,0));
            break;
        case 4:
            p1=ui->spot5_3->mapToGlobal(QPoint(0,0));
            B1X=p1.x(),B1Y=p1.y();
            switch(temp[i].vex2){
            case 0:
                p2=ui->spot1_3->mapToGlobal(QPoint(0,0));
                break;
            case 1:
                p2=ui->spot2_3->mapToGlobal(QPoint(0,0));
                break;
            case 2:
                p2=ui->spot3_3->mapToGlobal(QPoint(0,0));
                break;
            case 3:
                p2=ui->spot4_3->mapToGlobal(QPoint(0,0));
                break;
            case 4:
                p2=ui->spot5_3->mapToGlobal(QPoint(0,0));
                break;
            case 5:
                p2=ui->spot6_3->mapToGlobal(QPoint(0,0));
                break;
            case 6:
                p2=ui->spot7_3->mapToGlobal(QPoint(0,0));
                break;
            }
            B2X=p2.x(),B2Y=p2.y();
            drawline(B1X,B1Y,B2X,B2Y,QColor(255,0,0));
            break;
        case 5:
            p1=ui->spot6_3->mapToGlobal(QPoint(0,0));
            B1X=p1.x(),B1Y=p1.y();
            switch(temp[i].vex2){
            case 0:
                p2=ui->spot1_3->mapToGlobal(QPoint(0,0));
                break;
            case 1:
                p2=ui->spot2_3->mapToGlobal(QPoint(0,0));
                break;
            case 2:
                p2=ui->spot3_3->mapToGlobal(QPoint(0,0));
                break;
            case 3:
                p2=ui->spot4_3->mapToGlobal(QPoint(0,0));
                break;
            case 4:
                p2=ui->spot5_3->mapToGlobal(QPoint(0,0));
                break;
            case 5:
                p2=ui->spot6_3->mapToGlobal(QPoint(0,0));
                break;
            case 6:
                p2=ui->spot7_3->mapToGlobal(QPoint(0,0));
                break;
            }
            B2X=p2.x(),B2Y=p2.y();
            drawline(B1X,B1Y,B2X,B2Y,QColor(255,0,0));
            break;
        case 6:
            p1=ui->spot7_3->mapToGlobal(QPoint(0,0));
            B1X=p1.x(),B1Y=p1.y();
            switch(temp[i].vex2){
            case 0:
                p2=ui->spot1_3->mapToGlobal(QPoint(0,0));
                break;
            case 1:
                p2=ui->spot2_3->mapToGlobal(QPoint(0,0));
                break;
            case 2:
                p2=ui->spot3_3->mapToGlobal(QPoint(0,0));
                break;
            case 3:
                p2=ui->spot4_3->mapToGlobal(QPoint(0,0));
                break;
            case 4:
                p2=ui->spot5_3->mapToGlobal(QPoint(0,0));
                break;
            case 5:
                p2=ui->spot6_3->mapToGlobal(QPoint(0,0));
                break;
            case 6:
                p2=ui->spot7_3->mapToGlobal(QPoint(0,0));
                break;
            }
            B2X=p2.x(),B2Y=p2.y();
            drawline(B1X,B1Y,B2X,B2Y,QColor(255,0,0));
            break;
        }
    }
}

void MainWindow::on_recommend_clicked()
{
       Graph graph;
       graph.Init();
       Graph::Vex vexs[SIZE];
       Graph::Edge edges[SIZE*SIZE];
       memset(vexs,0,sizeof (vexs));
       memset(edges,0,sizeof (edges));
       graph.createScenicSpot(vexs,edges);
       for(int i = 0;i < 7;i++){
           graph.InsertVex(vexs[i]);
       }
       for(int i = 0;i < 11;i++){
           graph.InsertEdge(edges[i]);
       }

       Graph::Vex temp;
       Graph::Edge tempedges[7];
       temp = graph.getVet(ui->start->text().toStdString());
       int start = temp.num;
       temp = graph.getVet(ui->end->text().toStdString());
       int end = temp.num;

       if(start < 0 || end < 0 || start > 6 || end > 6 || ui->start->text() == NULL || ui->end->text() == NULL || ui->end->text() == ui->start->text())
               int a = (QMessageBox::warning(this, tr("waring"),tr("景点名错误！")));
       else{
           string path;
           graph.FindShortPath(start,end,path);//两点间最短距离
           Graph::Edge temp2;
           temp2.vex1 = start,temp2.vex2 = end;
       pix.fill(Qt::white);
       int B1X,B1Y,B2X,B2Y;
       QPoint p1,p2;

           for(int i = path.length()-1;i > 0;i--){
           switch (int(path.at(i)-'0')) {
           case 0:
               p1=ui->spot1_3->mapToGlobal(QPoint(0,0));
               B1X=p1.x(),B1Y=p1.y();
               switch(int(path.at(i-1)-'0')){
               case 0:
                   p2=ui->spot1_3->mapToGlobal(QPoint(0,0));
                   break;
               case 1:
                   p2=ui->spot2_3->mapToGlobal(QPoint(0,0));
                   break;
               case 2:
                   p2=ui->spot3_3->mapToGlobal(QPoint(0,0));
                   break;
               case 3:
                   p2=ui->spot4_3->mapToGlobal(QPoint(0,0));
                   break;
               case 4:
                   p2=ui->spot5_3->mapToGlobal(QPoint(0,0));
                   break;
               case 5:
                   p2=ui->spot6_3->mapToGlobal(QPoint(0,0));
                   break;
               case 6:
                   p2=ui->spot7_3->mapToGlobal(QPoint(0,0));
                   break;
               }
               B2X=p2.x(),B2Y=p2.y();
               drawline(B1X,B1Y,B2X,B2Y,QColor(255,0,0));
               break;
           case 1:
               p1=ui->spot2_3->mapToGlobal(QPoint(0,0));
               B1X=p1.x(),B1Y=p1.y();
               switch(int(path.at(i-1)-'0')){
               case 0:
                   p2=ui->spot1_3->mapToGlobal(QPoint(0,0));
                   break;
               case 1:
                   p2=ui->spot2_3->mapToGlobal(QPoint(0,0));
                   break;
               case 2:
                   p2=ui->spot3_3->mapToGlobal(QPoint(0,0));
                   break;
               case 3:
                   p2=ui->spot4_3->mapToGlobal(QPoint(0,0));
                   break;
               case 4:
                   p2=ui->spot5_3->mapToGlobal(QPoint(0,0));
                   break;
               case 5:
                   p2=ui->spot6_3->mapToGlobal(QPoint(0,0));
                   break;
               case 6:
                   p2=ui->spot7_3->mapToGlobal(QPoint(0,0));
                   break;
               }
               B2X=p2.x(),B2Y=p2.y();
               drawline(B1X,B1Y,B2X,B2Y,QColor(255,0,0));
               break;
           case 2:
               p1=ui->spot3_3->mapToGlobal(QPoint(0,0));
               B1X=p1.x(),B1Y=p1.y();
               switch(int(path.at(i-1)-'0')){
               case 0:
                   p2=ui->spot1_3->mapToGlobal(QPoint(0,0));
                   break;
               case 1:
                   p2=ui->spot2_3->mapToGlobal(QPoint(0,0));
                   break;
               case 2:
                   p2=ui->spot3_3->mapToGlobal(QPoint(0,0));
                   break;
               case 3:
                   p2=ui->spot4_3->mapToGlobal(QPoint(0,0));
                   break;
               case 4:
                   p2=ui->spot5_3->mapToGlobal(QPoint(0,0));
                   break;
               case 5:
                   p2=ui->spot6_3->mapToGlobal(QPoint(0,0));
                   break;
               case 6:
                   p2=ui->spot7_3->mapToGlobal(QPoint(0,0));
                   break;
               }
               B2X=p2.x(),B2Y=p2.y();
               drawline(B1X,B1Y,B2X,B2Y,QColor(255,0,0));
               break;
           case 3:
               p1=ui->spot4_3->mapToGlobal(QPoint(0,0));
               B1X=p1.x(),B1Y=p1.y();
               switch(int(path.at(i-1)-'0')){
               case 0:
                   p2=ui->spot1_3->mapToGlobal(QPoint(0,0));
                   break;
               case 1:
                   p2=ui->spot2_3->mapToGlobal(QPoint(0,0));
                   break;
               case 2:
                   p2=ui->spot3_3->mapToGlobal(QPoint(0,0));
                   break;
               case 3:
                   p2=ui->spot4_3->mapToGlobal(QPoint(0,0));
                   break;
               case 4:
                   p2=ui->spot5_3->mapToGlobal(QPoint(0,0));
                   break;
               case 5:
                   p2=ui->spot6_3->mapToGlobal(QPoint(0,0));
                   break;
               case 6:
                   p2=ui->spot7_3->mapToGlobal(QPoint(0,0));
                   break;
               }
               B2X=p2.x(),B2Y=p2.y();
               drawline(B1X,B1Y,B2X,B2Y,QColor(255,0,0));
               break;
           case 4:
               p1=ui->spot5_3->mapToGlobal(QPoint(0,0));
               B1X=p1.x(),B1Y=p1.y();
               switch(int(path.at(i-1)-'0')){
               case 0:
                   p2=ui->spot1_3->mapToGlobal(QPoint(0,0));
                   break;
               case 1:
                   p2=ui->spot2_3->mapToGlobal(QPoint(0,0));
                   break;
               case 2:
                   p2=ui->spot3_3->mapToGlobal(QPoint(0,0));
                   break;
               case 3:
                   p2=ui->spot4_3->mapToGlobal(QPoint(0,0));
                   break;
               case 4:
                   p2=ui->spot5_3->mapToGlobal(QPoint(0,0));
                   break;
               case 5:
                   p2=ui->spot6_3->mapToGlobal(QPoint(0,0));
                   break;
               case 6:
                   p2=ui->spot7_3->mapToGlobal(QPoint(0,0));
                   break;
               }
               B2X=p2.x(),B2Y=p2.y();
               drawline(B1X,B1Y,B2X,B2Y,QColor(255,0,0));
               break;
           case 5:
               p1=ui->spot6_3->mapToGlobal(QPoint(0,0));
               B1X=p1.x(),B1Y=p1.y();
               switch(int(path.at(i-1)-'0')){
               case 0:
                   p2=ui->spot1_3->mapToGlobal(QPoint(0,0));
                   break;
               case 1:
                   p2=ui->spot2_3->mapToGlobal(QPoint(0,0));
                   break;
               case 2:
                   p2=ui->spot3_3->mapToGlobal(QPoint(0,0));
                   break;
               case 3:
                   p2=ui->spot4_3->mapToGlobal(QPoint(0,0));
                   break;
               case 4:
                   p2=ui->spot5_3->mapToGlobal(QPoint(0,0));
                   break;
               case 5:
                   p2=ui->spot6_3->mapToGlobal(QPoint(0,0));
                   break;
               case 6:
                   p2=ui->spot7_3->mapToGlobal(QPoint(0,0));
                   break;
               }
               B2X=p2.x(),B2Y=p2.y();
               drawline(B1X,B1Y,B2X,B2Y,QColor(255,0,0));
               break;
           case 6:
               p1=ui->spot7_3->mapToGlobal(QPoint(0,0));
               B1X=p1.x(),B1Y=p1.y();
               switch(int(path.at(i-1)-'0')){
               case 0:
                   p2=ui->spot1_3->mapToGlobal(QPoint(0,0));
                   break;
               case 1:
                   p2=ui->spot2_3->mapToGlobal(QPoint(0,0));
                   break;
               case 2:
                   p2=ui->spot3_3->mapToGlobal(QPoint(0,0));
                   break;
               case 3:
                   p2=ui->spot4_3->mapToGlobal(QPoint(0,0));
                   break;
               case 4:
                   p2=ui->spot5_3->mapToGlobal(QPoint(0,0));
                   break;
               case 5:
                   p2=ui->spot6_3->mapToGlobal(QPoint(0,0));
                   break;
               case 6:
                   p2=ui->spot7_3->mapToGlobal(QPoint(0,0));
                   break;
               }
               B2X=p2.x(),B2Y=p2.y();
               drawline(B1X,B1Y,B2X,B2Y,QColor(255,0,0));
               break;
           }
       }
    }
}

void MainWindow::on_spotguide_clicked()
{
    Graph graph;
    graph.Init();
    Graph::Vex vexs[SIZE];
    Graph::Edge edges[SIZE*SIZE];
    memset(vexs,0,sizeof (vexs));
    memset(edges,0,sizeof (edges));
    graph.createScenicSpot(vexs,edges);
    for(int i = 0;i < 7;i++){
        graph.InsertVex(vexs[i]);
    }
    for(int i = 0;i < 11;i++){
        graph.InsertEdge(edges[i]);
    }

    Graph::Vex temp = graph.getVet(ui->guide->text().toStdString());
    int start = temp.num;
    if(start < 0 || start > 6)
        int a = (QMessageBox::warning(this, tr("waring"),tr("景点名错误！")));
    else{
        bool visited[SIZE];
        memset(visited,0,sizeof(visited));
        int sequence[SIZE] = {-1};
        int index = 0;
        graph.DFS(start,visited,sequence,index);//深度优先搜索遍历

        pix.fill(Qt::white);
        int B1X,B1Y,B2X,B2Y;
        QPoint p1,p2;
        for(int i = 0;i < index-1;i++){
            switch (sequence[i]) {
            case 0:
                p1=ui->spot1_3->mapToGlobal(QPoint(0,0));
                B1X=p1.x(),B1Y=p1.y();
                switch(sequence[i+1]){
                case 0:
                    p2=ui->spot1_3->mapToGlobal(QPoint(0,0));
                    break;
                case 1:
                    p2=ui->spot2_3->mapToGlobal(QPoint(0,0));
                    break;
                case 2:
                    p2=ui->spot3_3->mapToGlobal(QPoint(0,0));
                    break;
                case 3:
                    p2=ui->spot4_3->mapToGlobal(QPoint(0,0));
                    break;
                case 4:
                    p2=ui->spot5_3->mapToGlobal(QPoint(0,0));
                    break;
                case 5:
                    p2=ui->spot6_3->mapToGlobal(QPoint(0,0));
                    break;
                case 6:
                    p2=ui->spot7_3->mapToGlobal(QPoint(0,0));
                    break;
                }
                B2X=p2.x(),B2Y=p2.y();
                drawline(B1X,B1Y,B2X,B2Y,QColor(255,0,0));
                break;
            case 1:
                p1=ui->spot2_3->mapToGlobal(QPoint(0,0));
                B1X=p1.x(),B1Y=p1.y();
                switch(sequence[i+1]){
                case 0:
                    p2=ui->spot1_3->mapToGlobal(QPoint(0,0));
                    break;
                case 1:
                    p2=ui->spot2_3->mapToGlobal(QPoint(0,0));
                    break;
                case 2:
                    p2=ui->spot3_3->mapToGlobal(QPoint(0,0));
                    break;
                case 3:
                    p2=ui->spot4_3->mapToGlobal(QPoint(0,0));
                    break;
                case 4:
                    p2=ui->spot5_3->mapToGlobal(QPoint(0,0));
                    break;
                case 5:
                    p2=ui->spot6_3->mapToGlobal(QPoint(0,0));
                    break;
                case 6:
                    p2=ui->spot7_3->mapToGlobal(QPoint(0,0));
                    break;
                }
                B2X=p2.x(),B2Y=p2.y();
                drawline(B1X,B1Y,B2X,B2Y,QColor(255,0,0));
                break;
            case 2:
                p1=ui->spot3_3->mapToGlobal(QPoint(0,0));
                B1X=p1.x(),B1Y=p1.y();
                switch(sequence[i+1]){
                case 0:
                    p2=ui->spot1_3->mapToGlobal(QPoint(0,0));
                    break;
                case 1:
                    p2=ui->spot2_3->mapToGlobal(QPoint(0,0));
                    break;
                case 2:
                    p2=ui->spot3_3->mapToGlobal(QPoint(0,0));
                    break;
                case 3:
                    p2=ui->spot4_3->mapToGlobal(QPoint(0,0));
                    break;
                case 4:
                    p2=ui->spot5_3->mapToGlobal(QPoint(0,0));
                    break;
                case 5:
                    p2=ui->spot6_3->mapToGlobal(QPoint(0,0));
                    break;
                case 6:
                    p2=ui->spot7_3->mapToGlobal(QPoint(0,0));
                    break;
                }
                B2X=p2.x(),B2Y=p2.y();
                drawline(B1X,B1Y,B2X,B2Y,QColor(255,0,0));
                break;
            case 3:
                p1=ui->spot4_3->mapToGlobal(QPoint(0,0));
                B1X=p1.x(),B1Y=p1.y();
                switch(sequence[i+1]){
                case 0:
                    p2=ui->spot1_3->mapToGlobal(QPoint(0,0));
                    break;
                case 1:
                    p2=ui->spot2_3->mapToGlobal(QPoint(0,0));
                    break;
                case 2:
                    p2=ui->spot3_3->mapToGlobal(QPoint(0,0));
                    break;
                case 3:
                    p2=ui->spot4_3->mapToGlobal(QPoint(0,0));
                    break;
                case 4:
                    p2=ui->spot5_3->mapToGlobal(QPoint(0,0));
                    break;
                case 5:
                    p2=ui->spot6_3->mapToGlobal(QPoint(0,0));
                    break;
                case 6:
                    p2=ui->spot7_3->mapToGlobal(QPoint(0,0));
                    break;
                }
                B2X=p2.x(),B2Y=p2.y();
                drawline(B1X,B1Y,B2X,B2Y,QColor(255,0,0));
                break;
            case 4:
                p1=ui->spot5_3->mapToGlobal(QPoint(0,0));
                B1X=p1.x(),B1Y=p1.y();
                switch(sequence[i+1]){
                case 0:
                    p2=ui->spot1_3->mapToGlobal(QPoint(0,0));
                    break;
                case 1:
                    p2=ui->spot2_3->mapToGlobal(QPoint(0,0));
                    break;
                case 2:
                    p2=ui->spot3_3->mapToGlobal(QPoint(0,0));
                    break;
                case 3:
                    p2=ui->spot4_3->mapToGlobal(QPoint(0,0));
                    break;
                case 4:
                    p2=ui->spot5_3->mapToGlobal(QPoint(0,0));
                    break;
                case 5:
                    p2=ui->spot6_3->mapToGlobal(QPoint(0,0));
                    break;
                case 6:
                    p2=ui->spot7_3->mapToGlobal(QPoint(0,0));
                    break;
                }
                B2X=p2.x(),B2Y=p2.y();
                drawline(B1X,B1Y,B2X,B2Y,QColor(255,0,0));
                break;
            case 5:
                p1=ui->spot6_3->mapToGlobal(QPoint(0,0));
                B1X=p1.x(),B1Y=p1.y();
                switch(sequence[i+1]){
                case 0:
                    p2=ui->spot1_3->mapToGlobal(QPoint(0,0));
                    break;
                case 1:
                    p2=ui->spot2_3->mapToGlobal(QPoint(0,0));
                    break;
                case 2:
                    p2=ui->spot3_3->mapToGlobal(QPoint(0,0));
                    break;
                case 3:
                    p2=ui->spot4_3->mapToGlobal(QPoint(0,0));
                    break;
                case 4:
                    p2=ui->spot5_3->mapToGlobal(QPoint(0,0));
                    break;
                case 5:
                    p2=ui->spot6_3->mapToGlobal(QPoint(0,0));
                    break;
                case 6:
                    p2=ui->spot7_3->mapToGlobal(QPoint(0,0));
                    break;
                }
                B2X=p2.x(),B2Y=p2.y();
                drawline(B1X,B1Y,B2X,B2Y,QColor(255,0,0));
                break;
            case 6:
                p1=ui->spot7_3->mapToGlobal(QPoint(0,0));
                B1X=p1.x(),B1Y=p1.y();
                switch(sequence[i+1]){
                case 0:
                    p2=ui->spot1_3->mapToGlobal(QPoint(0,0));
                    break;
                case 1:
                    p2=ui->spot2_3->mapToGlobal(QPoint(0,0));
                    break;
                case 2:
                    p2=ui->spot3_3->mapToGlobal(QPoint(0,0));
                    break;
                case 3:
                    p2=ui->spot4_3->mapToGlobal(QPoint(0,0));
                    break;
                case 4:
                    p2=ui->spot5_3->mapToGlobal(QPoint(0,0));
                    break;
                case 5:
                    p2=ui->spot6_3->mapToGlobal(QPoint(0,0));
                    break;
                case 6:
                    p2=ui->spot7_3->mapToGlobal(QPoint(0,0));
                    break;
                }
                B2X=p2.x(),B2Y=p2.y();
                drawline(B1X,B1Y,B2X,B2Y,QColor(255,0,0));
                break;
            }
        }
    }
}

void MainWindow::on_info_clicked()
{
    Graph graph;
    graph.Init();
    Graph::Vex vexs[SIZE];
    Graph::Edge edges[SIZE*SIZE];
    memset(vexs,0,sizeof (vexs));
    memset(edges,0,sizeof (edges));
    graph.createScenicSpot(vexs,edges);
    for(int i = 0;i < 7;i++){
        graph.InsertVex(vexs[i]);
    }
    for(int i = 0;i < 11;i++){
        graph.InsertEdge(edges[i]);
    }

    QString s = ui->search->text();
    int i;
    for(i = 0;i < 7;i++)
        if(vexs[i].name == ui->search->text().toStdString()){
            s.append("\n" + QString::fromStdString(vexs[i].introduction));
            break;
        }

    if(i==7)
        int a = (QMessageBox::warning(this, tr("waring"),tr("景点名错误！")));
    else
        ui->information->setText(s);
}

void MainWindow::on_display_clicked()
{

    Graph graph;
    graph.Init();
    Graph::Vex vexs[SIZE];
    Graph::Edge temp[SIZE*SIZE];
    memset(vexs,0,sizeof (vexs));
    memset(temp,0,sizeof (temp));
    graph.createScenicSpot(vexs,temp);
    for(int i = 0;i < 7;i++){
        graph.InsertVex(vexs[i]);
    }
    for(int i = 0;i < 11;i++){
        graph.InsertEdge(temp[i]);
    }
    pix.fill(Qt::white);
    int B1X,B1Y,B2X,B2Y;
    QPoint p1,p2;
    for(int i = 0;i < 11;i++){
        switch (temp[i].vex1) {
        case 0:
            p1=ui->spot1_3->mapToGlobal(QPoint(0,0));
            B1X=p1.x(),B1Y=p1.y();
            switch(temp[i].vex2){
            case 0:
                p2=ui->spot1_3->mapToGlobal(QPoint(0,0));
                break;
            case 1:
                p2=ui->spot2_3->mapToGlobal(QPoint(0,0));
                break;
            case 2:
                p2=ui->spot3_3->mapToGlobal(QPoint(0,0));
                break;
            case 3:
                p2=ui->spot4_3->mapToGlobal(QPoint(0,0));
                break;
            case 4:
                p2=ui->spot5_3->mapToGlobal(QPoint(0,0));
                break;
            case 5:
                p2=ui->spot6_3->mapToGlobal(QPoint(0,0));
                break;
            case 6:
                p2=ui->spot7_3->mapToGlobal(QPoint(0,0));
                break;
            }
            B2X=p2.x(),B2Y=p2.y();
            drawline(B1X,B1Y,B2X,B2Y,QColor(255,0,0));
            break;
        case 1:
            p1=ui->spot2_3->mapToGlobal(QPoint(0,0));
            B1X=p1.x(),B1Y=p1.y();
            switch(temp[i].vex2){
            case 0:
                p2=ui->spot1_3->mapToGlobal(QPoint(0,0));
                break;
            case 1:
                p2=ui->spot2_3->mapToGlobal(QPoint(0,0));
                break;
            case 2:
                p2=ui->spot3_3->mapToGlobal(QPoint(0,0));
                            //printf("x1:%d y1:%d x2:%d y2:%d \n",B1X,B1Y,B2X,B2Y);
                break;
            case 3:
                p2=ui->spot4_3->mapToGlobal(QPoint(0,0));
                break;
            case 4:
                p2=ui->spot5_3->mapToGlobal(QPoint(0,0));
                break;
            case 5:
                p2=ui->spot6_3->mapToGlobal(QPoint(0,0));
                break;
            case 6:
                p2=ui->spot7_3->mapToGlobal(QPoint(0,0));
                break;
            }
            B2X=p2.x(),B2Y=p2.y();
            drawline(B1X,B1Y,B2X,B2Y,QColor(255,0,0));
            break;
        case 2:
            p1=ui->spot3_3->mapToGlobal(QPoint(0,0));
            B1X=p1.x(),B1Y=p1.y();
            switch(temp[i].vex2){
            case 0:
                p2=ui->spot1_3->mapToGlobal(QPoint(0,0));
                break;
            case 1:
                p2=ui->spot2_3->mapToGlobal(QPoint(0,0));
                break;
            case 2:
                p2=ui->spot3_3->mapToGlobal(QPoint(0,0));
                break;
            case 3:
                p2=ui->spot4_3->mapToGlobal(QPoint(0,0));
                break;
            case 4:
                p2=ui->spot5_3->mapToGlobal(QPoint(0,0));
                break;
            case 5:
                p2=ui->spot6_3->mapToGlobal(QPoint(0,0));
                break;
            case 6:
                p2=ui->spot7_3->mapToGlobal(QPoint(0,0));
                break;
            }
            B2X=p2.x(),B2Y=p2.y();
            drawline(B1X,B1Y,B2X,B2Y,QColor(255,0,0));
            break;
        case 3:
            p1=ui->spot4_3->mapToGlobal(QPoint(0,0));
            B1X=p1.x(),B1Y=p1.y();
            switch(temp[i].vex2){
            case 0:
                p2=ui->spot1_3->mapToGlobal(QPoint(0,0));
                break;
            case 1:
                p2=ui->spot2_3->mapToGlobal(QPoint(0,0));
                break;
            case 2:
                p2=ui->spot3_3->mapToGlobal(QPoint(0,0));
                break;
            case 3:
                p2=ui->spot4_3->mapToGlobal(QPoint(0,0));
                break;
            case 4:
                p2=ui->spot5_3->mapToGlobal(QPoint(0,0));
                break;
            case 5:
                p2=ui->spot6_3->mapToGlobal(QPoint(0,0));
                break;
            case 6:
                p2=ui->spot7_3->mapToGlobal(QPoint(0,0));
                break;
            }
            B2X=p2.x(),B2Y=p2.y();
            drawline(B1X,B1Y,B2X,B2Y,QColor(255,0,0));
            break;
        case 4:
            p1=ui->spot5_3->mapToGlobal(QPoint(0,0));
            B1X=p1.x(),B1Y=p1.y();
            switch(temp[i].vex2){
            case 0:
                p2=ui->spot1_3->mapToGlobal(QPoint(0,0));
                break;
            case 1:
                p2=ui->spot2_3->mapToGlobal(QPoint(0,0));
                break;
            case 2:
                p2=ui->spot3_3->mapToGlobal(QPoint(0,0));
                break;
            case 3:
                p2=ui->spot4_3->mapToGlobal(QPoint(0,0));
                break;
            case 4:
                p2=ui->spot5_3->mapToGlobal(QPoint(0,0));
                break;
            case 5:
                p2=ui->spot6_3->mapToGlobal(QPoint(0,0));
                break;
            case 6:
                p2=ui->spot7_3->mapToGlobal(QPoint(0,0));
                break;
            }
            B2X=p2.x(),B2Y=p2.y();
            drawline(B1X,B1Y,B2X,B2Y,QColor(255,0,0));
            break;
        case 5:
            p1=ui->spot6_3->mapToGlobal(QPoint(0,0));
            B1X=p1.x(),B1Y=p1.y();
            switch(temp[i].vex2){
            case 0:
                p2=ui->spot1_3->mapToGlobal(QPoint(0,0));
                break;
            case 1:
                p2=ui->spot2_3->mapToGlobal(QPoint(0,0));
                break;
            case 2:
                p2=ui->spot3_3->mapToGlobal(QPoint(0,0));
                break;
            case 3:
                p2=ui->spot4_3->mapToGlobal(QPoint(0,0));
                break;
            case 4:
                p2=ui->spot5_3->mapToGlobal(QPoint(0,0));
                break;
            case 5:
                p2=ui->spot6_3->mapToGlobal(QPoint(0,0));
                break;
            case 6:
                p2=ui->spot7_3->mapToGlobal(QPoint(0,0));
                break;
            }
            B2X=p2.x(),B2Y=p2.y();
            drawline(B1X,B1Y,B2X,B2Y,QColor(255,0,0));
            break;
        case 6:
            p1=ui->spot7_3->mapToGlobal(QPoint(0,0));
            B1X=p1.x(),B1Y=p1.y();
            switch(temp[i].vex2){
            case 0:
                p2=ui->spot1_3->mapToGlobal(QPoint(0,0));
                break;
            case 1:
                p2=ui->spot2_3->mapToGlobal(QPoint(0,0));
                break;
            case 2:
                p2=ui->spot3_3->mapToGlobal(QPoint(0,0));
                break;
            case 3:
                p2=ui->spot4_3->mapToGlobal(QPoint(0,0));
                break;
            case 4:
                p2=ui->spot5_3->mapToGlobal(QPoint(0,0));
                break;
            case 5:
                p2=ui->spot6_3->mapToGlobal(QPoint(0,0));
                break;
            case 6:
                p2=ui->spot7_3->mapToGlobal(QPoint(0,0));
                break;
            }
            B2X=p2.x(),B2Y=p2.y();
            drawline(B1X,B1Y,B2X,B2Y,QColor(255,0,0));
            break;
        }
    }
}
