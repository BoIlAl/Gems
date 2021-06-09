#pragma once
#include "Gem.h"
class Painter {
public:
	void DrawField(std::vector<Gem*>, int);
	void DrawGem(Gem* gem);
};