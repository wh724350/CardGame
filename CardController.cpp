#include "CardController.h"

void CardController::handleCardClick(CardView* cardView)
{
	// ��������ѱ���ת��ƥ�䣬ֱ�ӷ���
	if (cardView->getCard().getFace() == CardFaceType::CFT_NONE || cardView->getCard().getSuit() == CardSuitType::CST_NONE)
		return;
	// ��ת����
	cardView->flipCard(true);
	// ����Ƿ�����һ�ſ����ѱ���ת
	if (_actionHistory.size() < 2)
	{
		_actionHistory.push_back({ cardView, nullptr });
	}
	else
	{
		// ����������ſ��Ʊ���ת������ƥ����
		auto& firstCard = _actionHistory[0].first;
		auto& secondCard = _actionHistory[1].first;
		if (firstCard->getCard().canMatch(cardView->getCard()))
		{
			matchCards(firstCard, cardView);
			_actionHistory.clear(); // �����ʷ��¼
		}
		else
		{
			// ��ת��ȥ
			firstCard->flipCard(false);
			cardView->flipCard(false);
			_actionHistory.clear();
			_actionHistory.push_back({ cardView, nullptr });
		}
	}
}

void CardController::matchCards(CardView* card1, CardView* card2)
{
	// ����ƥ���߼�
	if (card1->getCard().canMatch(card2->getCard()))
	{
		// ƥ��ɹ���ִ����ز���
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
	// ��ȡ���һ�Կ���
	auto lastAction = _actionHistory.back();
	_actionHistory.pop_back();
	// ��ת��ȥ
	if (lastAction.first)
		lastAction.first->flipCard(false);
	if (lastAction.second)
		lastAction.second->flipCard(false);
}