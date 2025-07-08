#pragma once
#include "../proj.win32/CardModel.h"
#include "../proj.win32/CardView.h"

class CardController		// ���ƿ�������
{
public:
	void handleCardClick(CardView* cardView);	// �����Ƶ���¼�
	void matchCards(CardView* card1, CardView* card2);	// ƥ�����ſ���
	void undoLastAction();		// ������һ������

private:
	//��¼������ʷ
	std::vector<std::pair<CardView*, CardView*>> _actionHistory;	// �洢��ƥ��Ŀ��ƶ�
};