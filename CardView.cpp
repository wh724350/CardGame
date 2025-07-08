#include "CardView.h"

bool CardView::init()
{
	if (!Node::init())
		return false;
	// ��ʼ�����Ʊ��������
	_cardBack = cocos2d::Sprite::create("card_back.png");
	_cardFront = cocos2d::Sprite::create("card_front.png");
	_cardFront->setVisible(false); // ��ʼ״̬�����治�ɼ�

	// ��ӵ��ڵ���
	this->addChild(_cardBack);
	this->addChild(_cardFront);

	return true;
}

void CardView::setCard(const CardModel& card)
{
	_model = card; // ���ÿ���ģ��
	// ���¿����������ʾ
	/*_cardFront->setTexture(card.getFrontTexture());
	_cardBack->setTexture(card.getBackTexture());*/
}

void CardView::flipCard(bool isFaceUp)
{
	_isFaceUp = isFaceUp; // ����״̬
	_cardFront->setVisible(isFaceUp); // ��������ɼ���
	_cardBack->setVisible(!isFaceUp); // ���ñ���ɼ���
}

void CardView::moveTo(const cocos2d::Vec2& position, float duration)
{
	// �����ƶ�����
	auto moveAction = cocos2d::MoveTo::create(duration, position);
	// ִ�ж���
	this->runAction(moveAction);
}