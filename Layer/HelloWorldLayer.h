#ifndef __HelloWorldLayer_H__
#define __HelloWorldLayer_H__

#include <iostream>
#include "cocos2d.h" 
USING_NS_CC;

class HelloWorldLayer:public Layer
{
public:
	//����HelloWorldLayer��Ķ���ķ���
	//CREATE_FUNC(HelloWorldLayer);		//ԭHelloWorld��ʹ�ú���ʵ�ִ��� �����ķ���///��������
	static HelloWorldLayer * create();
	
};

#endif /*define (__HelloWorldLayer_H__)*/