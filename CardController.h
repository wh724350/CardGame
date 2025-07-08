#pragma once
#include "../proj.win32/CardModel.h"
#include "../proj.win32/CardView.h"

class CardController		// 卡牌控制器类
{
public:
	void handleCardClick(CardView* cardView);	// 处理卡牌点击事件
	void matchCards(CardView* card1, CardView* card2);	// 匹配两张卡牌
	void undoLastAction();		// 撤销上一步操作

private:
	//记录操作历史
	std::vector<std::pair<CardView*, CardView*>> _actionHistory;	// 存储已匹配的卡牌对
};