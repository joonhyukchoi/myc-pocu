#include <cstring>
#include <cmath>
#include "PolyLine.h"

namespace lab4
{
	PolyLine::PolyLine()
		: mCount(0)
	{
		for (int i = 0; i < 10; i++)
		{
			mArr[i] = nullptr;
		}
	}

	PolyLine::PolyLine(const PolyLine& other)
	{
		mCount = other.mCount;
		
		//�Ʒ��� ���� �����ϸ� ���� �ּҸ� ����Ű�� ������ ���X
		/*for (int i = 0; i < mCount; i++)
		{
			mArr[i] = other.mArr[i];
			mFlag[i] = other.mFlag[i];
		}*/
		for (int i = 0; i < mCount; i++)
		{
			mArr[i] = new Point(*other.mArr[i]);
		}

		// �Ʒ��� ���� �������� ������ ��������� ����
		for (int i = mCount; i < 10; i++)
		{
			mArr[i] = nullptr;
		}

	}

	PolyLine::~PolyLine()
	{
		//delete[] mArr �ϸ� ���� �߻�
		for (int i = 0; i < 10; i++)
		{
			delete mArr[i];
		}
	}

	bool PolyLine::AddPoint(float x, float y)
	{
		if (mCount < 10)
		{
			mArr[mCount] = new Point(x, y);
			mCount += 1;
			return true;
		}
		else
		{
			return false;
		}
	}

	bool PolyLine::AddPoint(const Point* point)
	{
		if (point == nullptr)
		{
			return false;
		}

		float x = point->GetX();
		float y = point->GetY();

		if (mCount < 10)
		{
			mArr[mCount] = new Point(x, y);
			mCount += 1;
			return true;
		}
		else
		{
			return false;
		}
	}

	//bool PolyLine::AddPoint(const Point point)
	//{
	//	float x = point.GetX();
	//	float y = point.GetY();

	//	if (mCount <= 10)
	//	{
	//		mArr[mCount] = new Point(x, y);
	//		mCount += mCount;
	//		return true;
	//	}
	//	else
	//	{
	//		return false;
	//	}
	//}

	bool PolyLine::RemovePoint(unsigned int i)
	{
		if (i >= mCount || i < 0)
		{
			return false;
		}

		for (int j = i; j < mCount - 1; j++)
		{
			delete mArr[j];
			mArr[j] = new Point(*mArr[j + 1]);
		}

		delete mArr[mCount - 1];
		mArr[mCount - 1] = nullptr;
		mCount -= 1;
		
		return true;

	}

	bool PolyLine::TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const
	{
		if (mCount < 2)
		{
			return false;
		}

		float x = mArr[0]->GetX();
		float y = mArr[0]->GetY();

		float minx = mArr[0]->GetX();
		float maxx = mArr[0]->GetX();
		float miny = mArr[0]->GetY();
		float maxy = mArr[0]->GetY();

		for (int i = 0; i < mCount; i++)
		{
			x = mArr[i]->GetX();
			y = mArr[i]->GetY();

			if (minx > x)
			{
				minx = x;
			}

			if (maxx < x)
			{
				maxx = x;
			}

			if (miny > y)
			{
				miny = y;
			}

			if (maxy < y)
			{
				maxy = y;
			}
		}

		outMin->SetX(minx);
		outMax->SetX(maxx);
		outMin->SetY(miny);
		outMax->SetY(maxy);

		return true;
	}

	const Point* PolyLine::operator[](unsigned int i) const
	{
		if (mArr[i] == nullptr || i >= 10)
		{
			return nullptr;
		}
		else
		{
			return new Point(mArr[i]->GetX(), mArr[i]->GetY());
		}
	}

	PolyLine& PolyLine::operator=(const PolyLine& other)
	{
		//���Կ����ڴ� ������ �ִ� �޸� ���� ���� ��
		for (int i = 0; i < 10; i++)
		{
			delete mArr[i];
		}

		mCount = other.mCount;

		for (int i = 0; i < 10; i++)
		{
			mArr[i] = new Point(*other.mArr[i]);
		}

		// �Ʒ��� ���� �������� ������ ��������� ����
		for (int i = mCount; i < 10; i++)
		{
			mArr[i] = nullptr;
		}

		return *this;
	}



}