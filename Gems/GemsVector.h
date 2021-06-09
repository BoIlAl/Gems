#pragma once
#include "Gem.h"
#include <ctime>

class GemBonusRepaint;
class GemBonusBomb;

// ласс абстракции над вектором гемов 
class GemsVector {
private:
	std::vector<SimpleGem*> gemsVect_;
	QWidget* parentForGems_ = nullptr;
	int numOfGemInLine_;
	int fieldSize_;

	void drawGem(SimpleGem* gem); //¬спомогательный метод отображени€ одного гема
public:
	GemsVector(QWidget*, int, int); // онструктор принимает данные дл€ инициализации переменных (11-13). —оздает и заполн€ет нул€ми вектор гемов.
	void vectFill(GemBonusBomb*, GemBonusRepaint*, int, int, const std::vector<QString>&); //ћетод, заполн€ющий нулевые пол€ вектора гемов случайными гемами с учетов параметризации
	void drawField(); //ћетод отображени€ всех гемов игрового пол€

	int getGemIndex(int, int) const; //ћетод, возвращающий номер гема в векторе по его координатам
	int getGemInLine() const; 
	int getFieldsize() const;
	int size() const;

	SimpleGem*& GemsVector::operator[] (const int index) { return gemsVect_[index]; }
};