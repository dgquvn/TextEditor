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
#include "Controller.hpp"

/**
 * Constructor
 */
Controller::Controller(const std::string& file_loc):
file{file_loc},
text(file),
viewer(text)
{}

/**
 * Engine for choose actions
 */
void Controller::start(){
	while(true){
		// save the choice from the input
		int choice = 6;
		std::cout << "Please choose one of the following options:\n";
		std::cout << "1. view the content\n";
		std::cout << "2. add a new line\n";
		std::cout << "3. delete a line\n";
		std::cout << "4. replace a line\n";
		std::cout << "5. save the file\n";
		std::cout << "6. exit\n";

		std::cin >> choice;

		std::cout << "choice: " << choice << "\n";

		if (choice == 1)
			viewer.display();
		else if (choice == 2)
			viewer.addLine();
		else if (choice == 3)
			viewer.deleteLine();
		else if (choice == 4)
			viewer.replaceLine();
		else if (choice == 5)
			viewer.writeToFile(file);
		else if (choice == 6)
			break;
		else
			std::cout << "Invalid input, please choose from 1-5\n";
	}
}



