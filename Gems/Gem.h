#pragma once
#include <QtWidgets>
#include <QMouseEvent>


class SimpleGem : public QPushButton {
	Q_OBJECT
public:
	SimpleGem(QWidget *parent) : QPushButton(parent) {}
	int getGemX() const;
	int getGemY() const;
	int getGemSize() const;
	QString getGemColour() const;
	
	void setGemColour(QString);
	void setGemSize(int);
	void setGemCoordinates(int, int);

	bool isGemNextTo(SimpleGem*) const; //�����, ������������ ��������� �� ��� ����� � ������
	void gemSwapWith(SimpleGem*); //�����, �������� ��������� ���� � ������ (����������, ����, �� �� ������� � �������)

	virtual ~SimpleGem() {};

protected:
	virtual void mousePressEvent(QMouseEvent *event);
private:
	static int gemSize_;
	QString gemColour_ = "grey";
	int gemX_ = 0;
	int gemY_ = 0;
signals:
	void gemClicked(SimpleGem*);
};

//�������� ��� ����� ������������� ����������
class BonusGem : public SimpleGem {
	Q_OBJECT
public:
	BonusGem(QWidget *parent) : SimpleGem(parent) {}
	virtual ~BonusGem();
signals:
	void gemDestr(SimpleGem*);
};