#include<fstream>
#include<iostream>
using namespace std;
bool flag1[280000]={0};//标志数组
bool flag2 = 0;
unsigned int vertex1[280000]={0};//第一列数据
unsigned int vertex2[280000]={0};//第二列数据
int numhuan=0;//找到多少个环
int vexnum ;//节点个数
int arcnum ;//边的个数
int jichong;//记录当前dfs到了第几代子节点
int qidian = 0;//dfs的起始节点序号
struct ArcNode
{
     int adjvex; //存放与表头节点相邻接的顶点在数组中的序号
	 ArcNode *next;//指向兄弟节点
};
struct VNode
{
    unsigned int vertex; //存放顶点的信息
    ArcNode *link; //指向下一个结点
};
struct AdjGraph
{
   VNode adjlist[280000]; //邻接链表表头
};
struct baocunhuanx
{
    unsigned int cunhuanx[7];//保存环的路径
    int huanchang;//保存这个环的长短
};
struct baocunhuan
{
    baocunhuanx cunhuany[3000000];//包存环
};
baocunhuan huan1;
AdjGraph adjg;
/*深度遍历找环大于7退出，叶子节点退出*/
baocunhuanx hua;
void dfs(int v)
{
   int i=0;
   ArcNode *p2;
   flag1[v]=1;
   hua.cunhuanx[jichong]=adjg.adjlist[v].vertex;
   jichong++;
   p2=adjg.adjlist[v].link;
   while((p2!=NULL))
    {
	   if((flag1[p2->adjvex]==0)&&(jichong<7)&&(adjg.adjlist[p2->adjvex].vertex>adjg.adjlist[qidian].vertex))
	   {
	      dfs(p2->adjvex);
	   }
       if((p2->adjvex==qidian)&&(jichong>2))
       {
                huan1.cunhuany[numhuan]=hua;
                huan1.cunhuany[numhuan].huanchang=jichong;
                numhuan++;
       }
     p2=p2->next;
    }
    flag1[v]=0;
    jichong--;
    hua.cunhuanx[jichong]=0;
}
//快速排序
void quick_sort3( int kaishi ,int jieshu)
{
    int mystack[512];
    int top=-1;
    mystack[++top] = kaishi;
    mystack[++top] = jieshu;
    while(top>0)
    {
        baocunhuanx cc;
        int wei = mystack[top--];
        int tou = mystack[top--];
        baocunhuanx x = huan1.cunhuany[wei];
        int iii = tou-1;
        int jjj=  tou;
        for (int jjj = tou; jjj < wei; jjj++)
        {
            if (huan1.cunhuany[jjj].huanchang < x.huanchang)
            {
                iii++;
                cc = huan1.cunhuany[iii];
                huan1.cunhuany[iii]=huan1.cunhuany[jjj];
                huan1.cunhuany[jjj]=cc;
            }
            else if(huan1.cunhuany[jjj].huanchang == x.huanchang )
            {
                if(huan1.cunhuany[jjj].cunhuanx[0] < x.cunhuanx[0])
                {
                     iii++;
                     cc = huan1.cunhuany[iii];
                     huan1.cunhuany[iii]=huan1.cunhuany[jjj];
                     huan1.cunhuany[jjj]=cc;

                }
                else if(huan1.cunhuany[jjj].cunhuanx[0] == x.cunhuanx[0] )
                {
                      if(huan1.cunhuany[jjj].cunhuanx[1] < x.cunhuanx[1])
                            {
                                iii++;
                                cc = huan1.cunhuany[iii];
                                huan1.cunhuany[iii]=huan1.cunhuany[jjj];
                                huan1.cunhuany[jjj]=cc;
                            }
                      else if(huan1.cunhuany[jjj].cunhuanx[1] == x.cunhuanx[1] )
                      {
                            if(huan1.cunhuany[jjj].cunhuanx[2] < x.cunhuanx[2] )
                            {
                                  iii++;
                                  cc = huan1.cunhuany[iii];
                                  huan1.cunhuany[iii]=huan1.cunhuany[jjj];
                                  huan1.cunhuany[jjj]=cc;
                            }
                            else if(huan1.cunhuany[jjj].cunhuanx[2] == x.cunhuanx[2] )
                            {
                                   if(huan1.cunhuany[jjj].cunhuanx[3] < x.cunhuanx[3] )
                                    {
                                         iii++;
                                         cc = huan1.cunhuany[iii];
                                         huan1.cunhuany[iii]=huan1.cunhuany[jjj];
                                         huan1.cunhuany[jjj]=cc;
                                    }
                                    else if(huan1.cunhuany[jjj].cunhuanx[3] == x.cunhuanx[3] )
                                    {
                                          if(huan1.cunhuany[jjj].cunhuanx[4] < x.cunhuanx[4] )
                                          {
                                                iii++;
                                                 cc = huan1.cunhuany[iii];
                                                huan1.cunhuany[iii]=huan1.cunhuany[jjj];
                                                 huan1.cunhuany[jjj]=cc;
                                          }
                                          else if(huan1.cunhuany[jjj].cunhuanx[4] == x.cunhuanx[4] )
                                          {
                                                if(huan1.cunhuany[jjj].cunhuanx[5] <x.cunhuanx[5] )
                                                {
                                                       iii++;
                                                       cc = huan1.cunhuany[iii];
                                                        huan1.cunhuany[iii]=huan1.cunhuany[jjj];
                                                        huan1.cunhuany[jjj]=cc;
                                                }

                                                else if(huan1.cunhuany[jjj].cunhuanx[5] == x.cunhuanx[5] )
                                                {
                                                     if(huan1.cunhuany[jjj].cunhuanx[6] <x.cunhuanx[6] )
                                                     {
                                                           iii++;
                                                           cc = huan1.cunhuany[iii];
                                                           huan1.cunhuany[iii]=huan1.cunhuany[jjj];
                                                           huan1.cunhuany[jjj]=cc;
                                                      }
                                                     else if(huan1.cunhuany[jjj].cunhuanx[6] == x.cunhuanx[6] )
                                                      {
                                                            if(huan1.cunhuany[jjj].cunhuanx[7] <x.cunhuanx[7] )
                                                            {
                                                                 iii++;
                                                                 cc = huan1.cunhuany[iii];
                                                                 huan1.cunhuany[iii]=huan1.cunhuany[jjj];
                                                                 huan1.cunhuany[jjj]=cc;
                       }}}}}}}}}}




                cc = huan1.cunhuany[iii+1];
                huan1.cunhuany[iii+1]=huan1.cunhuany[wei];
                huan1.cunhuany[wei]=cc;
        if (tou < iii)
        {
            mystack[++top]=tou;
            mystack[++top]=iii;
        }
        if (iii+2 < wei)
        {
            mystack[++top] = iii+2;
            mystack[++top] = wei;
        }
    }
}

