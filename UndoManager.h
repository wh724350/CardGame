#pragma once
#include "CardView.h"
#include <vector>
#include <string>

class UndoManager
{
	public:
		void recordAction(const CardView* card1, const CardView* card2 = nullptr, const std::string& actionType);	// ��¼����
		void undoLastAction();	// ������һ������

	private:
		struct ActionRecord
		{
			CardView* card1;			// ��һ�ſ���
			CardView* card2;			// ��ѡ�ĵڶ��ſ���
			std::string actionType;		// �������ͣ����� "flip" �� "match"
		};
		std::vector<ActionRecord> _actionHistory;	// �洢������ʷ��¼
};