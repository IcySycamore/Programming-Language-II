#pragma once
class IntegerSet
{
public:
	static constexpr int set_size = 101;//contains 0-set_size-1(set_size=101,0-100)
	IntegerSet();//default initializaton
	IntegerSet(const int(&)[set_size]);//initialization with arr;the size of the array must be set_Size 
	IntegerSet unionOfSets(IntegerSet a)const;
	IntegerSet intersectionOfSets(IntegerSet a)const;
	void insertElement(int i);
	void deleteElement(int i);
	void printSet() const;//with a \n at the end
	bool isEqualTo(IntegerSet a) const;
	bool isEmpty()const;
	bool validEntry(int i)const;
private:
	int set_exist_state[set_size];

};

