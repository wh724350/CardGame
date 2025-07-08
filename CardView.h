#pragma once
#include "cocos2d.h"
#include "../proj.win32/CardModel.h"

// ������ͼ��
class CardView : public cocos2d::Node
{
	public:
		CREATE_FUNC(CardView);		// ����ʵ��

		bool init() override;		// ��ʼ������
		void setCard(const CardModel& card);	// ���ÿ���ģ��
		CardModel getCard() const { return _model; }	// ��ȡ��ǰ����ģ��
		void flipCard(bool isFaceUp);	// ��ת����
		void moveTo(const cocos2d::Vec2& position, float duration = 0.3f);	// �ƶ����Ƶ�ָ��λ��

	private:
		CardModel _model;				// ��ǰ����ģ��
		cocos2d::Sprite* _cardBack;		// ���Ʊ���
		cocos2d::Sprite* _cardFront;	// ��������
		bool _isFaceUp;				// �Ƿ����泯��
};