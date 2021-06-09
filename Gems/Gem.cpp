#include "Gem.h"

int SimpleGem::gemSize_ = 0;

int SimpleGem::getGemX() const {
	return gemX_;
}

int SimpleGem::getGemY() const {
	return gemY_;
}

int SimpleGem::getGemSize() const {
	return gemSize_;
}

QString SimpleGem::getGemColour() const {
	return gemColour_;
}


void SimpleGem::setGemColour(QString newColour) {
	gemColour_ = newColour;
}

void SimpleGem::setGemSize(int size){
	gemSize_ = size;
}

void SimpleGem::setGemCoordinates(int x, int y) {
	gemX_ = x;
	gemY_ = y;
}

bool SimpleGem::isGemNextTo(SimpleGem *gem) const {
	if ((gemX_ + gemSize_ == gem->getGemX() && gemY_ == gem->getGemY()) || (gemX_ - gemSize_ == gem->getGemX() && gemY_ == gem->getGemY())
		|| (gemY_ + gemSize_ == gem->getGemY() && gemX_ == gem->getGemX()) || (gemY_ - gemSize_ == gem->getGemY() && gemX_ == gem->getGemX())) {
		return true;
	}
	return false;
}

void SimpleGem::gemSwapWith(SimpleGem* gem){
	int tempX = gem->getGemX();
	int tempY = gem->getGemY();
	gem->setGemCoordinates(gemX_, gemY_);
	gemX_ = tempX;
	gemY_ = tempY;
}


void SimpleGem::mousePressEvent(QMouseEvent * event) {
	if (event->button() == Qt::LeftButton) {
		gemClicked(this);
	}
}

BonusGem::~BonusGem(){
	gemDestr(this);
}
