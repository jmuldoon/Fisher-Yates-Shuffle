#ifndef CARD_HPP
#define CARD_HPP

enum suite_t {CLUBS,DIAMONDS,HEARTS,SPADES};
enum value_t {ACE=1,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,TEN,JACK,QUEEN,KING};

class Card{
public:
	Card(suite_t, value_t);
	suite_t getSuite();
	value_t getValue();

private:
	suite_t suite;
	value_t value;
};

Card::Card(suite_t s, value_t v){
	value = v;
	suite = s;
}

value_t Card::getValue(){
	return value;
}
suite_t Card::getSuite(){
	return suite;
}

#endif //CARD_HPP