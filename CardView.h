#pragma once
#include "cocos2d.h"
#include "../proj.win32/CardModel.h"

// 卡牌视图类
class CardView : public cocos2d::Node
{
	public:
		CREATE_FUNC(CardView);		// 创建实例

		bool init() override;		// 初始化函数
		void setCard(const CardModel& card);	// 设置卡牌模型
		CardModel getCard() const { return _model; }	// 获取当前卡牌模型
		void flipCard(bool isFaceUp);	// 翻转卡牌
		void moveTo(const cocos2d::Vec2& position, float duration = 0.3f);	// 移动卡牌到指定位置

	private:
		CardModel _model;				// 当前卡牌模型
		cocos2d::Sprite* _cardBack;		// 卡牌背面
		cocos2d::Sprite* _cardFront;	// 卡牌正面
		bool _isFaceUp;				// 是否正面朝上
};