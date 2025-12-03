#pragma once
#include "Field.h"
#include "OscilloscopeMode.h"

class Display : public Field
{
public:
	enum class TYPE {
		WAVEFORM,
		VALUE,
		TEXT,
	};
	Display(Vei2 pos, int width, int height, Field::THEME theme, TYPE type);
	void Update(const Mouse& mouse, float dt) override;
	void Draw(Graphics& gfx) const override;
	void DrawGrid(Graphics& gfx) const;
	void SetGrid(bool effect);
private:
	TYPE type;
	bool grid = true;
};