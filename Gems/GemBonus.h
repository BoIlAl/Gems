#pragma once
#include "GemsPhysics.h"

//������ ������ ������������ ���������� �������������� ���������� GemsPhysics �� ���� ���� ��� �������� ����� ���������� ��������� ���� �� ������� �������� ����� ����� ����.

class AbstractGemBonus : public QObject {
	Q_OBJECT
public:
	AbstractGemBonus(GemsPhysics*, int, int, int); //����������� ��������� ������ ����������� ��� ������������� ���������� ������ (������ 13-16)
protected:
	GemsPhysics* gemsPhysics_; 
	int dropRadius_; 
	int actionRadius_;
	int numberOfAffectedElem_;

	std::vector<int> BonusRadius(int, int) const; //��������������� �����, ������������ ��������� ����� � ������ ������� �� ���� �� ������� �������
	int detPlaceOfHit(int) const; //��������������� �����, ����������� ���� ����� ����� �� ������� ��������� ����. 
																//���������� ������ ��� ������������� �����, ���� ��������� ��������� ���� ��������� �����
public slots:
	virtual void activate(SimpleGem*) const = 0; //�������� ����� ������ ������������� ��� ������� ����������
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