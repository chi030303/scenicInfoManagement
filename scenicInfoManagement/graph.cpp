#include <iostream>
#include "graph.h"
#include <string.h>
#define INFINITY 99999
void Graph::Init(){
    vexnum = 0;//初始化点的数量
    memset(matrix,0,sizeof(matrix));//初始化当前的图（点、边、权重）
    memset(vexs,0,sizeof(vexs));//初始化当前的点
}

bool Graph::InsertVex(Vex vex){
    if(vexnum!=SIZE){
    vexs[vexnum].num = vex.num;
    vexs[vexnum].name = vex.name;
    vexs[vexnum++].introduction = vex.introduction;
    }
    else
    return false;
    return true;
}

bool Graph::InsertEdge(Edge edge){
    for(int i = 0;i < vexnum;i++)
        for(int j = 0;j < vexnum;j++)
            if(i == edge.vex1 && j == edge.vex2){
                matrix[i][j] = edge.weight;
                return true;
            }
    return false;
}

Graph::Vex Graph::getVet(string name){
    for(int i = 0;i < vexnum;i++)
        if(name == vexs[i].name)
           return vexs[i];
}

int Graph::FindEdge(int nVex,Edge edges[]){
    int index = 0;
    for(int j = 0;j < vexnum;j++)
        if(matrix[nVex][j]!=0){
            edges[index].vex1 = nVex;
            edges[index].vex2 = j;
            edges[index++].weight = matrix[nVex][j];
        }
    return index;
}

int Graph::getVexNum(){
    return vexnum;
}

void Graph::traversal(){
    for(int i = 0;i < vexnum;i++){
        for(int j = 0;j < vexnum;j++)
           printf("row:%d col:%d value:%d ",i,j,matrix[i][j]);
        printf("\n");
    }//matrix
}

void Graph::DFS(int nVex,bool visited[],int sequence[],int &index){
    int tempMatrix[vexnum][vexnum];
    memset(tempMatrix,0,sizeof(tempMatrix));

    for(int i = 0;i < vexnum;i++)
        for(int j = 0;j < vexnum;j++)
            if(matrix[i][j]!=0 && matrix[j][i] == 0){
               tempMatrix[i][j] = matrix[i][j];
               tempMatrix[j][i] = matrix[i][j];
            }
    for(int i = 0;i < vexnum;i++)
       for(int j = 0;j  < vexnum;j++){
           if(tempMatrix[nVex][j]!=0 && !visited[j]){
              visited[j] = true;
              sequence[index++] = j;
              DFS(j,visited,sequence,index);
              printf("j:%d  ",j);
           }
       }
}

//找到两点间最短路径
int Graph::FindShortPath(int start,int end,string &path2){
    int distance[vexnum][vexnum];
    int tempMatrix[vexnum][vexnum];
    memset(tempMatrix,0,sizeof(tempMatrix));

    for(int i = 0;i < vexnum;i++)
        for(int j = 0;j < vexnum;j++)
            if(matrix[i][j]!=0 && matrix[j][i] == 0){
               tempMatrix[i][j] = matrix[i][j];
               tempMatrix[j][i] = matrix[i][j];
            }
    string path[vexnum][vexnum];
    //初始化路径矩阵
    for(int i = 0;i < vexnum;i++)
        for(int j = 0;j < vexnum;j++){
            distance[i][j] = tempMatrix[i][j];
            path[i][j] += to_string(j);
        }
    int sequence[7];
    memset(sequence,-1,sizeof (sequence));
    int sign1 = 0,sign2 = 0;
    for(int i = start;i < vexnum;i++)//没有判断何时起止
        for(int j = 0;j < vexnum;j++)
              //sign2 = 0;
              if(i != j)
                 for(int k = 0;k < vexnum;k++)
                    if(distance[i][j]!=0 && distance[j][k]!=0 && sign2 == 0){//&& sign1 == -1 && sign2 == 0
                        if((distance[i][k] > distance[i][j] + distance[j][k])||distance[i][k] == 0){
                            distance[i][k] = distance[i][j] + distance[j][k];
                            path[i][k] += to_string(j);
                            printf("i:%d j:%d k:%d",i,j,k);
                        }
                        if(k == end)
                            sign2 = -1;
                    }
        path2 = path[start][end] += to_string(start);
        //s = s.reserve();
        cout << start << "->"  << end << ":" << path[start][end];
        printf(" shortestpath:%d ",distance[start][end]);
        printf(" path:%s ",path2.c_str());
        cout << endl;
        return distance[start][end];
}


//构造最小生成树
void Graph::MST(Edge tree[]){
    int n = 0,min = INFINITY,tempMatrix[vexnum][vexnum],temp = 0;
    int cloest[vexnum],lowcost[vexnum];//closet为顶点i的最近邻点，lowcost存放（i,cloest[i]）的权值
    Edge e[vexnum-1];//从每个点出去的边
    memset(cloest,0,sizeof(cloest));
    memset(lowcost,0,sizeof(lowcost));
    memset(tempMatrix,0,sizeof(tempMatrix));

    for(int i = 0;i < vexnum;i++)
        for(int j = 0;j < vexnum;j++)
            if(matrix[i][j]!=0 && matrix[j][i] == 0){//
               tempMatrix[i][j] = matrix[i][j];
               tempMatrix[j][i] = matrix[i][j];
            }

    for(int i = 0;i < vexnum;i++){
        min = INFINITY;
        for(int j = 0;j < vexnum;j++){
            if(tempMatrix[i][j]!=0){
               temp = min;
               min = (min < tempMatrix[i][j])?min:tempMatrix[i][j];
               if(min != temp)
               cloest[i] = j;
            }
        }
        lowcost[i] = min;
    }

    cout << "MST: ";
    for(int i = 0;i < vexnum;i++){
        //cout << i << "——" << cloest[i] ;
        cout << "i: " << i << "  " << cloest[i] ;
    }

    cout << "  lowcost: ";
    for(int i = 0;i < vexnum;i++){
        //cout << i << "——" << cloest[i] ;
        cout << "i: " << i << "  " << lowcost[i] ;
    }
    for(int i = 0;i < vexnum;i++){
        tree[i].vex1 = i;
        tree[i].vex2 = cloest[i];
        tree[i].weight = lowcost[i];
    }
}

