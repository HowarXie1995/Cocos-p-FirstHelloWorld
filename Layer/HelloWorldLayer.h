#ifndef __HelloWorldLayer_H__
#define __HelloWorldLayer_H__

#include <iostream>
#include "cocos2d.h" 
USING_NS_CC;

class HelloWorldLayer:public Layer
{
public:
	//创建HelloWorldLayer类的对象的方法
	//CREATE_FUNC(HelloWorldLayer);		//原HelloWorld是使用宏来实现创建 类对象的方法///？？好绕
	static HelloWorldLayer * create();
	//定义一个初始化方法
	virtual bool init();

	//点击按钮close的回调函数
	void menuCloseCallBack(Ref * pSender);

	
};

#endif /*define (__HelloWorldLayer_H__)*/
