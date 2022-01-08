// Copyright (c) 2022 The-Last-Cookie
// Licensed under the MIT Licence.
// See the LICENCE file for more information.

#pragma once

#include <iostream>

namespace StringCalc {
	class Number {
		public:
			Number(unsigned int base, std::string value);
			~Number();

			bool isZero();
			void removeLeadingZeros();

		private:
			bool isInBase(std::string str, unsigned int base);

			std::string m_value;
			unsigned int m_base;
	};
}
