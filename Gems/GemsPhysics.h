#pragma once
#include "GemsVector.h"

//����� ����������� �������� �������� ��� �������
class GemsPhysics {
private:
	GemsVector *gemsVect_;
	std::vector<int> gemsToDelete_; //������ �������� �����, ������� �����/��� �������. ������������� � ������ ������� ��������� ��-�� �������� ����������� ��������
	SimpleGem* clickedGem_ = nullptr; 


	bool isElemInArr(std::vector<int> vector, int value) const; //��������������� �����
	std::vector<int> CombinationColl(int) const; //��������������� �����, ���������� ���������� �� ���� �� �������� �������

public:
	GemsPhysics(GemsVector*);

	bool processing�licks(SimpleGem*); //����� �������������� ������� �� ���. ��������, ������� �� �������� ������

	std::vector<int> checkComb(int) const; //�����, ��������� ��� ���������� �� ���� � ������������ ������ �������� ���� ���������, ������� ������� �������. 
																				 //��������� ����������� ������ ����������.

	void gemsDelete(std::vector<int>); //�����, ��������� ��� �������� �� ������ ��������
	void gemsRepaint(std::vector<int>, QString); //�����, ��������������� � ������ ���� ��� �������� �� ������ ��������

	void fallOfGems(); //�����, ������������ ����

	bool isGemDestroyed(int) const; //�����, ���������� ������� ��������� ���� �� ������� � �������. ����� �� �� ������.
	GemsVector* getGemsVector() const;

	int clearDelete(); //����� ��������� ������ �������� �����, ������� �����/��� �������.
};