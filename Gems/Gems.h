#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Gems.h"
#include "GemBonus.h"
#include "Score.h"

class Gems : public QMainWindow
{
    Q_OBJECT

public:
    Gems(QWidget *parent = Q_NULLPTR); //� ����������� ��������� ������� ���� ������������ ������� (������ 37 - 41). ������� ���� ���������� � ��������� ��������� ����������

private:
    Ui::GemsClass ui;

		const int c_numOfGemInLine = 7; //���������� ����� � ������/�������
		const int c_fieldsize = 700; //������ �������� ����
		const int c_combinationSize = 3; //������ ����������� ����������
		const int c_scoreSize = 100; //������ ������-�������� �����

		const int c_chanceOfBonusBombGem = 3; //���� ��������� ������-����� � %
		const int c_dropRadiusBonusBomb = 3; //������ ��������� ������-�����
		const int c_numOfBonusBombAffectedElem = 5; //���-�� �����, �� ������� ��������� �����-����� (>= 1)
		int c_actionRadiusBonusBomb = c_numOfGemInLine; //������, � ������� ��������� �����-����� ����� ���������

		const int c_chanceOfBonusRepaintGem = 3; //���� ��������� ������-���������� � %
		const int c_dropRadiusRepaintBonus = 3; //������ ��������� ������-����������
		const int c_numOfBonusRepaintAffectedElem = 3; //���-�� �����, �� ������� ��������� �����-���������� ( (>= 1)
		const int c_actionRadiusRepaintBonus = 2; //������, � ������� ��������� �����-���������� ����� ���������

		const int c_scoreToWin = 100; //���������� ����� ��� ������ (���� ����������� ��� == 1)
		
		const std::vector<QString> c_colours = { "green","blue", "red", "magenta", "yellow", "white", "black", "grey", "cyan" }; //�������������� ��� ����� �����

		Score* score_;
		GemsPhysics* gemsPhysics_;
		GemBonusBomb* gemBonusBomb_;
		GemBonusRepaint* gemBonusRepaint_;
		GemsVector* gemsVect_;

private slots:
	void updateField(SimpleGem*); //����� ������� �� �������
	void gameOver(); //����� �������� ���������� 
};
