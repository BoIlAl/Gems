#pragma once
#include <QtWidgets>

//�����-������-�������, ������������ ������� �������� �� ����. ����� ���������� �������� ���-�� �����, ���������� �������� ������� ��� �������� ����������.
class Score : public QPushButton {
	Q_OBJECT
public:
	Score(QWidget*, int);
	void increaseScore(int); //�����, ������������� ������� ���-�� �����. �������� ���� �������.
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