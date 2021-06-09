#pragma once
#include <QtWidgets>

//Класс-кнопка-счетчик, отображающий текущий прогресс на себе. После достижения целевого кол-ва очков, становится активной кнопкой для закрытия приложения.
class Score : public QPushButton {
	Q_OBJECT
public:
	Score(QWidget*, int);
	void increaseScore(int); //Метод, увеличивающий текущее кол-во очков. Изменяет свою надпись.
	bool isScoreAchieved();
protected:
	virtual void mousePressEvent(QMouseEvent *event);
private:
	int score_ = 0;
	int endScore_;
	QLabel* label_;
	bool endFlag_ = false; 
signals:
	void scoreClicked();
};