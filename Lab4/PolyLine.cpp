#include <cstring>
#include <cmath>
#include "PolyLine.h"

namespace lab4
{
	PolyLine::PolyLine()
		: mCount(0)
	{	
			mArr = nullptr;
	}

	PolyLine::PolyLine(const PolyLine& other)
	{
		mCount = other.mCount;
		
		//아래와 같이 구현하면 같은 주소를 가리키기 때문에 사용X
		/*for (int i = 0; i < mCount; i++)
		{
			mArr[i] = other.mArr[i];
			mFlag[i] = other.mFlag[i];
		}*/

		delete[] mArr;
		mArr = new Point[mCount];

		for (int i = 0; i < mCount; i++)
		{
			mArr[i] = other.mArr[i];
		}
		
		//아래 작동안되는 코드
		/*delete[] mArr;
		mArr = new Point[mCount];
		memcpy(mArr, other.mArr, mCount);*/


	}

	PolyLine::~PolyLine()
	{
		delete[] mArr;
	}

	bool PolyLine::AddPoint(float x, float y)
	{
		if (mCount < 10)
		{
			Point* arr = new Point[mCount];

			for (int i = 0; i < mCount; i++)
			{
				arr[i] = mArr[i];
			}

			delete[] mArr;
			mArr = new Point[mCount + 1];

			for (int i = 0; i < mCount; i++)
			{
				mArr[i] = arr[i];
			}

			mArr[mCount].SetX(x);
			mArr[mCount].SetY(y);
			mCount += 1;
			delete[] arr;

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
			Point* arr = new Point[mCount];

			for (int i = 0; i < mCount; i++)
			{
				arr[i] = mArr[i];
			}

			delete[] mArr;
			mArr = new Point[mCount + 1];

			for (int i = 0; i < mCount; i++)
			{
				mArr[i] = arr[i];
			}

			mArr[mCount].SetX(x);
			mArr[mCount].SetY(y);
			mCount += 1;
			delete[] arr;

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

		Point* arr = new Point[mCount];

		for (int j = 0; j < mCount; j++)
		{
			arr[j] = mArr[j];
		}

		delete[] mArr;
		mCount -= 1;
		mArr = new Point[mCount];

		for (int j = 0; j < mCount; j++)
		{
			if (j >= i)
			{
				mArr[j] = arr[j + 1];
			}
			else
			{
				mArr[j] = arr[j];
			}
		}

		delete[] arr;

		return true;

	}

	bool PolyLine::TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const
	{
		if (mCount < 2)
		{
			return false;
		}

		float x = mArr[0].GetX();
		float y = mArr[0].GetY();

		float minx = mArr[0].GetX();
		float maxx = mArr[0].GetX();
		float miny = mArr[0].GetY();
		float maxy = mArr[0].GetY();

		for (int i = 0; i < mCount; i++)
		{
			x = mArr[i].GetX();
			y = mArr[i].GetY();

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
		if (mArr == nullptr || i >= 10 || mCount <= i)
		{
			return nullptr;
		}
		else
		{
			return new Point(mArr[i].GetX(), mArr[i].GetY());
		}
	}

	PolyLine& PolyLine::operator=(const PolyLine& other)
	{
		//대입연산자는 기존에 있던 메모리 삭제 넣을 것
		for (int i = 0; i < 10; i++)
		{
			delete[] mArr;
		}

		mCount = other.mCount;
		mArr = new Point[mCount];
		memcpy(mArr, other.mArr, mCount);


		return *this;
	}



}