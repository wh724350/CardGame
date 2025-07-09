#include "CardController.h"

void CardController::handleCardClick(CardView* cardView)
{
	// 如果卡牌已被翻转或匹配，直接返回
	if (cardView->getCard().getFace() == CardFaceType::CFT_NONE || cardView->getCard().getSuit() == CardSuitType::CST_NONE)
		return;
	// 翻转卡牌
	cardView->flipCard(true);
	// 检查是否有另一张卡牌已被翻转
	if (_actionHistory.size() < 2)
	{
		_actionHistory.push_back({ cardView, nullptr });
	}
	else
	{
		// 如果已有两张卡牌被翻转，进行匹配检查
		auto& firstCard = _actionHistory[0].first;
		auto& secondCard = _actionHistory[1].first;
		if (firstCard->getCard().canMatch(cardView->getCard()))
		{
			matchCards(firstCard, cardView);
			_actionHistory.clear(); // 清空历史记录
		}
		else
		{
			// 翻转回去
			firstCard->flipCard(false);
			cardView->flipCard(false);
			_actionHistory.clear();
			_actionHistory.push_back({ cardView, nullptr });
		}
	}
}

void CardController::matchCards(CardView* card1, CardView* card2)
{
	// 处理匹配逻辑
	if (card1->getCard().canMatch(card2->getCard()))
	{
		// 匹配成功，执行相关操作
		cocos2d::log("Matched cards: %d of %d and %d of %d",
			static_cast<int>(card1->getCard().getFace()), static_cast<int>(card1->getCard().getSuit()),
			static_cast<int>(card2->getCard().getFace()), static_cast<int>(card2->getCard().getSuit()));
	}
	else
	{
		cocos2d::log("Cards do not match.");
	}
}

void CardController::undoLastAction()
{
	if (_actionHistory.empty())
		return;
	// 获取最后一对卡牌
	auto lastAction = _actionHistory.back();
	_actionHistory.pop_back();
	// 翻转回去
	if (lastAction.first)
		lastAction.first->flipCard(false);
	if (lastAction.second)
		lastAction.second->flipCard(false);
}