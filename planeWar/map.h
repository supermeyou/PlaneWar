#ifndef MAP_H
#define MAP_H
#include <QPixmap>

class Map
{

public:
    //构造函数
    Map();
    //地图滚动坐标计算
    void mapPosition();

public:
    //地图图片对象
    QPixmap m_map1;//两张互补的图片，便于滚动无视觉差
    QPixmap m_map2;
    //地图Y轴坐标，X坐标固定不用计算，因为X方向不用滚动
    int m_map1_posY;
    int m_map2_posY;
    //地图滚动幅度，滚动的速度
    int m_scroll_speed;
};


#endif // MAP_H
