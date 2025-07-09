#pragma once
#include "cocos2d.h"

//卡牌花色
enum class CardSuitType
{
	CST_NONE = -1, // 无效花色
	CST_SPADES,      // 黑桃
	CST_HEARTS,      // 红桃
	CST_DIAMONDS,    // 方块
	CST_CLUBS,        // 梅花
	CST_NUM_CARD_SUIT_TYPES		// 花色数量
};

//卡牌点数(1-13)
enum class CardFaceType
{
	CFT_NONE = -1, // 无效点数
	CFT_ACE,   // A
	CFT_TWO,   // 2
	CFT_THREE, // 3
	CFT_FOUR,  // 4
	CFT_FIVE,  // 5
	CFT_SIX,   // 6
	CFT_SEVEN, // 7
	CFT_EIGHT, // 8
	CFT_NINE,  // 9
	CFT_TEN,   // 10
	CFT_JACK,  // J
	CFT_QUEEN, // Q
	CFT_KING,  // K
	CFT_NUM_CARD_FACE_TYPES // 点数数量
};

class CardModel
{
public:
	CardModel(CardSuitType suit, CardFaceType face) : _suit(suit), _face(face) {}	// 构造函数

	CardFaceType getFace() const { return _face; }  // 获取卡牌点数
	CardSuitType getSuit() const { return _suit; }  // 获取卡牌花色

	//判断是否可以匹配(数字差1)
	bool canMatch(const CardModel& other)const
	{
		int diff = abs(static_cast<int>(_face) - static_cast<int>(other._face));
		return diff == 1;
	}

private:
	CardSuitType _suit;  // 卡牌花色
	CardFaceType _face;  // 卡牌点数
};