//创建景点图
void Graph::createScenicSpot(Vex vexs[],Edge edges[]){
    //创建点
    vexs[0].num = 0;
    vexs[0].name = "颐和园";
    vexs[0].introduction = "颐和园，中国清朝时期皇家园林，前身为清漪园，坐落在北京西郊，距城区15公里，全园占地3.009平方公里（其中颐和园世界文化遗产区面积为2.97平方公里），水面约占四分之三。与圆明园毗邻。它是以昆明湖、万寿山为基址，以杭州西湖为蓝本，汲取江南园林的设计手法而建成的一座大型山水园林，也是保存最完整的一座皇家行宫御苑，被誉为“皇家园林博物馆”。";
    vexs[1].num = 1;
    vexs[1].name = "天安门";
    vexs[1].introduction = "天安门（Tian'anmen），坐落在中华人民共和国首都北京市的中心、故宫的南端，与天安门广场以及人民英雄纪念碑、毛主席纪念堂、人民大会堂、中国国家博物馆隔长安街相望，占地面积4800平方米，以杰出的建筑艺术和特殊的政治地位为世人所瞩目。";
    vexs[2].num = 2;
    vexs[2].name = "长城";
    vexs[2].introduction = "长城（the Great Wall），又称万里长城，是中国古代的军事防御工事，是一道高大、坚固而且连绵不断的长垣，用以限隔敌骑的行动。长城不是一道单纯孤立的城墙，而是以城墙为主体，同大量的城、障、亭、标相结合的防御体系。";
    vexs[3].num = 3;
    vexs[3].name = "鸟巢";
    vexs[3].introduction = "国家体育场（鸟巢），位于北京奥林匹克公园中心区南部，为2008年北京奥运会的主体育场，占地20.4万平米 ，建筑面积25.8万平方米，可容纳观众9.1万人举行了奥运会、残奥会开闭幕式、田径比赛及足球比赛决赛。奥运会后成为北京市民参与体育活动及享受体育娱乐的大型专业场所，并成为地标性的体育建筑和奥运遗产";
    vexs[4].num = 4;
    vexs[4].name = "北京交通大学";
    vexs[4].introduction = "北京交通大学（Beijing Jiaotong University），位于北京市，是中华人民共和国教育部直属，教育部、交通运输部、北京市人民政府、中国国家铁路集团有限公司共建的全国重点大学，是国家“双一流”建设高校、  “211工程”建设高校、先后入选“985工程优势学科创新平台”、高等学校创新能力提升计划、“111计划”、卓越工程师教育培养计划。";
    vexs[5].num = 5;
    vexs[5].name = "天坛";
    vexs[5].introduction = "天坛公园在北京市南部，东城区永定门内大街东侧。占地约273万平方米。天坛始建于明永乐十八年（1420年），清乾隆、光绪时曾重修改建。现为世界文化遗产，全国重点文物保护单位，国家AAAAA级旅游景区，全国文明风景旅游区示范点。";
    vexs[6].num = 6;
    vexs[6].name = "香山公园";
    vexs[6].introduction = "香山公园（Fragrant Hills Park），位于北京市海淀区买卖街40号，北京市区西北郊，占地188公顷，是一座具有山林特色的皇家园林。景区内主峰香炉峰俗称“鬼见愁”，海拔575米。早在元、明、清时，皇家就在香山营建离宫别院，每逢夏秋时节皇帝都要到此狩猎纳凉。咸丰十年（1860年）和光绪二十六年（1900年）先后两次被英法联军、八国联军焚毁，1956年开辟为人民公园。 香山公园有香山寺、洪光寺、双清别墅等著名旅游景点。";

    //创建边
    edges[0].vex1 = 0;
    edges[0].vex2 = 1;
    edges[0].weight = 1000;
    edges[1].vex1 = 0;
    edges[1].vex2 = 2;
    edges[1].weight = 2000;
    edges[2].vex1 = 0;
    edges[2].vex2 = 3;
    edges[2].weight = 500;
    edges[3].vex1 = 0;
    edges[3].vex2 = 4;
    edges[3].weight = 1500;
    edges[4].vex1 = 0;
    edges[4].vex2 = 5;
    edges[4].weight = 3000;
    edges[5].vex1 = 0;
    edges[5].vex2 = 6;
    edges[5].weight = 300;
    edges[6].vex1 = 1;
    edges[6].vex2 = 2;
    edges[6].weight = 1000;
    edges[7].vex1 = 2;
    edges[7].vex2 = 3;
    edges[7].weight = 700;
    edges[8].vex1 = 3;
    edges[8].vex2 = 4;
    edges[8].weight = 3200;
    edges[9].vex1 = 4;
    edges[9].vex2 = 5;
    edges[9].weight = 3100;
    edges[10].vex1 = 5;
    edges[10].vex2 = 6;
    edges[10].weight = 1200;
}
