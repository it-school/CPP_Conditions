#include <iostream>
#include <iomanip>

int main()
{
	std::cout << "Conditions" << std::endl;

	int a1 = 6 << 3;  // bit left  shift 6*2*2*2
	int b1 = 16 >> 3; // bit right shift 16 /2 /2 /2
	int c1 = 0;

	if (a1 == b1)
	{
		c1 = a1 + b1;
	}
	else
	{
		c1 = a1 - b1;
	}

	c1 = (a1 == b1 ? a1 + b1 : a1 - b1); // ternary operator instead of IF with ELSE

	std::cout << c1;


//	SWITCH example
	// 1..3		 4..6		7..9	 10..12
	// bad	 satisfactory	good	excellent

	int mark;
label_mark:
	std::cout << "\n\nInput mark in school (1..12): ";
	std::cin >> mark;

	switch (mark)
	{
	case 1:	case 2:	case 3:
		std::cout << "bad";
		break;
	case 4: case 5: case 6:
		std::cout << "satisfactory";
		break;
	case 7: case 8: case 9:
		std::cout << "good";
		break;
	case 10: case 11: case 12:
		std::cout << "excellent";
		break;
	default:
		std::cout << "Not a mark!";
		goto label_mark;
		break;
	}


// IF instead of SWITCH
mark_input:
	std::cout << "\n\nInput mark in school (1..12) one more time: ";
	std::cin >> mark;
	if (mark == 1 || mark == 2 || mark == 3)
		std::cout << "bad";
	else
		if (mark == 4 || mark == 5 || mark == 6)
			std::cout << "satisfactory";
		else
			if (mark == 7 || mark == 8 || mark == 9)
				std::cout << "good";
			else
				if (mark == 10 || mark == 11 || mark == 12)
					std::cout << "excellent";
				else {
					std::cout << "Not a mark!";
					goto mark_input;
				}


// where IF is better than SWITCH
	std::cout << "\n\nInput mark in university (1..100): ";
	std::cin >> mark;
	std::cout << "\n";

	if (mark > 0 && mark < 60)
		std::cout << "bad";
	else
		if (mark >= 60 && mark <= 74)
			std::cout << "satisfactory";	else
			if (mark >= 75 && mark < 90)
				std::cout << "good";	else
				if (mark >= 90 && mark <= 100)
					std::cout << "excellent";
				else
					std::cout << "Not a mark!";



// Quadratic equation with keyboard input correctness checking
	double x1, x2, a = 2, b = -3, c = 10, d;
	std::cout << "\n\nQuadratic equation solving with keybord coefficients input and control: ";
a1:
	std::cout << "\n Input A:";
	if (std::cin >> a)
	{
	b1:
		std::cout << "\n Input B:";
		if (std::cin >> b)
		{
		c1:
			std::cout << "\n Input C:";
			if (std::cin >> c)
			{
				d = pow(b, 2) - 4 * a * c;
				if (d < 0)
				{
					std::cout << "\nNo solutions";
				}
				else
				{
					if (d > 0)
					{
						x1 = (-b + sqrt(d)) / (2 * a);
						std::cout << "\nX1 = " << x1;
						x2 = (-b - sqrt(d)) / (2 * a);
						std::cout << "\nX2 = " << x2;
					}
					else
					{
						x1 = -b / (2 * a);
						std::cout << "\nX = " << x1;
					}
				}
			}
			else
			{
				std::cout << "Incorrect input for C";
				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(INT_MAX, '\n');
				}
				goto c1;
			}
		}
		else
		{
			std::cout << "Incorrect input for B";
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
			}
			goto b1;
		}
	}
	else
	{
		std::cout << "Incorrect input for A";
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
		}
		goto a1;
	}


	std::cout << "\n\nTime in seconds since 1.1.1970 using function time(0): " << time(0);
	srand(time(0)); // random nuber generator initialisation
	std::cout << "\nrand()%100 returns number in range [0..100): " << rand() * rand() % 100 << std::endl;


// Quadratic equation with random number generator use for variables
	const int MAX = 20;
	const int MIN = -20;
	std::cout << "\n\nQuadratic equation solving with coefficients input using random numbers generator: ";
label_equation:
	//	a = rand() % (abs(MAX) + abs(MIN)) - abs(MIN), b = rand() % (MAX * 2 + 1) - MAX, c = rand() % (MAX * 2 + 1) - MAX;
	a = rand() % (abs(MAX) + abs(MIN)) - abs(MIN);
	b = rand() % (MAX * 2 + 1) - MAX;
	c = rand() % (MAX * 2 + 1) - MAX;
	std::cout << std::endl << std::setw(10) << std::setprecision(3) << "A = " << a;	// printf("\nA = %10.3f", a);
	std::cout << std::endl << std::setw(10) << "B = " << b;							// printf("\nB = %10.3f", b);
	std::cout << std::endl << std::setw(10) << "C = " << c;							// printf("\nC = %10.3f", c);

	d = pow(b, 2) - 4 * a * c;
	if (d > 0)
	{
		x1 = (-b + sqrt(d)) / (2 * a);
		std::cout << "\nX1 = " << std::setprecision(5) << x1;
		x2 = (-b - sqrt(d)) / (2 * a);
		std::cout << "\nX2 = " << x2;
	}
	else {
		if (d < 0)
		{
			std::cout << "\nNo solutions";
			goto label_equation;
		}
		else
		{
			x1 = -b / (2 * a);
		}
	}


	std::cout << "\n\n\n";
	return 0;
}