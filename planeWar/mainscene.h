#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include <QTimer>
#include <map.h>
#include "heroplane.h"
#include "bullet.h"
#include "enemyplane.h"
#include "bomb.h"
#include <QSound>
#include <QMediaPlayer>
class MainScene : public QWidget
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = 0);

    //初始化场景
    void initScene();
    //启动游戏 用于启动定时器对象
    void playGame();
    //更新坐标
    void updatePosition();
    //敌机出场
    void enemyToScene();
    //碰撞检测函数
    void collisionDetection();
    //绘图事件
    void paintEvent(QPaintEvent *event);
    //鼠标移动事件
    void mouseMoveEvent(QMouseEvent *event);  //这里是重新写中断函数
    //地图对象
    Map m_map;
    //飞机对象
    HeroPlane m_hero;
//    //测试子弹代码
//    Bullet temp_bullet;
    //定时器
    QTimer m_Timer;

    //敌机数组
    EnemyPlane m_enemys[ENEMY_NUM];

    //敌机出场间隔记录
    int m_recorder;
    //爆炸数组
    Bomb m_bombs[BOMB_NUM];

//     QSound sound;
    QSound *sound = new QSound(SOUND_BACKGROUND, this); //构建对象
    QSound *soundBOM=new QSound(SOUND_BOMB,this);
    ~MainScene();
};

#endif // MAINSCENE_H