void quickSort2( int kaishi ,int jieshu)
{
    int mystack[1024];
    int top=-1;
    mystack[++top] = kaishi;
    mystack[++top] = jieshu;
    while(top>0)
    {
        unsigned int cc1;
        unsigned int cc2;
        int wei = mystack[top--];
        int tou = mystack[top--];
        unsigned int x = adjg.adjlist[wei].vertex;
        int i = tou-1;
        int j=  tou;
        for (int j = tou; j < wei; j++)
        {
            if (adjg.adjlist[j].vertex < x)
            {
                i++;
                cc1 = adjg.adjlist[i].vertex;

                adjg.adjlist[i].vertex=adjg.adjlist[j].vertex;

                adjg.adjlist[j].vertex=cc1;

            }
        }
                cc1 =adjg.adjlist[i+1].vertex;

                adjg.adjlist[i+1].vertex=adjg.adjlist[wei].vertex;

                adjg.adjlist[wei].vertex=cc1;

        if (tou < i)
        {
            mystack[++top]=tou;
            mystack[++top]=i;
        }
        if (i+2 < wei)
        {
            mystack[++top] = i+2;
            mystack[++top] = wei;
        }
    }
}


int main()
{
    bool flagid=1;
    int j;
    int jj;
    int jjj;
    int i;
    char a ;
    char buf[32]={0};
    char bufc;
    int vexnum =0;//节点个数
    int arcnum =0;//边个数
    ifstream ifs;
    ifs.open("/data/test_data.txt",ios::in);
    //建立邻接表
    while (ifs >> vertex1[arcnum])
    {
        ifs >> bufc;
        ifs >> vertex2[arcnum];
        ifs >> buf;
        vertex1[arcnum]++;
        vertex2[arcnum]++;
        arcnum++;
    }
    ArcNode *p;

    for(i=0;i<arcnum;i++)
    {
        for(j=0;j<vexnum;j++)
        {
            if(adjg.adjlist[j].vertex==vertex1[i])
            {
                flagid=0;
                break;
            }

        }
        if(flagid)
        {
            adjg.adjlist[vexnum].vertex = vertex1[i];
	        adjg.adjlist[vexnum].link = NULL;
	        vexnum++;
        }
         flagid=1;
    }
    quickSort2( 0 ,vexnum-1);
    for(i=0;i<arcnum;i++)
    {
        flagid=0;

        /*for(jj=0;jj<vexnum;jj++)
        {
            if(adjg.adjlist[jj].vertex==vertex1[i])
            {
                break;
            }
        }
        for(jjj=0;jjj<vexnum;jjj++)
        {
            if(adjg.adjlist[jjj].vertex==vertex2[i])
            {
                flagid=1;
                break;
            }
        }*/
        int left = 0;
        int right = vexnum-1 ;
        while (left < right)
       {
            int mid = (left + right) / 2;
            if (adjg.adjlist[mid].vertex < vertex1[i])
                left = mid + 1;
            else
                right = mid;
        }
        if (adjg.adjlist[left].vertex == vertex1[i])
       {
            jj= left;
       }
        left = 0;
        right = vexnum-1 ;
        while (left < right)
       {
            int mid = (left + right) / 2;
            if (adjg.adjlist[mid].vertex < vertex2[i])
                left = mid + 1;
            else
                right = mid;
        }
        if (adjg.adjlist[left].vertex == vertex2[i])
        {
            jjj= left;
            flagid=1;
        }
        if(flagid)
        {
            p=new ArcNode;
	        p->adjvex=jjj;
	        p->next=adjg.adjlist[jj].link;
	        adjg.adjlist[jj].link=p;
        }
    }
    //找环
    for(i=0;i<vexnum;i++)
    {
        qidian = i;
	    dfs(i);
    }
    //排序
    quick_sort3(0,numhuan-1);
    //输出到TXT
    ofstream ofs;
    ofs.open("/projects/student/result.txt",ios::out);
    ofs << numhuan << "\n";
    for(i=0;i<numhuan;i++)
    {
        a=0;
        ofs <<huan1.cunhuany[i].cunhuanx[a]-1;
        for(a=1;a<huan1.cunhuany[i].huanchang;a++)
        {
            ofs << ","<<huan1.cunhuany[i].cunhuanx[a]-1 ;

        }
        ofs <<"\n";
    }
    return 0;
}
