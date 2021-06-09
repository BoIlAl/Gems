#include "Painter.h"

void Painter::DrawField(std::vector<Gem*> array, int size){
	for (int i = 0; i < size; ++i) {
		DrawGem(array[i]);
	}
}

void Painter::DrawGem(Gem* gem) {
	gem->setGeometry(gem->getGemX(), gem->getGemY(), gem->getGemSize(), gem->getGemSize());
	gem->setStyleSheet("background-color: " + gem->gemColour_);
	gem->setVisible(true);
}
