#pragma once
#include "GemsPhysics.h"

//Классу бонуса делигируется управление использующимся экземляром GemsPhysics за счет чего его действие после разрушения бонусного гема не требует контроля через класс игры.

class AbstractGemBonus : public QObject {
	Q_OBJECT
public:
	AbstractGemBonus(GemsPhysics*, int, int, int); //Конструктор принимает данные необходимые для инициализации переменных класса (строки 13-16)
protected:
	GemsPhysics* gemsPhysics_; 
	int dropRadius_; 
	int actionRadius_;
	int numberOfAffectedElem_;

	std::vector<int> BonusRadius(int, int) const; //Вспомогательный метод, определяющий множество гемов в данном радиусе от гема по данному индексу
	int detPlaceOfHit(int) const; //Вспомогательный метод, вычисляющий куда попал бонус по индексу побусного гема. 
																//Возвращает индекс или отрицательное число, если множество возможных мест попадания пусто
public slots:
	virtual void activate(SimpleGem*) const = 0; //Основной метод класса специфический для каждого наследника
};


class GemBonusRepaint : public AbstractGemBonus {
	Q_OBJECT
public:
	GemBonusRepaint(GemsPhysics* overseer, int dropRadius, int actionRadius, int numberOfAffectedElem) : AbstractGemBonus(overseer, dropRadius, actionRadius, numberOfAffectedElem) {}
public slots:
	virtual void activate(SimpleGem*) const;
};

class GemBonusBomb : public AbstractGemBonus {
	Q_OBJECT
public:
	GemBonusBomb(GemsPhysics* overseer, int dropRadius, int actionRadius, int numberOfAffectedElem) : AbstractGemBonus(overseer, dropRadius, actionRadius, numberOfAffectedElem) {}
public slots:
	virtual void activate(SimpleGem*) const;
};