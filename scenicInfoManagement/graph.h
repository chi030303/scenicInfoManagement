#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <QPainter>
#define SIZE 10
using namespace std;

class Graph{
public:
    struct Vex{
        int num;//节点数字
        string name;//节点名称
        string introduction;//节点介绍（景点介绍）
    };

    struct Edge{
        int vex1;//点1
        int vex2;//点2
        int weight;//权重
    };

    void Init();//初始化Graph类
    bool InsertVex(Vex vex);//添加点到vexs数组中
    bool InsertEdge(Edge edge);//将边edge的信息保存到邻接矩阵matrix中
    Vex getVet(string name);//查询点的信息
    int FindEdge(int nVex,Edge edges[]);//查询与一个点相连的边
    int getVexNum();//得到当前点的个数
    int FindShortPath(int start,int end,string &path);//找到两点间最短路径
    void MST(Edge edges[]);//构造最小生成树
    void traversal();
    void DFS(int nVex,bool visited[],int sequence[],int &index);//用深度优先搜索遍历图
    void createScenicSpot(Vex vexs[],Edge edges[]);//创建景点
private:
    int matrix[SIZE][SIZE];//邻接矩阵
    Vex vexs[SIZE];
    int vexnum;
};

#endif // GRAPH_H
