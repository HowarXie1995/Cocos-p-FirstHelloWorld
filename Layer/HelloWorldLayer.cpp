#include "HelloWorldLayer.h"

#ifdef WIN32
#pragma execution_character_set("utf-8")
#endif

HelloWorldLayer * HelloWorldLayer::create()
{
	//1、为HelloWorldLayyer分配一块内存空间
	HelloWorldLayer * pRet = new HelloWorldLayer();
	//2、pRet成功创建，并且成功初始化
	if (pRet && pRet->init())
	{
		pRet->autorelease();	//添加对象到自动释放池里
		return pRet;			//然后返回对象
	}
	else
	{
		CC_SAFE_DELETE(pRet);	//删除对象
		return NULL;			//返回空
	}
		
	return nullptr;
}

bool HelloWorldLayer::init()
{
	//养成良好的编程习惯
	if (!Layer::init())
	{
		return false;
	}
	//1、获取屏幕中心点的坐标
	Size size = Director::getInstance()->getVisibleSize();

	//2、创建标签
	Label * label = Label::createWithTTF("黑夜", "fonts/white.ttf", 56);
	label->setPosition(Vec2(size.width / 2, size.height * 3 / 4));
	this->addChild(label);

	//3、添加一个精灵
	auto sprite = Sprite::create("HelloWorld.png");
	sprite->setPosition(Vec2(size.width / 2, size.height / 2));
	this->addChild(sprite);

	//4、添加按钮菜单
	auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(HelloWorldLayer::menuCloseCallBack, this));
	closeItem->setPosition(Vec2(900, 100));

	auto menu = Menu::create(closeItem, NULL);		//如果有很多子选项可在下面继续添加
													//最后加一句NULL
	menu->setPosition(Point::ZERO);
	this->addChild(menu);

	return true;
}

void HelloWorldLayer::menuCloseCallBack(Ref * pSender)
{
}
