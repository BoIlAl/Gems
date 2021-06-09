#include "Gems.h"

Gems::Gems(QWidget *parent) : QMainWindow(parent)
{
    ui.setupUi(this);
		setFixedSize(c_fieldsize, c_fieldsize + c_scoreSize);

		gemsVect_ = new GemsVector(this, c_fieldsize, c_numOfGemInLine);

		gemsPhysics_ = new GemsPhysics(gemsVect_);
		gemBonusBomb_ = new GemBonusBomb(gemsPhysics_, c_dropRadiusBonusBomb, c_actionRadiusBonusBomb, c_numOfBonusBombAffectedElem);
		gemBonusRepaint_ = new GemBonusRepaint(gemsPhysics_, c_dropRadiusRepaintBonus, c_actionRadiusRepaintBonus, c_numOfBonusRepaintAffectedElem);
		score_ = new Score(this, c_scoreToWin);
		score_->setGeometry(0, c_fieldsize, c_fieldsize, c_scoreSize);
	
		gemsVect_->vectFill(gemBonusBomb_, gemBonusRepaint_, c_chanceOfBonusBombGem, c_chanceOfBonusRepaintGem, c_colours);

		std::vector<int> delGems = gemsPhysics_->checkComb(c_combinationSize);
		while (delGems.size() != 0) {
			gemsPhysics_->gemsDelete(delGems);
			gemsPhysics_->clearDelete();
			gemsPhysics_->fallOfGems();
			gemsVect_->vectFill(gemBonusBomb_, gemBonusRepaint_, c_chanceOfBonusBombGem, c_chanceOfBonusRepaintGem, c_colours);
			delGems = gemsPhysics_->checkComb(c_combinationSize);
		}

		gemsVect_->drawField();
}

void Gems::updateField(SimpleGem* gem) {
	if (!gemsPhysics_->processing—licks(gem)) {
		return;
	}

	std::vector<int> delGems = gemsPhysics_->checkComb(c_combinationSize);

	int temp = 0;
	while (delGems.size() != 0) {
		gemsPhysics_->gemsDelete(delGems);
		temp += 	gemsPhysics_->clearDelete();

		gemsPhysics_->fallOfGems();
		gemsVect_->vectFill(gemBonusBomb_, gemBonusRepaint_, c_chanceOfBonusBombGem, c_chanceOfBonusRepaintGem, c_colours);
		delGems = gemsPhysics_->checkComb(c_combinationSize);
	}

	gemsVect_->drawField();
	this->update();
	score_->increaseScore(temp);
	if (score_->isScoreAchieved()) {
		connect(score_, SIGNAL(scoreClicked()), this, SLOT(gameOver()));
	}
}


void Gems::gameOver() {
	for (int i = 0; i < gemsVect_->size(); i++) {
		(*gemsVect_)[i]->disconnect();
	}
	delete score_;
	delete gemsPhysics_;
	delete gemBonusBomb_;
	delete gemBonusRepaint_;
	delete gemsVect_;
	close();
}
