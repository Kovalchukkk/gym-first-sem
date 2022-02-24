#pragma once
class VisualComponent
{
public:
	virtual void Draw() = 0;
	virtual void SetColor(int& temp) = 0;
};