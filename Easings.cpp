#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif

#include <cmath>

#include "Easings.h"

namespace Easings
{
	namespace Sine
	{
		float In(float t)
		{
			return sin(M_PI_2 * t);
		}

		float Out(float t)
		{
			return 1.0f + sin(M_PI_2 * (--t));
		}

		float InOut(float t)
		{
			return 0.5f * (1.0f + sin(M_PI * (t - 0.5f)));
		}
	}

	namespace Quad
	{
		float In(float t)
		{
			return t * t;
		}

		float Out(float t)
		{
			return t * (2.0f - t);
		}

		float InOut(float t)
		{
			if (t < 0.5f)
			{
				return 2.0f * t * t;
			}
			else
			{
				return t * (4.0f - 2.0f * t) - 1.0f;
			}
		}
	}

	namespace Cubic
	{
		float In(float t)
		{
			return t * t * t;
		}

		float Out(float t)
		{
			return 1.0f + (--t) * t * t;
		}

		float InOut(float t)
		{
			if (t < 0.5f)
			{
				return 4.0f * t * t * t;
			}
			else
			{
				1.0f + (--t) * (2.0f * (--t)) * (2.0f * t);
			}
		}
	}

	namespace Quart
	{
		float In(float t)
		{
			t *= t;
			return t * t;
		}

		float Out(float t)
		{
			t = (--t) * t;
			return 1.0f - t * t;
		}

		float InOut(float t)
		{
			if (t < 0.5f)
			{
				t *= t;
				return 8.0f * t * t;
			}
			else
			{
				t = (--t) * t;
				return 1.0f - 8.0f * t * t;
			}
		}
	}

	namespace Quint
	{
		float In(float t)
		{
			float t2 = t * t;
			return t * t2 * t2;
		}

		float Out(float t)
		{
			float t2 = (--t) * t;
			return 1 + t * t2 * t2;
		}

		float InOut(float t)
		{
			float t2;
			if (t < 0.5f)
			{
				t2 = t * t;
				return 16.0f * t * t2 * t2;
			}
			else
			{
				t2 = (--t) * t;
				return 1.0f + 16.0f * t * t2 * t2;
			}
		}
	}

	namespace Expo
	{
		float In(float t)
		{
			return (pow(2.0f, 8.0f * t) - 1.0f) / 255.0f;
		}

		float Out(float t)
		{
			return 1.0f - pow(2.0f, -8.0f * t);
		}

		float InOut(float t)
		{
			if (t < 0.5f)
			{
				return (pow(2.0f, 16.0f * t) - 1) / 510.0f;
			}
			else
			{
				return 1.0f - 0.5f * pow(2, -16.0f * (t - 0.5f));
			}
		}
	}

	namespace Circ
	{
		float In(float t)
		{
			return 1.0f - sqrt(1.0f - t);
		}

		float Out(float t)
		{
			return sqrt(t);
		}

		float InOut(float t)
		{
			if (t < 0.5f)
			{
				return (1.0f - sqrt(1.0f - 2.0f * t)) * 0.5f;
			}
			else
			{
				return (1.0f + sqrt(2.0f * t - 1.0f)) * 0.5f;
			}
		}
	}

	namespace Back
	{
		float In(float t)
		{
			return t * t * (2.70158f * t - 1.70158f);
		}

		float Out(float t)
		{
			return 1.0f + (--t) * t * (2.70158f * t + 1.70158f);
		}

		float InOut(float t)
		{
			if (t < 0.5f)
			{
				return t * t * (7.0f * t - 2.5f) * 2.0f;
			}
			else
			{
				return 1.0f + (--t) * t * 2.0f * (7.0f * t + 2.5f);
			}
		}
	}

	namespace Elastic
	{
		float In(float t)
		{
			float t2 = t * t;
			return t2 * t2 * sin(t * M_PI * 4.5f);
		}

		float Out(float t)
		{
			float t2 = (t - 1.0f) * (t - 1.0f);
			return 1.0f - t2 * t2 * cos(t * M_PI * 4.5f);
		}

		float InOut(float t)
		{
			float t2;
			if (t < 0.45f)
			{
				t2 = t * t;
				return 8.0f * t2 * t2 * sin(t * M_PI * 9.0f);
			}
			else if (t < 0.55f)
			{
				return 0.5f + 0.75f * sin(t * M_PI * 4.0f);
			}
			else
			{
				t2 = (t - 1.0f) * (t - 1.0f);
				return 1.0f - 8.0f * t2 * t2 * sin(t * M_PI * 9.0f);
			}
		}
	}

	namespace Bounce
	{
		float In(float t)
		{
			return pow(2.0f, 6.0f * (t - 1.0f)) * abs(sin(t * M_PI * 3.5f));
		}

		float Out(float t)
		{
			return 1.0f - pow(2.0f, -6.0f * t) * abs(cos(t * M_PI * 3.5f));
		}

		float InOut(float t)
		{
			if (t < 0.5f)
			{
				return 8.0f * pow(2.0f, 8.0f * (t - 1.0f)) * abs(sin(t * M_PI * 7.0f));
			}
			else
			{
				return 1.0f - 8.0f * pow(2.0f, -8.0f * t) * abs(sin(t * M_PI * 7.0f));
			}
		}
	}
}