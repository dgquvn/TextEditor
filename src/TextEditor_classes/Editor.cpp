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
#include "Editor.hpp"

/**
 * Constructor
 */
Editor::Editor(TextContent& file):
text{file}
{}

/**
 * Display the text content;
 */
void Editor::display(){
	// get the content
	const std::vector<std::string>& content = text.getContent();

	// output the text content
	for (int i = 0; i < content.size(); i++){
		std::cout << i << "\t" << content[i] << "\n";
	}
}

/**
 * procedure for adding a line
 */
void Editor::addLine(){
	// line index to be inserted
	int index;

	// new line to be inserted
	std::string line;
	std::cout << "Please enter the line index you want to insert the new line: ";
	std::cin >> index;

	// skip for negative input;
	if (index < 0){
		std::cout << "index has to be nonnegative\n";
		return;
	}
	std::cout << "\nPlease enter the content of the new line:\n";
	std::cin.ignore(256, '\n');
	std::getline(std::cin, line);

	// double check if the new line is intended to be empty
/*	if (line.empty()){
		std::cout << "There is no content for the new line\n";
		std::cout << "Are you sure you want to insert a empty line? : ";
		std::string answer;
		std::cin >> answer;
		std::transform(answer.begin(), answer.end(), answer.begin(), ::toupper);
		if (answer != "YES" || answer != "Y")
			return;
	}*/

	// add the line
	text.addLine(index, line);
}

/**
 * procedure for deleting a line
 */
void Editor::deleteLine(){
	// line index to be deleted
	int index;

	std::cout << "Please enter the line index you want to deleted: ";
	std::cin >> index;
	std::cout << "\n";

	if (index < 0 || index >= text.getContent().size()){
		std::cout << "incorrect index\n";
		return;
	}

	// delete the line
	text.deleteLine(index);
}

/**
 * procedure for replacing a line
 */
void Editor::replaceLine(){
	// line index to be replaced
	int index;
	// the new line to be put in
	std::string newLine;

	std::cout << "Please enter the line index you want to replace with: ";
	std::cin >> index;

	if (index < 0 || index >= text.getContent().size()){
		std::cout << "incorrect index\n";
		return;
	}

	std::cout << "Please enter the new line:\n";
	std::cin.ignore(256, '\n');
	std::getline(std::cin, newLine);

	// replace the line
	text.replaceLine(index, newLine);
}
/**
 * save content to the file
 */
void Editor::writeToFile(const std::string& file_loc){

	const std::vector<std::string>& content = text.getContent();
	std::ofstream file(file_loc);
	if (file.is_open()){

		// write the modified content to the file
		std::ostream_iterator<std::string> file_ite(file, "\n");
		std::copy(content.cbegin(), content.cend(), file_ite);

		file.close();
	}
	else
		throw "cannot find the file";

}



