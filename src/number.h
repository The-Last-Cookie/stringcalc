// Copyright (c) 2022 The-Last-Cookie
// Licensed under the MIT Licence.
// See the LICENCE file for more information.

#pragma once

#include <iostream>

#include "stringcalc.h"
#include "helper.h"

namespace StringCalc {
	class Number {
		public:
			Number(unsigned int base, std::string value);
			~Number();

			bool isZero();
			void removeLeadingZeros();
			void addZeros(uint64 count);
			bool isValid();
			std::string getValue();

		private:
			bool isInBase(unsigned int base);

			std::string m_value;
			unsigned int m_base;
			bool m_isValid;
	};
}
