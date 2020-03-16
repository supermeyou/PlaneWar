#include "map.h"
#include "config.h"

Map::Map()
{
    //初始化加载地图对象，对应路劲
    m_map1.load(MAP_PATH);
    m_map2.load(MAP_PATH);
    //设置地图其实y轴坐标，两张图片的坐标初始化
    m_map1_posY = -GAME_HEIGHT;
    m_map2_posY = 0;

    //设置地图滚动速度
    m_scroll_speed=MAP_SCROLL_SPEED;
}

void Map::mapPosition()
{
   //两张地图的坐标移动处理
   m_map1_posY+=m_scroll_speed;
   if(m_map1_posY>=0)
   {
     m_map1_posY = -GAME_HEIGHT;
   }

   m_map2_posY+=m_scroll_speed;
   if(m_map2_posY>=GAME_HEIGHT)
   {
     m_map2_posY = 0;
   }
}
