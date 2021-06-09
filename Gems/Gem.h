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

	bool isGemNextTo(SimpleGem*) const; //ћетод, определ€ющий находитс€ ли гем р€дос с данным
	void gemSwapWith(SimpleGem*); //ћетод, мен€ющий параметры гема с данным (координаты, цвет, но не позицию в массиве)

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

//Ѕонусный гем имеет специфический деструктор
class BonusGem : public SimpleGem {
	Q_OBJECT
public:
	BonusGem(QWidget *parent) : SimpleGem(parent) {}
	virtual ~BonusGem();
signals:
	void gemDestr(SimpleGem*);
};