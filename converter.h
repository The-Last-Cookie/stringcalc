// Copyright (c) 2021 The-Last-Cookie
// Licensed under the MIT Licence.
// See the LICENCE file for more information.

#pragma once

namespace StringCalc {

	class Converter {
		public:
			Converter();
			~Converter();
			void parse(std::string str, unsigned int base);
			std::string convertTo(unsigned int base);

		private:
			int currentBase;
			std::string value;
	};
}
