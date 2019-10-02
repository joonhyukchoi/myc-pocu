#pragma once
#include "eGrassType.h"

namespace lab5
{
	class Lawn
	{
		friend class RectangleLawn;
		friend class SquareLawn;
		friend class CircleLawn;
		friend class EquilateralTriangleLawn;
	public:
		Lawn();
		virtual ~Lawn();

		virtual unsigned int GetArea() const = 0;

		unsigned int GetGrassPrice(eGrassType grassType) const;
		unsigned int GetMinimumSodRollsCount() const;

	private:
		unsigned int mArea;
	};
} 