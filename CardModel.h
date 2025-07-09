#pragma once
#include "cocos2d.h"

//���ƻ�ɫ
enum class CardSuitType
{
	CST_NONE = -1, // ��Ч��ɫ
	CST_SPADES,      // ����
	CST_HEARTS,      // ����
	CST_DIAMONDS,    // ����
	CST_CLUBS,        // ÷��
	CST_NUM_CARD_SUIT_TYPES		// ��ɫ����
};

//���Ƶ���(1-13)
enum class CardFaceType
{
	CFT_NONE = -1, // ��Ч����
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
	CFT_NUM_CARD_FACE_TYPES // ��������
};

class CardModel
{
public:
	CardModel(CardSuitType suit, CardFaceType face) : _suit(suit), _face(face) {}	// ���캯��

	CardFaceType getFace() const { return _face; }  // ��ȡ���Ƶ���
	CardSuitType getSuit() const { return _suit; }  // ��ȡ���ƻ�ɫ

	//�ж��Ƿ����ƥ��(���ֲ�1)
	bool canMatch(const CardModel& other)const
	{
		int diff = abs(static_cast<int>(_face) - static_cast<int>(other._face));
		return diff == 1;
	}

private:
	CardSuitType _suit;  // ���ƻ�ɫ
	CardFaceType _face;  // ���Ƶ���
};