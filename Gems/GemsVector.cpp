#include "GemsVector.h"
#include "GemBonus.h"

void GemsVector::drawGem(SimpleGem * gem) {
	gem->setGeometry(gem->getGemX(), gem->getGemY(), gem->getGemSize(), gem->getGemSize());
	gem->setStyleSheet("background-color: " + gem->getGemColour());
	gem->setVisible(true);
}

GemsVector::GemsVector(QWidget* parentForGems, int fieldSize, int numOfGemInLine) {
	parentForGems_ = parentForGems;
	numOfGemInLine_ = numOfGemInLine;
	fieldSize_ = fieldSize;

	SimpleGem* newGem = new SimpleGem(parentForGems_);
	newGem->setGemSize(fieldSize_ / numOfGemInLine_);
	delete newGem;
	newGem = nullptr;

	for (int i = 0; i < numOfGemInLine_ * numOfGemInLine_; ++i) {
		gemsVect_.push_back(newGem);
	}
}

void GemsVector::vectFill(GemBonusBomb* gemBonusBomb, GemBonusRepaint* gemBonusRepaint, int chanceOfBombGem, int chanceOfRepGem, const std::vector<QString>& colours) {
	std::srand(unsigned(std::time(0)));
	int counter1 = 0;
	int counter2 = 0;


	for (int i = 0; i < numOfGemInLine_ * numOfGemInLine_; ++i) {

		if (gemsVect_[i] != nullptr) {
			++counter1;
			if (counter1 == numOfGemInLine_) {
				counter1 = 0;
				++counter2;
			}
			continue;
		}

		int random = round(static_cast<double>(std::rand()) * (colours.size() - 1) / RAND_MAX);
		SimpleGem* newGem;
		if ((round(static_cast<double>(std::rand()) * 99) / RAND_MAX) <= chanceOfBombGem) {
			newGem = new BonusGem(parentForGems_);
			QObject::connect(newGem, SIGNAL(gemDestr(SimpleGem*)), gemBonusBomb, SLOT(activate(SimpleGem*)));
		}
		else if (round(static_cast<double>(std::rand()) * 99) / RAND_MAX <= numOfGemInLine_) {
			newGem = new BonusGem(parentForGems_);
			QObject::connect(newGem, SIGNAL(gemDestr(SimpleGem*)), gemBonusRepaint, SLOT(activate(SimpleGem*)));
		}
		else {
			newGem = new SimpleGem(parentForGems_);
		}
		gemsVect_[i] = newGem;
		QObject::connect(newGem, SIGNAL(gemClicked(SimpleGem*)), parentForGems_, SLOT(updateField(SimpleGem*)));


		newGem->setGemColour(colours[random]);
		newGem->setGemCoordinates(counter1 * newGem->getGemSize(), counter2 * newGem->getGemSize());
		++counter1;
		if (counter1 == numOfGemInLine_) {
			counter1 = 0;
			++counter2;
		}
	}
}

void GemsVector::drawField() {
	for (int i = 0; i < gemsVect_.size(); ++i) {
		drawGem(gemsVect_[i]);
	}
}


int GemsVector::getGemIndex(int x, int y) const {
	return (x * numOfGemInLine_ / fieldSize_ + y * numOfGemInLine_ * numOfGemInLine_ / fieldSize_);
}

int GemsVector::getGemInLine() const {
	return numOfGemInLine_;
}

int GemsVector::getFieldsize() const {
	return fieldSize_;
}

int GemsVector::size() const {
	return gemsVect_.size();
}
