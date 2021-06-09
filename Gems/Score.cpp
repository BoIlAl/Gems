#include "Score.h"

Score::Score(QWidget* parent, int endScore) : QPushButton(parent) {
	endScore_ = endScore;
	QString temp = QString::number(endScore);


	label_ = new QLabel("Your score is 0   : yo'll get " + temp + " more to win", this);
}


void Score::increaseScore(int score) {
	if (endFlag_ == true) {
		return;
	}

	score_ += score;

	if (score_ >= endScore_) {
		endFlag_ = true;
		label_->setText("Congratulations");
		return;
	}


	QString endScoreStr = QString::number(endScore_);
	QString currScoreStr = QString::number(score_);

	label_->setText("Your score is " + currScoreStr + " : yo'll get " + endScoreStr + " more to win");
}

bool Score::isScoreAchieved() {
	return endFlag_;
}

void Score::mousePressEvent(QMouseEvent * event) {
	if (event->button() == Qt::LeftButton) {
		scoreClicked();
	}
}

