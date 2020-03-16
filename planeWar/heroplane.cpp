#include "heroplane.h"
#include "config.h"
HeroPlane::HeroPlane()
{
    //初始化加载飞机图片资源
    m_Plane.load(HERO_PATH);

    //初始化坐标
    m_X = GAME_WIDTH * 0.5 - m_Plane.width()*0.5;
    m_Y = GAME_HEIGHT - m_Plane.height();

    //初始化矩形框
    m_Rect.setWidth(m_Plane.width());    //设置检测框的宽度和长度
    m_Rect.setHeight(m_Plane.height());
    m_Rect.moveTo(m_X,m_Y);              //把矩形框移动倒飞机中点

    //初始化子弹发射间隔记录
    m_recorder = 0;


}

void HeroPlane::shoot()
{

    //累加时间间隔记录变量
    m_recorder++;
    //判断如果记录数字 未达到发射间隔，直接return
    if(m_recorder < BULLET_INTERVAL)
    {
    return;
    }
    //到达发射时间处理
    //重置发射时间间隔记录
    m_recorder = 0;

    //发射子弹
    for(int i = 0 ; i < BULLET_NUM;i++)
    {
    //如果是空闲的子弹进行发射
    if(m_bullets[i].m_Free)
    {
        //将改子弹空闲状态改为假
        m_bullets[i].m_Free = false;
        //设置发射的子弹坐标
        m_bullets[i].m_X = m_X + m_Rect.width()*0.5 - 10;  //点睛之笔！！！
        m_bullets[i].m_Y = m_Y - 25 ;                      //在发射子弹的同时更新已经超过屏幕的子弹位置，牛逼！！！
        break;                                             //这里要注意用break,不然30发子弹全部射出去了
    }
    }

}

void HeroPlane::setPosition(int x, int y)
{
    m_X = x;                //鼠标位置给飞机
    m_Y = y;
    m_Rect.moveTo(m_X,m_Y);//检测框更新位置

}
