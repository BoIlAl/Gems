#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Gems.h"
#include "GemBonus.h"
#include "Score.h"

class Gems : public QMainWindow
{
    Q_OBJECT

public:
    Gems(QWidget *parent = Q_NULLPTR); //В контрукторе создаются объекты всех используемых классов (строки 37 - 41). Игровое поле приводится в состоянии отсутсвия комбинаций

private:
    Ui::GemsClass ui;

		const int c_numOfGemInLine = 7; //Количество гемов в строке/столбце
		const int c_fieldsize = 700; //Размер игрового поля
		const int c_combinationSize = 3; //Размер минимальной комбинации
		const int c_scoreSize = 100; //Размер кнопки-счетчика очков

		const int c_chanceOfBonusBombGem = 3; //Шанс появления бонуса-бомбы в %
		const int c_dropRadiusBonusBomb = 3; //Радиус выпадения бонуса-бомбы
		const int c_numOfBonusBombAffectedElem = 5; //Кол-во гемов, на которое действует бонус-бомба (>= 1)
		int c_actionRadiusBonusBomb = c_numOfGemInLine; //Радиус, в котором действует бонус-бомба после попадания

		const int c_chanceOfBonusRepaintGem = 3; //Шанс появления бонуса-перекраски в %
		const int c_dropRadiusRepaintBonus = 3; //Радиус выпадения бонуса-перекраски
		const int c_numOfBonusRepaintAffectedElem = 3; //Кол-во гемов, на которое действует бонус-перекраска ( (>= 1)
		const int c_actionRadiusRepaintBonus = 2; //Радиус, в котором действует бонус-перекраска после попадания

		const int c_scoreToWin = 100; //Количество очков для победы (один разрушенный гем == 1)
		
		const std::vector<QString> c_colours = { "green","blue", "red", "magenta", "yellow", "white", "black", "grey", "cyan" }; //Использующиеся для гемов цвета

		Score* score_;
		GemsPhysics* gemsPhysics_;
		GemBonusBomb* gemBonusBomb_;
		GemBonusRepaint* gemBonusRepaint_;
		GemsVector* gemsVect_;

private slots:
	void updateField(SimpleGem*); //Метод реакции на нажатие
	void gameOver(); //Метод закрытия приложения 
};
