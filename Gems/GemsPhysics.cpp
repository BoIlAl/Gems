#include "GemsPhysics.h"

bool GemsPhysics::isElemInArr(std::vector<int> vector, int value) const {
	for (int i = 0; i < vector.size(); ++i) {
		if (vector[i] == value) {
			return true;
		}
	}
	return false;
}

std::vector<int> GemsPhysics::CombinationColl(int indexToStart) const {
	std::vector<int> confirmed;
	std::vector<int> notConfirmed;

	notConfirmed.push_back(indexToStart);

	while (!notConfirmed.empty()) {
		int temp = notConfirmed.back();
		notConfirmed.pop_back();
		if (((*gemsVect_)[temp]->getGemX() != 0) && ((*gemsVect_)[temp]->getGemColour() == (*gemsVect_)[temp - 1]->getGemColour())) {
			if (isElemInArr(confirmed, temp - 1) == false && isElemInArr(notConfirmed, temp - 1) == false) {
				notConfirmed.push_back(temp - 1);
			}
		}
		if (((*gemsVect_)[temp]->getGemY() != 0) && ((*gemsVect_)[temp]->getGemColour() == (*gemsVect_)[temp - gemsVect_->getGemInLine()]->getGemColour())) {
			if (isElemInArr(confirmed, temp - gemsVect_->getGemInLine()) == false && isElemInArr(notConfirmed, temp - gemsVect_->getGemInLine()) == false) {
				notConfirmed.push_back(temp - gemsVect_->getGemInLine());
			}
		}
		if (((*gemsVect_)[temp]->getGemX() != (gemsVect_->getGemInLine() - 1) * (*gemsVect_)[temp]->getGemSize()) 
			&& ((*gemsVect_)[temp]->getGemColour() == (*gemsVect_)[temp + 1]->getGemColour())) {
			if (isElemInArr(confirmed, temp + 1) == false && isElemInArr(notConfirmed, temp + 1) == false) {
				notConfirmed.push_back(temp + 1);
			}
		}
		if (((*gemsVect_)[temp]->getGemY() != (gemsVect_->getGemInLine() - 1) * (*gemsVect_)[temp]->getGemSize()) 
			&& ((*gemsVect_)[temp]->getGemColour() == (*gemsVect_)[temp + gemsVect_->getGemInLine()]->getGemColour())) {
			if (isElemInArr(confirmed, temp + gemsVect_->getGemInLine()) == false && isElemInArr(notConfirmed, temp + gemsVect_->getGemInLine()) == false) {
				notConfirmed.push_back(temp + gemsVect_->getGemInLine());
			}
		}
		confirmed.push_back(temp);
	}
	return confirmed;
}

GemsPhysics::GemsPhysics(GemsVector *vect){
	gemsVect_ = vect;
}

bool GemsPhysics::processingÑlicks(SimpleGem* gem){
	if (clickedGem_ == nullptr) {
		clickedGem_ = gem;
		return false;
	}
	if (clickedGem_->isGemNextTo(gem)) {

		int indOfFirstGem = gemsVect_->getGemIndex(clickedGem_->getGemX(), clickedGem_->getGemY());
		int	indOfSecondGem = gemsVect_->getGemIndex(gem->getGemX(), gem->getGemY());

		clickedGem_->gemSwapWith(gem);

		(*gemsVect_)[indOfFirstGem] = gem;
		(*gemsVect_)[indOfSecondGem] = clickedGem_;

	}
	clickedGem_ = nullptr;
	return true;
}

std::vector<int> GemsPhysics::checkComb(int combSize) const {
	std::vector<int> allComb;
	std::vector<int> oneCombination;

	for (int i = gemsVect_->size() - 1; i >= 0; --i) {

		oneCombination = CombinationColl(i);
		if (oneCombination.size() < combSize) {
			continue;
		}

		if (oneCombination.size() != 0 && isElemInArr(allComb, oneCombination[0]) == false) {
			allComb.insert(allComb.end(), oneCombination.begin(), oneCombination.end());
		}
	}
	return allComb;
}

void GemsPhysics::gemsDelete(std::vector<int> arrOfInd) {
	if (gemsToDelete_.size() == 0) {
		gemsToDelete_ = arrOfInd;
	}
	else {
		gemsToDelete_.insert(gemsToDelete_.end(), arrOfInd.begin(), arrOfInd.end());
	}

	for (int i = 0; i < arrOfInd.size(); ++i) {
		delete (*gemsVect_)[arrOfInd[i]];
		(*gemsVect_)[arrOfInd[i]] = nullptr;
	}
}

void GemsPhysics::fallOfGems() {
	for (int i = (*gemsVect_).size() - 1; i >= 0; --i) {
		if ((*gemsVect_)[i] == nullptr) {
			continue;
		}
		if (i / gemsVect_->getGemInLine() != gemsVect_->getGemInLine() - 1 && (*gemsVect_)[i + gemsVect_->getGemInLine()] == nullptr) {
			int j = i;
			do {
				(*gemsVect_)[j]->setGemCoordinates((*gemsVect_)[j]->getGemX(), (*gemsVect_)[j]->getGemY() + (*gemsVect_)[j]->getGemSize());
				(*gemsVect_)[j + gemsVect_->getGemInLine()] = (*gemsVect_)[j];
				(*gemsVect_)[j] = nullptr;
				j += gemsVect_->getGemInLine();
			} while (j / gemsVect_->getGemInLine() != gemsVect_->getGemInLine() - 1 && (*gemsVect_)[j + gemsVect_->getGemInLine()] == nullptr);
		}
	}
}

void GemsPhysics::gemsRepaint(std::vector<int> arrOfInd, QString newColour) {
	for (int i = 0; i < arrOfInd.size(); ++i) {
		(*gemsVect_)[arrOfInd[i]]->setGemColour(newColour);
	}
}

bool GemsPhysics::isGemDestroyed(int index) const {
	if (isElemInArr(gemsToDelete_, index)) {
		return true;
	}
	return false;
}

GemsVector* GemsPhysics::getGemsVector() const {
	return gemsVect_;
}

int GemsPhysics::clearDelete() {
	int temp = gemsToDelete_.size();
	gemsToDelete_.clear();
	return temp;
}
