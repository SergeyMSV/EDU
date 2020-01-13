#include <ratio>

int UnitTest_Ratio()
{
	std::ratio<36, 10> Ratio_km_h_To_ms;
	
	int Speed_ms = 10;

	int Speed_km_h = (Speed_ms * Ratio_km_h_To_ms.num) / Ratio_km_h_To_ms.den;

	return 0;
}