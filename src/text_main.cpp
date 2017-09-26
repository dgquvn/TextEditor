/**----------------------------------------------------------------------------
 Copyright (c) 2015-, UT-Battelle, LLC
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

 * Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.

 * Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.

 * Neither the name of fern nor the names of its
 contributors may be used to endorse or promote products derived from
 this software without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 Author(s): Guoqiang Deng (dgquvn <at> gmail <dot> com)
 -----------------------------------------------------------------------------*/

#include <iostream>
#include <boost/program_options.hpp>
#include <string>
#include "Controller.hpp"

using namespace boost::program_options;

/**
 * This is the program for simple text editing,
 * including adding a line to a specific location,
 * and deleting a specific line
 */
int main(int argc, const char *argv[]){
	try{
		// file_loc, storing the text file location for editing
		std::string file_loc;

		/**
		 * generalOpt, storing the parsed arguments
		 */
		options_description generalOpt{"General"};
		generalOpt.add_options()
				("help,h", "Help Screen")
				("file,f", value<std::string>(&file_loc), "Text file location");

		variables_map mp;

		// parse arguments to generalOpt and store them to mp;
		store(parse_command_line(argc, argv, generalOpt), mp);
		notify(mp);

		if (mp.count("help"))
			std::cout << generalOpt << "\n";
		else if (file_loc.empty())
			std::cout << "file location missing\n";
		else{
			// start editing the file
			Controller app(file_loc);
			app.start();
		}
	}
	catch(const char* exp){
		// output exception
		std::cerr << exp << "\n";
		std::cout << "enter --help for input options\n";
	}

	return 0;
}


