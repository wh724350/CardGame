#include "UndoManager.h"

void UndoManager::recordAction(const CardView* card1, const CardView* card2, const std::string& actionType)
{
	_actionHistory.push_back({ const_cast<CardView*>(card1), const_cast<CardView*>(card2), actionType });	// 记录操作
}

void UndoManager::undoLastAction()
{
	if (_actionHistory.empty())
		return;	// 如果没有操作记录，直接返回
	// 获取最后一条操作记录
	ActionRecord lastAction = _actionHistory.back();
	_actionHistory.pop_back();	// 移除最后一条记录
	// 根据操作类型执行撤销逻辑
	if (lastAction.actionType == "flip")
	{
		lastAction.card1->flipCard(false);	// 翻转卡牌回去
	}
	else if (lastAction.actionType == "match")
	{
		if (lastAction.card2)
		{
			lastAction.card1->flipCard(false);	// 翻转第一张卡牌回去
			lastAction.card2->flipCard(false);	// 翻转第二张卡牌回去
		}
	}
}