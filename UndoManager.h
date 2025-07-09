#pragma once
#include "CardView.h"
#include <vector>
#include <string>

class UndoManager
{
	public:
		void recordAction(const CardView* card1, const CardView* card2 = nullptr, const std::string& actionType);	// 记录操作
		void undoLastAction();	// 撤销上一步操作

	private:
		struct ActionRecord
		{
			CardView* card1;			// 第一张卡牌
			CardView* card2;			// 可选的第二张卡牌
			std::string actionType;		// 操作类型，例如 "flip" 或 "match"
		};
		std::vector<ActionRecord> _actionHistory;	// 存储操作历史记录
};