#pragma once
#include "Gem.h"
#include <ctime>

class GemBonusRepaint;
class GemBonusBomb;

//����� ���������� ��� �������� ����� 
class GemsVector {
private:
	std::vector<SimpleGem*> gemsVect_;
	QWidget* parentForGems_ = nullptr;
	int numOfGemInLine_;
	int fieldSize_;

	void drawGem(SimpleGem* gem); //��������������� ����� ����������� ������ ����
public:
	GemsVector(QWidget*, int, int); //����������� ��������� ������ ��� ������������� ���������� (11-13). ������� � ��������� ������ ������ �����.
	void vectFill(GemBonusBomb*, GemBonusRepaint*, int, int, const std::vector<QString>&); //�����, ����������� ������� ���� ������� ����� ���������� ������ � ������ ��������������
	void drawField(); //����� ����������� ���� ����� �������� ����

	int getGemIndex(int, int) const; //�����, ������������ ����� ���� � ������� �� ��� �����������
	int getGemInLine() const; 
	int getFieldsize() const;
	int size() const;

	SimpleGem*& GemsVector::operator[] (const int index) { return gemsVect_[index]; }
};