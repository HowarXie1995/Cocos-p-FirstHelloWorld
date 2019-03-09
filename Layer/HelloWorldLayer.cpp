#include "HelloWorldLayer.h"

#ifdef WIN32
#pragma execution_character_set("utf-8")
#endif

HelloWorldLayer * HelloWorldLayer::create()
{
	//1��ΪHelloWorldLayyer����һ���ڴ�ռ�
	HelloWorldLayer * pRet = new HelloWorldLayer();
	//2��pRet�ɹ����������ҳɹ���ʼ��
	if (pRet && pRet->init())
	{
		pRet->autorelease();	//��Ӷ����Զ��ͷų���
		return pRet;			//Ȼ�󷵻ض���
	}
	else
	{
		CC_SAFE_DELETE(pRet);	//ɾ������
		return NULL;			//���ؿ�
	}
		
	return nullptr;
}

bool HelloWorldLayer::init()
{
	//�������õı��ϰ��
	if (!Layer::init())
	{
		return false;
	}
	//1����ȡ��Ļ���ĵ������
	Size size = Director::getInstance()->getVisibleSize();

	//2��������ǩ
	Label * label = Label::createWithTTF("��ҹ", "fonts/white.ttf", 56);
	label->setPosition(Vec2(size.width / 2, size.height * 3 / 4));
	this->addChild(label);

	//3�����һ������
	auto sprite = Sprite::create("HelloWorld.png");
	sprite->setPosition(Vec2(size.width / 2, size.height / 2));
	this->addChild(sprite);

	//4����Ӱ�ť�˵�
	auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(HelloWorldLayer::menuCloseCallBack, this));
	closeItem->setPosition(Vec2(900, 100));

	auto menu = Menu::create(closeItem, NULL);		//����кܶ���ѡ���������������
													//����һ��NULL
	menu->setPosition(Point::ZERO);
	this->addChild(menu);

	return true;
}

void HelloWorldLayer::menuCloseCallBack(Ref * pSender)
{
}
