#include "CardView.h"

bool CardView::init()
{
	if (!Node::init())
		return false;
	// 初始化卡牌背面和正面
	_cardBack = cocos2d::Sprite::create("card_back.png");
	_cardFront = cocos2d::Sprite::create("card_front.png");
	_cardFront->setVisible(false); // 初始状态下正面不可见

	// 添加到节点中
	this->addChild(_cardBack);
	this->addChild(_cardFront);

	return true;
}

void CardView::setCard(const CardModel& card)
{
	_model = card; // 设置卡牌模型
	// 更新卡牌正面的显示
	/*_cardFront->setTexture(card.getFrontTexture());
	_cardBack->setTexture(card.getBackTexture());*/
}

void CardView::flipCard(bool isFaceUp)
{
	_isFaceUp = isFaceUp; // 更新状态
	_cardFront->setVisible(isFaceUp); // 设置正面可见性
	_cardBack->setVisible(!isFaceUp); // 设置背面可见性
}

void CardView::moveTo(const cocos2d::Vec2& position, float duration)
{
	// 创建移动动作
	auto moveAction = cocos2d::MoveTo::create(duration, position);
	// 执行动作
	this->runAction(moveAction);
}