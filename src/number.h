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
			void addZeros(uint64 count);
			bool isValid();
			
			std::string value;
			unsigned int base;

		private:
			bool isInBase(unsigned int base);

			bool m_isValid;
	};
}
