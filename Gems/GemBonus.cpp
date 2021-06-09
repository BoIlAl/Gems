#include "GemBonus.h"

AbstractGemBonus::AbstractGemBonus(GemsPhysics* gemsPhysics, int dropRadius, int actionRadius, int numberOfAffectedElem) {
	gemsPhysics_ = gemsPhysics;
	dropRadius_ = dropRadius;
	actionRadius_ = actionRadius;
	numberOfAffectedElem_ = numberOfAffectedElem;
}

std::vector<int> AbstractGemBonus::BonusRadius(int indOfCentre, int radius) const {
	int gemInLine = gemsPhysics_->getGemsVector()->getGemInLine();

	int leftBorder = indOfCentre - radius;
	int rightBorder = indOfCentre + radius;
	int topBorder = indOfCentre - radius * gemInLine;
	int bottomBorder = indOfCentre + radius * gemInLine;
	while ((leftBorder / (gemInLine) != indOfCentre / (gemInLine)) || leftBorder < 0) {
		++leftBorder;
	}
	while (rightBorder / (gemInLine) != indOfCentre / (gemInLine)) {
		--rightBorder;
	}
	while (topBorder < 0) {
		topBorder += gemInLine;
	}
	while (bottomBorder > gemInLine * gemInLine - 1) {
		bottomBorder -= gemInLine;
	}

	std::vector<int> auxiliary;
	for (int k = (leftBorder % gemInLine) + (topBorder / gemInLine) * gemInLine; k <= (bottomBorder - indOfCentre) + rightBorder; ++k) {
		if ((rightBorder - k + 1) % (gemInLine) == 0) {
			k = k - rightBorder + leftBorder - 1 + gemInLine;
		}
		if (k == indOfCentre) {
			continue;
		}
		auxiliary.push_back(k);
	}
	return auxiliary;
}

int AbstractGemBonus::detPlaceOfHit(int indOfCentre) const {
	std::vector<int> possHitPoint = BonusRadius(indOfCentre, dropRadius_);

	while (!possHitPoint.empty()) {
		int temp = possHitPoint[round(static_cast<double>(std::rand()) * (possHitPoint.size() - 1) / RAND_MAX)];
		if (gemsPhysics_->isGemDestroyed(temp)) {
			possHitPoint.erase(std::remove(possHitPoint.begin(), possHitPoint.end(), temp), possHitPoint.end());
		}
		else {
			return temp;
		}
	}
	return -1;
}

void GemBonusRepaint::activate(SimpleGem* gem) const {
	int ind = gemsPhysics_->getGemsVector()->getGemIndex(gem->getGemX(), gem->getGemY());
	int gemInLine = gemsPhysics_->getGemsVector()->getGemInLine();

	std::vector<int> gemsToRepaint;
	ind = detPlaceOfHit(ind);
	if (ind == -1) {
		return;
	}
	gemsToRepaint.push_back(ind);

	std::vector<int> possTargets = BonusRadius(gemsToRepaint[0], actionRadius_);

	if (ind % gemInLine != 0) {
		possTargets.erase(std::remove(possTargets.begin(), possTargets.end(), ind - 1), possTargets.end());
	}
	if (ind % gemInLine != gemInLine - 1) {
		possTargets.erase(std::remove(possTargets.begin(), possTargets.end(), ind + 1), possTargets.end());
	}
	if (ind / gemInLine != 0) {
		possTargets.erase(std::remove(possTargets.begin(), possTargets.end(), ind - gemInLine), possTargets.end());
	}
	if (ind / gemInLine != gemInLine - 1) {
		possTargets.erase(std::remove(possTargets.begin(), possTargets.end(), ind + gemInLine), possTargets.end());
	}

	while (!possTargets.empty() && gemsToRepaint.size() < numberOfAffectedElem_) {
		int temp = possTargets[round(static_cast<double>(std::rand()) * (possTargets.size() - 1) / RAND_MAX)];
		if (!gemsPhysics_->isGemDestroyed(temp)) {
			gemsToRepaint.push_back(temp);
		}

		possTargets.erase(std::remove(possTargets.begin(), possTargets.end(), temp), possTargets.end());
	}
	gemsPhysics_->gemsRepaint(gemsToRepaint, gem->getGemColour());
}

void GemBonusBomb::activate(SimpleGem* gem) const {
	int ind = gemsPhysics_->getGemsVector()->getGemIndex(gem->getGemX(), gem->getGemY());

	std::vector<int> gemsToDelete;

	ind = detPlaceOfHit(ind);
	if (ind == -1) {
		return;
	}
	gemsToDelete.push_back(ind);

	std::vector<int> possTargets = BonusRadius(gemsToDelete[0], actionRadius_);

	while (!possTargets.empty() && gemsToDelete.size() < numberOfAffectedElem_) {
		int temp = possTargets[round(static_cast<double>(std::rand()) * (possTargets.size() - 1) / RAND_MAX)];
		if (!gemsPhysics_->isGemDestroyed(temp)) {
			gemsToDelete.push_back(temp);
	  }
		possTargets.erase(std::remove(possTargets.begin(), possTargets.end(), temp), possTargets.end());
	}
	gemsPhysics_->gemsDelete(gemsToDelete);
}

