#pragma once
#include "GemsVector.h"

//Класс выполняющий основные действия над гемсами
class GemsPhysics {
private:
	GemsVector *gemsVect_;
	std::vector<int> gemsToDelete_; //Вектор индексов гемов, которые будут/уже удалены. Необходимость в данном векторе возникает из-за рекурсий пораждаемых бонусами
	SimpleGem* clickedGem_ = nullptr; 


	bool isElemInArr(std::vector<int> vector, int value) const; //Вспомогательный метод
	std::vector<int> CombinationColl(int) const; //Вспомогательный метод, собирающий комбинацию от гема по входному индексу

public:
	GemsPhysics(GemsVector*);

	bool processingСlicks(SimpleGem*); //Метод обрабатывающий нажатие на гем. Сообщает, следует ли провести замену

	std::vector<int> checkComb(int) const; //Метод, находящий все комбинации на поле и возвращающий вектор индексов всех элементов, которые следует удалить. 
																				 //Принимает минимальный размер комбинации.

	void gemsDelete(std::vector<int>); //Метод, удаляющий все элементы по данным индексам
	void gemsRepaint(std::vector<int>, QString); //Метод, перекрашивающий в данный цвет все элементы по данным индексам

	void fallOfGems(); //Метод, обваливающий гемы

	bool isGemDestroyed(int) const; //Метод, сообщающий текущее состоянии гема по индексу в векторе. Будет ли он удален.
	GemsVector* getGemsVector() const;

	int clearDelete(); //Метод очищающий вектор индексов гемов, которые будут/уже удалены.
};