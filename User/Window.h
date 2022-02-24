#pragma once
#include "VisualComponent.h"
class Window
{
public:
	void Draw(VisualComponent* visualComponent)
	{
		visualComponent->Draw();
	}
	void SetColor(VisualComponent* visualComponent, int num)
	{
		visualComponent->SetColor(num);
	}
};