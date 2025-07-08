#include "UndoManager.h"

void UndoManager::recordAction(const CardView* card1, const CardView* card2, const std::string& actionType)
{
	_actionHistory.push_back({ const_cast<CardView*>(card1), const_cast<CardView*>(card2), actionType });	// ��¼����
}

void UndoManager::undoLastAction()
{
	if (_actionHistory.empty())
		return;	// ���û�в�����¼��ֱ�ӷ���
	// ��ȡ���һ��������¼
	ActionRecord lastAction = _actionHistory.back();
	_actionHistory.pop_back();	// �Ƴ����һ����¼
	// ���ݲ�������ִ�г����߼�
	if (lastAction.actionType == "flip")
	{
		lastAction.card1->flipCard(false);	// ��ת���ƻ�ȥ
	}
	else if (lastAction.actionType == "match")
	{
		if (lastAction.card2)
		{
			lastAction.card1->flipCard(false);	// ��ת��һ�ſ��ƻ�ȥ
			lastAction.card2->flipCard(false);	// ��ת�ڶ��ſ��ƻ�ȥ
		}
	}
}