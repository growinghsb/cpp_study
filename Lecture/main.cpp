#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Point
{
public:
	Point(int x, int y)
		: mX(x)
		, mY(y)
	{}

	~Point() = default;

	int getX() const
	{
		return mX;
	}

	int getY() const
	{
		return mY;
	}

private:
	int mX;
	int mY;
};

class Shape
{
public:
	Shape(Point p1, Point p2, Point p3 = { -1 , -1 }, Point p4 = { -1 , -1 })
		: matrix{}
	{
		memset(matrix, '*', MATRIX_SIZE * MATRIX_SIZE);

		mPoints.reserve(4);

		mPoints.push_back(p1);
		mPoints.push_back(p2);

		if (p3.getX() != -1)
		{
			mPoints.push_back(p3);

			if (p4.getX() != -1)
			{
				mPoints.push_back(p4);
			}
		}
	}

	virtual void printShape() = 0;
	virtual int getArea() = 0;

protected:
	void printMatrix()
	{
		for (int i = 0; i < MATRIX_SIZE; ++i)
		{
			cout << MATRIX_SIZE - (i + 1) << "\t";
			for (int j = 0; j < MATRIX_SIZE; ++j)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}

		cout << endl;
		cout << "\t";

		for (int i = 0; i < MATRIX_SIZE; ++i)
		{
			cout << i % 10 << " ";
		}

		cout << endl;
	}

	enum { MATRIX_SIZE = 24 };
	char matrix[MATRIX_SIZE][MATRIX_SIZE];

	vector<Point> mPoints;
};

class Line
	: public Shape
{
public:
	Line(Point p1, Point p2, Point p3 = { -1 , -1 }, Point p4 = { -1 , -1 })
		:Shape(p1, p2, p3, p4)
	{}

	void printShape() override
	{
		matrix[MATRIX_SIZE - mPoints[0].getY()][mPoints[0].getX()] = '#';
		matrix[MATRIX_SIZE - mPoints[1].getY()][mPoints[1].getX()] = '#';

		printMatrix();
	}

	int getArea() override
	{
		return sqrt(abs(mPoints[0].getX() - mPoints[1].getX()) + abs(mPoints[0].getY() - mPoints[1].getY()));
	}
};

class Triangle
	: public Shape
{
public:
	Triangle(Point p1, Point p2, Point p3 = { -1 , -1 }, Point p4 = { -1 , -1 })
		: Shape(p1, p2, p3, p4)
	{}

	void printShape() override
	{
		matrix[MATRIX_SIZE - mPoints[0].getY()][mPoints[0].getX()] = '#';
		matrix[MATRIX_SIZE - mPoints[1].getY()][mPoints[1].getX()] = '#';
		matrix[MATRIX_SIZE - mPoints[2].getY()][mPoints[2].getX()] = '#';
#
		printMatrix();
	}

	int getArea() override
	{
		int line1 = sqrt(abs(mPoints[0].getX() - mPoints[1].getX()) + abs(mPoints[0].getY() - mPoints[1].getY()));
		int line2 = sqrt(abs(mPoints[1].getX() - mPoints[2].getX()) + abs(mPoints[1].getY() - mPoints[2].getY()));
		int line3 = sqrt(abs(mPoints[2].getX() - mPoints[0].getX()) + abs(mPoints[2].getY() - mPoints[0].getY()));
		int s = (line1 + line2 + line3) / 2;

		return sqrt(s * ((s - line1) * (s - line2) * (s - line3)));
	}
};

class Ractangle
	: public Shape
{
public:
	Ractangle(Point p1, Point p2, Point p3 = { -1 , -1 }, Point p4 = { -1 , -1 })
		: Shape(p1, p2, p3, p4)
	{}

	void printShape() override
	{
		matrix[MATRIX_SIZE - mPoints[0].getY()][mPoints[0].getX()] = '#';
		matrix[MATRIX_SIZE - mPoints[1].getY()][mPoints[1].getX()] = '#';
		matrix[MATRIX_SIZE - mPoints[2].getY()][mPoints[2].getX()] = '#';
		matrix[MATRIX_SIZE - mPoints[3].getY()][mPoints[3].getX()] = '#';

		printMatrix();
	}

	int getArea() override
	{
		int line1 = sqrt(abs(mPoints[0].getX() - mPoints[1].getX()) + abs(mPoints[0].getY() - mPoints[1].getY()));
		int line2 = sqrt(abs(mPoints[1].getX() - mPoints[2].getX()) + abs(mPoints[1].getY() - mPoints[2].getY()));

		return (line1 * line2) * 2;
	}
};

int main()
{
	Point p1(3, 6);
	Point p2(1, 3);
	Point p3(2, 4);
	Point p4(4, 2);
	Point p5(8, 2);
	Point p6(4, 7);
	Point p7(8, 7);



	Line line(p1, p2);
	Triangle triangle(p2, p3, p4);
	Ractangle ractangle(p4, p5, p6, p7);

	cout << line.getArea() << endl;
	cout << triangle.getArea() << endl;
	cout << ractangle.getArea() << endl;

	cout << endl;

	// Shape* sLine = &line;
	/*Shape* sTriangle = &triangle;
	Shape* sRactangle = &ractangle*/;

	Shape* shapes[3] = { &line, &triangle, &ractangle };

	for (auto elem : shapes)
	{
		elem->printShape();
		cout << endl;
	}

	return 0;
}

